#include "gamewindow.h"
#include "ui_wykesy.h"

gamewindow::gamewindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::gamewindow)
{
    ui->setupUi(this);
}

gamewindow::~gamewindow()
{
    delete ui;
}
