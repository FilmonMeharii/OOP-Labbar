#include "filmonsmainwindow.h"
#include "ui_filmonsmainwindow.h"

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

