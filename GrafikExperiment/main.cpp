#include "filmonsmainwindow.h"
#include "grafikyta.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FilmonsMainWindow w;
    w.show();

    Grafikyta grafikyta;
    grafikyta.show();
    return a.exec();
}
