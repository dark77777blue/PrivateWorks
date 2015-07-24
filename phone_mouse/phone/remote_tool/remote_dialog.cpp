#include "remote_dialog.h"
#include "ui_remote_dialog.h"

Remote_Dialog::Remote_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Remote_Dialog)
{
    ui->setupUi(this);
}

Remote_Dialog::~Remote_Dialog()
{
    delete ui;
}
