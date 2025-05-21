#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "breakout.h"
#include "breakout_medium.h"
#include <QDebug>
#include <QList>
#include <QSerialPortInfo>
#include <QDateTime>
#include "SharedData.h"

#define CRC16_INIT        0
#define CRC16_POLYNOMIAL  0x8005

/*!
    \file
    \brief This file is responsible for creating mainwindow.

*/
/*!
    \brief This is a constructor method for the Arkanoid32 class.

    It create an object of the QSerialPort class, which will be deleted from memory automatically before we close the window.
    \code
    this->device = new QSerialPort(this);
    \endcode

*/
MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::Arkanoid32)
{
    this->device = new QSerialPort(this);
    ui->setupUi(this);
    charts = new Wykresy;
    charts -> set_XYZWykres("chartX");
    for (int i = 0; i < 50; ++i){
        chartX[i] = 0;
        chartY[i] = 0;
        chartZ[i] = 0;
    }
    Tlumacz = new QTranslator;
    //setWindowTitle("Arkanoid32");
}

/*!
    \brief This is a destructor method for the MainWindow class.
*/
MainWindow::~MainWindow()
{
    delete ui;
}

/*!
    \brief This method is called after clicking on the "Search" button in the main window.

    It allows to see available connected devices and the port through which they are connected.
*/

int x_acc, y_acc, z_acc, sumdata;
void MainWindow::on_pushButton_3_clicked()
{
    //qDebug() << "Searching for port...";

    QList<QSerialPortInfo> devices;
    devices = QSerialPortInfo::availablePorts();

    for(int i = 0; i < devices.count(); i++) {
        this->addToLogs("Device found: " + devices.at(i).portName() + " " + devices.at(i).description());
        ui->comboBox->addItem(devices.at(i).portName() + "\t" + devices.at(i).description());
    }
}

/*!
    \brief This method is called after clicking on the "Connect" button in the main window.

    It allows to establish a connection between the computer and the connected device, including reading and writing data, port configuration, and it also shows if the port is open or not.
*/
void MainWindow::on_pushButton_4_clicked()
{
    if(ui->comboBox->count() == 0) {
        this->addToLogs("No devices avaliable");
        return;
    }

    QString portName = ui->comboBox->currentText().split("\t").first();
    this->device->setPortName(portName);

    //if(!device->isOpen()) {
        if(device->open(QSerialPort::ReadWrite)) {
            this->device->setBaudRate(QSerialPort::Baud115200);
            this->device->setDataBits(QSerialPort::Data8);
            this->device->setParity(QSerialPort::NoParity);
            this->device->setStopBits(QSerialPort::OneStop);
            this->device->setFlowControl(QSerialPort::NoFlowControl);

            connect(this->device, SIGNAL(readyRead()), this, SLOT(readFromPort()));

            this->addToLogs("Port opened");
        } else {
            this->addToLogs("Cant open port");
        }
    // } else {
    //     this->addToLogs("Port already opened");
    //     return;
    // }
}

/*!
    \brief This method adds all events to the Logs section.

    It uses the "currentDateTime()" method to get information about the date and time at the moment. As a parameter function takes string line, which will be showed.
    \param[in]  message
*/
void MainWindow::addToLogs(const QString &message)
{
    QString currentDateTime = QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss");
    ui->textEdit->append(currentDateTime + " -> " + message);
}

/*!
    \brief This method is responsible for data transmission.

    It checks if CRC16 is ok, if there is a "start" symbol, and transmits only correct data. Additionally, it directs data from the accelerometer to the X, Y, Z log sections inside the main window.
*/
void MainWindow::readFromPort()
{
    while(this->device->canReadLine()) {
        QString line = this->device->readLine();
        //qDebug() << line;


        // qDebug() << line.left(pos);

        // this->addToLogs(line.left(pos));


        QTextStream ss(&line);
        char ch;
        int z_acc, sumdata;
        int xsize = 0, ysize = 0, zsize = 0;
        ss >> ch >> SharedData::getInstance().x_acc >> SharedData::getInstance().y_acc >> z_acc >> sumdata;
        //qDebug() << ch << SharedData::getInstance().x_acc << y_acc << z_acc << sumdata;
        if(SharedData::getInstance().x_acc < 0){
            ++xsize;
        }

        for (int i = abs(SharedData::getInstance().x_acc); i > 0; i /= 10){
            ++xsize;
        }

        if(y_acc < 0){
            ++ysize;
        }

        for (int i = abs(SharedData::getInstance().y_acc); i > 0; i /= 10){
            ++ysize;
        }

        if(z_acc < 0){
            ++zsize;
        }

        for (int i = abs(z_acc); i > 0; i /= 10){
            ++zsize;
        }
        int datasize = xsize + ysize + zsize + 4;
        char data[datasize];
        sprintf(data, "D %d %d %d", SharedData::getInstance().x_acc, SharedData::getInstance().y_acc, z_acc);
        int sumCRC16 = ComputeCRC16(data, datasize, CRC16_POLYNOMIAL, CRC16_INIT);
        //qDebug() << sumdata;
        //qDebug() << sumCRC16;

        if(ch == 'D' && sumCRC16 == sumdata){
            QString terminator = "\r";
            int pos = line.lastIndexOf(terminator);
            this->addToLogs(line.left(pos));
            //this->addToLogs(line);
            ui->lineEdit->setText(QString::number(SharedData::getInstance().x_acc));
            ui->lineEdit->setAlignment(Qt::AlignRight);
            ui->lineEdit_2->setText(QString::number(SharedData::getInstance().y_acc));
            ui->lineEdit_2->setAlignment(Qt::AlignRight);
            ui->lineEdit_3->setText(QString::number(z_acc));
            ui->lineEdit_3->setAlignment(Qt::AlignRight);

            for(int i; i < 49; ++i){
                chartX[i] = chartX[i + 1];
                chartY[i] = chartY[i + 1];
                chartZ[i] = chartZ[i + 1];
            }
            chartX[49] = SharedData::getInstance().x_acc;
            chartY[49] = SharedData::getInstance().y_acc;
            chartZ[49] = z_acc;

            charts -> set_dane("chartX", chartX);
            charts -> set_dane("chartY", chartY);
            charts -> set_dane("chartZ", chartZ);
        }
    }
}

/*!
    \brief This method is called after clicking on the "Disconnect" button.

    It adds information about the status of the connection to the logs.
*/
void MainWindow::on_pushButton_5_clicked()
{
    if(this->device->isOpen()) {
        this->device->close();
        this->addToLogs("Connection closed");
    } else {
        this->addToLogs("Port isnt open");
        return;
    }
}

/*!
    \brief This method is used for changing game difficulty.

    At the moment this function doesn't work.
*/

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    switch(index){
    case 0:
        //window = new Breakout();
        // window -> resize(300, 400);
        // window -> setWindowTitle("Breakout");
        // window->setStyleSheet("background-color: rgb(133, 170, 255);");
        //window -> show();
        break;

    case 1:
        // if(appTranslator -> load("C:/Users/Anton/Documents/untitled/untitled_pl_PL.qm")){
        //     qApp -> installTranslator(appTranslator);
        // }
        break;

    case 2:
        // if(appTranslator -> load("C:/Users/Anton/Documents/untitled/untitled_ru_UA.qm")){
        //     qApp -> installTranslator(appTranslator);
        // }
        break;
    }
}

/*!
    \brief This method is used for the "Play" button.

    After clicking this button, a window with a game appears.
*/
void MainWindow::on_pushButton_clicked()
{
    //x_acc++;
    //hide();
    window = new Breakout();
    window -> resize(300, 400);
    window -> setWindowTitle("Breakout");
    window->setStyleSheet("background-color: rgb(133, 170, 255);");
    window -> show();
    // window_M = new Breakout_M();
    // window_M -> resize(300, 400);
    // window_M -> setWindowTitle("Breakout");
    // window_M -> setStyleSheet("background-color: rgb(133, 170, 255);");
    // window_M -> show();

}

/*!
    \brief This method is used for turning on "Chats" window.

    After clicking this button window appears.
*/

void MainWindow::on_pushButton_6_clicked()
{
    charts -> show();
}

/*!
    \brief This method is used for closing all windows after clicking on "Exit" button.
*/

void MainWindow::on_pushButton_2_clicked()
{
    if(window -> isVisible()){
        window -> close();
    }

    if(charts -> isVisible()){
        charts -> close();
    }

    close();
}



void MainWindow::changeEvent(QEvent *event){
    if(event -> type() == QEvent::LanguageChange){
        ui -> retranslateUi(this);
        return;
    }
    QMainWindow::changeEvent(event);
}

// void MainWindow::changeLanguage(QString lng){
//     if(lng == "pl"){
//         if(Tlumacz -> load("C:/Users/Anton/Documents/untitled/untitled_pl_PL.qm")){
//             qApp -> installTranslator(Tlumacz);
//         } else {
//             qDebug() << "error";
//         }
//     }
// }

/*!
    \brief This method is used for changing language of application i main window.

    It takes an index of choosen button in combo box and translates to the choosen language.
    \param[in] index index of chosen option
*/

void MainWindow::on_comboBox_3_currentIndexChanged(int index)
{
    static QTranslator *appTranslator = new QTranslator();

    charts -> changeLang(index);
    switch(index){
        case 0:
            qApp -> removeTranslator(appTranslator);
        break;

        case 1:
            if(appTranslator -> load("C:/Users/Anton/Documents/untitled/untitled_pl_PL.qm")){
                qApp -> installTranslator(appTranslator);
            }
        break;

        case 2:
            if(appTranslator -> load("C:/Users/Anton/Documents/untitled/untitled_ru_UA.qm")){
                qApp -> installTranslator(appTranslator);
            }
        break;
    }
}




