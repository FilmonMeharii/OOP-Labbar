#include "bildyta.h"
#include <QPixmap>
#include <QPainter>
#include <QtDebug>
#include <QPropertyAnimation>
#include <QMouseEvent>


Bildyta::Bildyta(QWidget *parent) : QWidget(parent)
{
    m_framsida = QPixmap(":/bilder/Kungenframsida.png");
    m_baksida = QPixmap(":/bilder/baksidan.png");

    m_pLabel = new QLabel(this);

    m_pLabel->setPixmap(m_framsida);
    m_pLabel->setScaledContents(true);
    m_pLabel->resize(100,100);
}

void Bildyta::mousePressEvent(QMouseEvent *event)
{
    QRect rc = m_pLabel->geometry();

    QRect rcDestination(event->pos().x()-rc.width()/2,
                        event->pos().y()-rc.height()/2,
                        rc.width(),
                        rc.height());

    const int antalMillisekunder = 1000;
    QPropertyAnimation *pMoveAnimation = new QPropertyAnimation(m_pLabel, "geometry");
    pMoveAnimation->setDuration(antalMillisekunder);
    pMoveAnimation->setStartValue(rc);
    pMoveAnimation->setEndValue(rcDestination);
    //pMoveAnimation->setEasingCurve(QEasingCurve::OutElastic);
    pMoveAnimation->start();
}

void Bildyta::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(rect(), Qt::white);
}
