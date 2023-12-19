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
    void on_quitButton_clicked(bool checked);

    void on_actionFile_triggered();

    void on_actionSave_triggered();

    void on_actionopen_triggered();

private:
    Ui::FilmonsMainWindow *ui;
};
#endif // FILMONSMAINWINDOW_H
