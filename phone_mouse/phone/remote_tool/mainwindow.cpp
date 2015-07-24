#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

#include "mouse_dialog.h"
#include "remote_dialog.h"
#include "netset_dialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->net_action->trigger();    //默认选中net_action
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::paintEvent(QPaintEvent *event)
//{
//    QPainter painter(this);
//    painter.fillRect(this->rect(), QColor(0, 0, 255, 80));
//}

void MainWindow::on_mouse_action_triggered()
{
    ui->mouse_action->setChecked(true);
    ui->net_action->setChecked(false);
    ui->remoute_action->setChecked(false);
    ui->sys_action->setChecked(false);
    ui->other_action->setChecked(false);

    Mouse_Dialog *mousedialog = new Mouse_Dialog;
    mousedialog->setAddr(addr_ip, addr_port);
    this->setCentralWidget(mousedialog);

}

void MainWindow::on_sys_action_triggered()
{
    ui->mouse_action->setChecked(false);
    ui->net_action->setChecked(false);
    ui->remoute_action->setChecked(false);
    ui->sys_action->setChecked(true);
    ui->other_action->setChecked(false);
}

void MainWindow::on_remoute_action_triggered()
{
    ui->mouse_action->setChecked(false);
    ui->net_action->setChecked(false);
    ui->remoute_action->setChecked(true);
    ui->sys_action->setChecked(false);
    ui->other_action->setChecked(false);

    Remote_Dialog *remotedialog = new Remote_Dialog;
    this->setCentralWidget(remotedialog);
}

void MainWindow::on_net_action_triggered()
{
    ui->mouse_action->setChecked(false);
    ui->net_action->setChecked(true);
    ui->remoute_action->setChecked(false);
    ui->sys_action->setChecked(false);
    ui->other_action->setChecked(false);

    NetSet_Dialog *netsetdialog = new NetSet_Dialog;
    this->setCentralWidget(netsetdialog);
}

void MainWindow::on_other_action_triggered()
{
    ui->mouse_action->setChecked(false);
    ui->net_action->setChecked(false);
    ui->remoute_action->setChecked(false);
    ui->sys_action->setChecked(false);
    ui->other_action->setChecked(true);
}
