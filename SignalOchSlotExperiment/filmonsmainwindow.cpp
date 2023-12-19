#include "filmonsmainwindow.h"
#include "ui_filmonsmainwindow.h"
#include <QLabel>

FilmonsMainWindow::FilmonsMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FilmonsMainWindow)
{
    ui->setupUi(this);

    connect(ui->knappB, &QPushButton::clicked, this, &FilmonsMainWindow::knappBKlickades);
    connect(ui->knappC, SIGNAL(clicked()), this, SLOT(knappCKlickades()));
    connect(ui->knappD, "2clicked()" , this, "1knappDKlickades()" );
    connect(ui->knappE, "2clicked()" , this, "1knappEKlickades()" );
    connect(ui->knappF, &QPushButton::clicked,
    this, [this](){ui->label1->setText("Knapp F klickades");});

    for(QObject* child : ui->centralwidget->children()){
        QPushButton *button = dynamic_cast<QPushButton*>(child);
        if(button){
            connect(button, SIGNAL(clicked()), this, SLOT(someButtonWasClicked()));
        }
    }
}

FilmonsMainWindow::~FilmonsMainWindow()
{
    delete ui;
}


void FilmonsMainWindow::on_knappA_clicked()
{
    ui->label1->setText("knapp A klickades!");
}

void FilmonsMainWindow::on_knappE_clicked()
{
    ui->label1->setText("knapp E klickades!");

}

void FilmonsMainWindow::knappBKlickades()
{
    ui->label1->setText("knapp B klickades!");
}

void FilmonsMainWindow::knappCKlickades()
{
    ui->label1->setText("knapp C klickades!");
}

void FilmonsMainWindow::knappDKlickades()
{
    ui->label1->setText("knapp D klickades!");
}

void FilmonsMainWindow::someButtonWasClicked()
{
    QPushButton *button = dynamic_cast<QPushButton*>(sender());
    if(button){
        QString str= "Textpa pa tryckknapp = " + button->text();
        ui->label2->setText(str);
    }
}

