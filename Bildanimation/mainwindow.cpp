#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionFramsida_triggered()
{
    ui->bildyta->visaFramsidan(true);
    ui->actionBaksida->setChecked(false);
    ui->actionFramsida->setChecked(true);
}


void MainWindow::on_actionBaksida_triggered()
{
    ui->bildyta->visaFramsidan(false);
    ui->actionBaksida->setChecked(true);
    ui->actionFramsida->setChecked(false);
}

