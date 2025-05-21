#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/*!
    \file
    \brief Header file for mainwindow.cpp.

*/
#include <QMainWindow>
#include <QSerialPort>
#include "breakout.h"
#include "breakout_medium.h"
#include "wykresy.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Arkanoid32;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void readFromPort();

    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_3_currentIndexChanged(int index);

    void on_comboBox_2_currentIndexChanged(int index);

private:
    QTranslator *Tlumacz;
    virtual void changeEvent(QEvent *event) override;
    void changeLanguage(QString lng);
    QSerialPort *device;
    Ui::Arkanoid32 *ui;
    Breakout *window;
    Breakout_M *window_M;
    Wykresy *charts;

    int chartX[50];
    int chartY[50];
    int chartZ[50];

    void addToLogs(const QString &message);
/*!
    \brief This function calculates CRC16.

*/
    unsigned short int ComputeCRC16(const char* pData, int Length, unsigned int Poly, unsigned short int InitVal)
    {
        short int i;
        unsigned short int ResCRC = InitVal;

        while (--Length >= 0) {
            ResCRC ^= *pData++ << 8;
            for (short int i=0; i < 8; ++i)
                ResCRC = ResCRC & 0x8000 ? (ResCRC << 1) ^ Poly : ResCRC << 1;
        }
        return ResCRC & 0xFFFF;
    }

};
#endif // MAINWINDOW_H
