#include "ui_setup.h"
#include "SetUp.h"
#include "Udpserver.h"

SetUp::SetUp(QWidget *parent) : QDialog(parent) , ui(new Ui::SetUp)
{
    ui->setupUi(this);
}

SetUp::~SetUp()
{
    delete ui;
}



void SetUp::on_pushButton_clicked()
{
    Udpserver *w = new Udpserver(ui->lineEdit->text());
    w->show();

    this->hide();
}

void SetUp::on_pushButton_2_clicked()
{
    qApp->quit();
}
