#include "mainwindow.h"
#include "breakout.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // QTranslator Tlumacz;
    // if(Tlumacz.load("C:/Users/Anton/Documents/untitled/untitled_pl_PL.qm")){
    //     a.installTranslator(&Tlumacz);
    // } else {
    //     qDebug() << "error";
    // }
    MainWindow w;
    w.show();

    return a.exec();
}
