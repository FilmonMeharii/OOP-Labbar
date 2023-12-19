#include "grafikyta.h"
#include <QPaintEvent>
#include <QPainter>
#include <QColor>
#include <QPen>
#include <QRect>
#include <QPoint>

Grafikyta::Grafikyta(QWidget *parent) : QWidget(parent)
{
    QPainter painter(this);

    QColor farg1 = Qt::red;
    QColor farg2 = QColor(rand()%256, rand()%256, rand()%256);
    QColor farg3 = QColor(255,255,0,200);

    painter.fillRect(rect(), Qt::white);

    QRect litenKvadrat(0,20,100,100);
    painter.fillRect(litenKvadrat, farg1);

    QPen pen(Qt::blue, 5);
    painter.setPen(pen);
    painter.setBrush(farg2);
    painter.drawRect(200,10,50,300);

    painter.setPen(Qt::black);
    painter.setBrush(farg3);
    painter.drawRect(50,50,300,100);

}


void Grafikyta::mousePressEvent(QMouseEvent *event)
{
}

void Grafikyta::paintEvent(QPaintEvent *event)
{
}
