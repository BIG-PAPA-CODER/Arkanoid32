#include "wykresy.h"
#include "ui_wykresy.h"
/*!
    \file
    \brief This file is responsible for creating window with charts from accelerometr data.

    It contains methods that help to create charts.
*/

/*!
    \brief Construktor for a Wykresy object.
*/

Wykresy::Wykresy(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Wykresy)
{
    ui->setupUi(this);

    lineSeriesX = new QLineSeries();
    lineSeriesY = new QLineSeries();
    lineSeriesZ = new QLineSeries();
    chart = new QChart();
    chartView = new QChartView(this);

    chart->legend()->hide();
    chart->addSeries(lineSeriesX);
    lineSeriesX->setColor(QColor(140, 0, 0));
    chart->addSeries(lineSeriesY);
    lineSeriesY->setColor(QColor(0, 140, 0));
    chart->addSeries(lineSeriesZ);
    lineSeriesZ->setColor(QColor(0, 0, 140));
    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).first()->setRange(-32000, 32000);
    //ui->comboBox_2->setCurrentIndex(1);
    chart->axes(Qt::Horizontal).first()->setRange(0, 50);
    chart->setBackgroundBrush(QColor(24, 77, 147));
    chart->setBackgroundPen(QColor(255, 255, 255));
    //chart->setTitleBrush(QBrush(Qt::white));
    chart->setVisible(true);

    chartView->setChart(chart);
    chartView->setFixedSize(800, 500);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setVisible(true);

    setWindowTitle(QStringLiteral("Charts"));
}

/*!
    \brief Destruktor for a Wykresy object.
*/

Wykresy::~Wykresy()
{
    delete ui;
}

/*!
    \brief This method helps to choose which chart will be shown.
    \param [in] which
*/

void Wykresy::set_XYZWykres(QString which)
{
    XYZWykres = which;
    if (which == "chartX") {
        ui->comboBox->setCurrentIndex(0);
    }
    if (which == "chartY") {
        ui->comboBox->setCurrentIndex(1);
    }
    if (which == "chartZ") {
        ui->comboBox->setCurrentIndex(2);
    }
    if (which == "chartXYZ") {
        ui->comboBox->setCurrentIndex(3);
    }
}

/*!
    \brief This method helps to send data from accelerometr to charts.
    \param [in] which
    \param [in] dane
*/

void Wykresy::set_dane(QString which, int *dane)
{
    if (which == "chartX") {
        for (int i = 0; i < 50; i++) {
            daneX[i] = dane[i];
        }
    }
    if (which == "chartY") {
        for (int i = 0; i < 50; i++) {
            daneY[i] = dane[i];
        }
    }
    if (which == "chartZ") {
        for (int i = 0; i < 50; i++) {
            daneZ[i] = dane[i];
        }
    }
    rysuj();
}

/*!
    \brief This method helps to draw charts.
*/

void Wykresy::rysuj()
{
    lineSeriesX->clear();
    lineSeriesY->clear();
    lineSeriesZ->clear();

    if (XYZWykres == "chartX" || XYZWykres == "chartXYZ") {
        for (int i = 0; i < 50; i++) {
            lineSeriesX->append(i, daneX[i]);
        }
    }
    if (XYZWykres == "chartY" || XYZWykres == "chartXYZ") {
        for (int i = 0; i < 50; i++) {
            lineSeriesY->append(i, daneY[i]);
        }
    }
    if (XYZWykres == "chartZ" || XYZWykres == "chartXYZ") {
        for (int i = 0; i < 50; i++) {
            lineSeriesZ->append(i, daneZ[i]);
        }
    }
}

/*!
    \brief This method allows to resize window with charts.
    \param [in] event
*/

void Wykresy::resizeEvent(QResizeEvent *event)
{
    QSize windowSize = size();
    chartView->setFixedSize(windowSize.width(), windowSize.height() - 50);
}

/*!
    \brief This method allows to close charts window.
*/

void Wykresy::on_pushButton_clicked()
{
    close();
}

void Wykresy::on_comboBox_textActivated(const QString &arg1)
{
    XYZWykres = arg1;
}

void Wykresy::changeEvent(QEvent *event){
    if(event -> type() == QEvent::LanguageChange){
        ui -> retranslateUi(this);
        return;
    }
    QMainWindow::changeEvent(event);
}

/*!
    \brief This method allows to change language of charts window.
    \param [in] index choosen option in combo box
*/

void Wykresy::changeLang(int index)
{
    static QTranslator *appTranslator = new QTranslator();

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
// void Wykresy::on_comboBox_2_activated(int index)
// {
//     if (index == 0){
//         chart->axes(Qt::Vertical).first()->setRange(-16000, 16000);
//     } else if (index == 1){
//         chart->axes(Qt::Vertical).first()->setRange(-32000, 32000);
//     }
// }
