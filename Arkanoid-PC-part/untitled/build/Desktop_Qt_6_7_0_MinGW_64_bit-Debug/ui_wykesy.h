/********************************************************************************
** Form generated from reading UI file 'wykesy.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WYKESY_H
#define UI_WYKESY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_gamewindow
{
public:
    QPushButton *pushButton;
    QComboBox *comboBox;

    void setupUi(QDialog *gamewindow)
    {
        if (gamewindow->objectName().isEmpty())
            gamewindow->setObjectName("gamewindow");
        gamewindow->resize(521, 368);
        pushButton = new QPushButton(gamewindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(210, 330, 80, 24));
        comboBox = new QComboBox(gamewindow);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(130, 330, 72, 24));

        retranslateUi(gamewindow);

        QMetaObject::connectSlotsByName(gamewindow);
    } // setupUi

    void retranslateUi(QDialog *gamewindow)
    {
        gamewindow->setWindowTitle(QCoreApplication::translate("gamewindow", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("gamewindow", "Exit", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("gamewindow", "WykresX", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("gamewindow", "WykresY", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("gamewindow", "WykresZ", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("gamewindow", "WykresXYZ", nullptr));

    } // retranslateUi

};

namespace Ui {
    class gamewindow: public Ui_gamewindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WYKESY_H
