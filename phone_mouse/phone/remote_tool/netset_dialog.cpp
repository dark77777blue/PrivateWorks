#include "netset_dialog.h"
#include "ui_netset_dialog.h"
#include "mainwindow.h"

NetSet_Dialog::NetSet_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NetSet_Dialog)
{
    ui->setupUi(this);
}

NetSet_Dialog::~NetSet_Dialog()
{
    delete ui;
}

void NetSet_Dialog::on_saveBtn_clicked()
{
    ((MainWindow *)this->parent())->addr_ip = ui->ipEdit->text();
    ((MainWindow *)this->parent())->addr_port = ui->portEdit->text().toInt();
}
