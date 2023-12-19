#ifndef FILMONSMAINWINDOW_H
#define FILMONSMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class FilmonsMainWindow; }
QT_END_NAMESPACE

class FilmonsMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    FilmonsMainWindow(QWidget *parent = nullptr);
    ~FilmonsMainWindow();

private slots:
    void on_knappA_clicked();
    void on_knappE_clicked();
    void knappBKlickades();
    void knappCKlickades();
    void knappDKlickades();

    void someButtonWasClicked();

private:
    Ui::FilmonsMainWindow *ui;
};
#endif // FILMONSMAINWINDOW_H
