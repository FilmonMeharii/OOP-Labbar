#include "filmonsmainwindow.h"
#include "ui_filmonsmainwindow.h"
#include <QDebug>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>

FilmonsMainWindow::FilmonsMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FilmonsMainWindow)
{
    ui->setupUi(this);
}

FilmonsMainWindow::~FilmonsMainWindow()
{
    delete ui;
}


void FilmonsMainWindow::on_quitButton_clicked(bool checked)
{
    // if(checked)
    QApplication::quit();
}


void FilmonsMainWindow::on_actionFile_triggered()
{

}


void FilmonsMainWindow::on_actionSave_triggered()
{
    QString filnamn = QFileDialog::getSaveFileName(
                this,
                "Open Fil",
                "",
                "Text Files(*.txt);; c++-Files(*.h*.cpp)"
                );
    if(!filnamn.isEmpty()){
        QFile fil(filnamn);
        if(!fil.open(QIODevice::WriteOnly)){
            QMessageBox::critical(this, "Error", "Could not write file");
            return;
        }
        QTextStream ut(&fil);
        ut<<ui->textEdit->toPlainText();
        ut.flush();
        fil.close();
    }
}


void FilmonsMainWindow::on_actionopen_triggered()
{
    QString filnamn = QFileDialog::getOpenFileName(
                this,
                "Open Fil",
                "",
                "Text Files(*.txt);; c++-Files(*.h*.cpp)"
                );
    if(!filnamn.isEmpty()){
        QFile fil(filnamn);
        if(!fil.open(QIODevice::ReadOnly)){
            QMessageBox::critical(this, "Error", "Could not open file");
            return;
        }
        QTextStream in(&fil);
        ui->textEdit->setText(in.readAll());
        fil.close();
    }

}

