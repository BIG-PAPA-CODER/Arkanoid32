/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Arkanoid32
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_3;
    QComboBox *comboBox;
    QGroupBox *groupBox_2;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QPushButton *pushButton_2;
    QLabel *label;
    QGroupBox *groupBox_3;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Arkanoid32)
    {
        if (Arkanoid32->objectName().isEmpty())
            Arkanoid32->setObjectName("Arkanoid32");
        Arkanoid32->resize(800, 600);
        Arkanoid32->setAutoFillBackground(false);
        Arkanoid32->setStyleSheet(QString::fromUtf8("border-color: rgb(153, 32, 118);"));
        centralwidget = new QWidget(Arkanoid32);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 15, 34);"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 140, 271, 97));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(24, 77, 147, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(255, 255, 255, 128));
        brush2.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush2);
#endif
        groupBox->setPalette(palette);
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 77, 147);\n"
"color: rgb(255, 255, 255);"));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(12, 31, 79, 24));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 41, 113);\n"
"color: rgb(255, 255, 255)"));
        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(97, 31, 78, 24));
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 41, 113);\n"
"color: rgb(255, 255, 255)"));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(181, 31, 78, 24));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 41, 113);\n"
"color: rgb(255, 255, 255)"));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(12, 61, 251, 24));
        comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 41, 113);\n"
"color: rgb(255, 255, 255)"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(480, 140, 281, 261));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 77, 147);\n"
"color: rgb(255, 255, 255);"));
        textEdit = new QTextEdit(groupBox_2);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(10, 20, 261, 231));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(300, 140, 161, 51));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush3(QColor(0, 41, 113, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush2);
#endif
        pushButton->setPalette(palette1);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 41, 113);\n"
"color: rgb(255, 255, 255);"));
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(300, 220, 161, 51));
        comboBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 41, 113);\n"
"color: rgb(255, 255, 255)"));
        comboBox_3 = new QComboBox(centralwidget);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(300, 300, 161, 51));
        comboBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 41, 113);\n"
"color: rgb(255, 255, 255)"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(300, 380, 161, 51));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 41, 113);\n"
"color: rgb(255, 255, 255)"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(300, 80, 171, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Modern")});
        font.setPointSize(28);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:1, stop:0 rgba(153, 32, 118, 0), stop:1 rgba(255, 255, 255, 255));"));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(10, 250, 271, 151));
        groupBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 77, 147);\n"
"color: rgb(255, 255, 255);"));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 20, 31, 41));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8(""));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 60, 31, 41));
        label_3->setFont(font);
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 100, 31, 41));
        label_4->setFont(font);
        lineEdit = new QLineEdit(groupBox_3);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(40, 30, 113, 24));
        lineEdit->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lineEdit_2 = new QLineEdit(groupBox_3);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(40, 70, 113, 24));
        lineEdit_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lineEdit_3 = new QLineEdit(groupBox_3);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(40, 110, 113, 24));
        lineEdit_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_6 = new QPushButton(groupBox_3);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(170, 70, 80, 24));
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 41, 113);\n"
"color: rgb(255, 255, 255)"));
        Arkanoid32->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Arkanoid32);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menubar->setStyleSheet(QString::fromUtf8("background-color: rgb(178, 134, 255);"));
        Arkanoid32->setMenuBar(menubar);
        statusbar = new QStatusBar(Arkanoid32);
        statusbar->setObjectName("statusbar");
        statusbar->setStyleSheet(QString::fromUtf8("background-color: rgb(178, 134, 255);"));
        Arkanoid32->setStatusBar(statusbar);

        retranslateUi(Arkanoid32);

        QMetaObject::connectSlotsByName(Arkanoid32);
    } // setupUi

    void retranslateUi(QMainWindow *Arkanoid32)
    {
        Arkanoid32->setWindowTitle(QCoreApplication::translate("Arkanoid32", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Arkanoid32", "Connection settings", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Arkanoid32", "Connect", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Arkanoid32", "Disconnect", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Arkanoid32", "Search", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Arkanoid32", "Logs", nullptr));
        pushButton->setText(QCoreApplication::translate("Arkanoid32", "PLAY", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("Arkanoid32", "EASY", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("Arkanoid32", "MEDIUM", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("Arkanoid32", "HARD", nullptr));

        comboBox_3->setItemText(0, QCoreApplication::translate("Arkanoid32", "English", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("Arkanoid32", "Polski", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("Arkanoid32", "\320\240\321\203\321\201\321\201\320\272\320\270\320\271", nullptr));

        pushButton_2->setText(QCoreApplication::translate("Arkanoid32", "EXIT", nullptr));
        label->setText(QCoreApplication::translate("Arkanoid32", "ARKANOID32", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Arkanoid32", "Axis data", nullptr));
        label_2->setText(QCoreApplication::translate("Arkanoid32", "X:", nullptr));
        label_3->setText(QCoreApplication::translate("Arkanoid32", "Y:", nullptr));
        label_4->setText(QCoreApplication::translate("Arkanoid32", "Z:", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Arkanoid32", "Charts", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Arkanoid32: public Ui_Arkanoid32 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
