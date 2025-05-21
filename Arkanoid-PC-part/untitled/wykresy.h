#ifndef WYKRESY_H
#define WYKRESY_H
/*!
    \file
    \brief Header file for Wykresy.cpp.

*/
#include <QMainWindow>
#include <QPainter>
#include <QResizeEvent>
#include <QtCharts>

namespace Ui {
class Wykresy;
}

class Wykresy : public QMainWindow
{
    Q_OBJECT

public:
    explicit Wykresy(QWidget *parent = nullptr);
    ~Wykresy();
    void set_dane(QString CoZaWykres, int *dane);
    void set_XYZWykres(QString CoZaWykres);
    void changeLang(int index);
    void changeEvent(QEvent *event);

protected:
    void resizeEvent(QResizeEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_comboBox_textActivated(const QString &arg1);

    void rysuj();

    //void on_comboBox_2_activated(int index);

private:
    Ui::Wykresy *ui;
    QLineSeries *lineSeriesX;
    QLineSeries *lineSeriesY;
    QLineSeries *lineSeriesZ;
    QChart *chart;
    QChartView *chartView;
    QString XYZWykres;
    int daneX[50];
    int daneY[50];
    int daneZ[50];
};

#endif // WYKRESY_H
