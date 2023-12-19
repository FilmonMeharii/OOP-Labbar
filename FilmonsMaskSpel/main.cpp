#include "mainwindow.h"
#include "spelplan.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    Spelplan w;
    w.show();
    //w.show();
    return a.exec();
}
