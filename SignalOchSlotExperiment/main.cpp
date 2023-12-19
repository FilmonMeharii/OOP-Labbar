#include "filmonsmainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FilmonsMainWindow w;
    w.show();
    return a.exec();
}
