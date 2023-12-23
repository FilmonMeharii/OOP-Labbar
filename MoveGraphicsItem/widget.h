#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>

#include <moveitem.h>
QT_BEGIN_NAMESPACE
namespace Ui {
class widget;
}
QT_END_NAMESPACE
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit  Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::widget *ui;
    QGraphicsScene *scene;
};

#endif // WIDGET_H
