/********************************************************************************
** Form generated from reading UI file 'wykresy.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WYKRESY_H
#define UI_WYKRESY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Wykresy
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Wykresy)
    {
        if (Wykresy->objectName().isEmpty())
            Wykresy->setObjectName("Wykresy");
        Wykresy->resize(800, 600);
        Wykresy->setMinimumSize(QSize(450, 300));
        Wykresy->setCursor(QCursor(Qt::ArrowCursor));
        Wykresy->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 15, 34);"));
        centralwidget = new QWidget(Wykresy);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer = new QSpacerItem(20, 504, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(596, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 41, 113);\n"
"color: rgb(255, 255, 255)"));

        horizontalLayout->addWidget(comboBox);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 41, 113);\n"
"color: rgb(255, 255, 255)"));

        horizontalLayout->addWidget(pushButton);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 1);

        Wykresy->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Wykresy);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Wykresy->setMenuBar(menubar);
        statusbar = new QStatusBar(Wykresy);
        statusbar->setObjectName("statusbar");
        Wykresy->setStatusBar(statusbar);

        retranslateUi(Wykresy);

        QMetaObject::connectSlotsByName(Wykresy);
    } // setupUi

    void retranslateUi(QMainWindow *Wykresy)
    {
        Wykresy->setWindowTitle(QCoreApplication::translate("Wykresy", "Charts", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Wykresy", "chartX", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Wykresy", "chartY", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Wykresy", "chartZ", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Wykresy", "chartXYZ", nullptr));

        pushButton->setText(QCoreApplication::translate("Wykresy", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Wykresy: public Ui_Wykresy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WYKRESY_H
