#include "spelplan.h"
#include <QTimer>
#include <QPainter>
#include <QKeyEvent>
#include <QPaintEvent>


Spelplan::Spelplan(QWidget *parent) : QWidget(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Spelplan::uppdateraMasken);
    timer->start(50);

    setFocus();
    m_rkHuvud = RK(50,50);
    m_rkRiktning = RK(0,0);

}

void Spelplan::uppdateraMasken()
{
    m_rkHuvud.m_r += m_rkRiktning.m_r;
    m_rkHuvud.m_k += m_rkRiktning.m_k;

    m_masken.push_front(m_rkHuvud);
    if(m_masken.size() > 100)
        m_masken.pop_back();
}

void Spelplan::keyPressEvent(QKeyEvent *event)
{
    int k = event->key();

    if(k==Qt::Key_Down) m_rkRiktning = RK(1,0);
    if(k==Qt::Key_Up) m_rkRiktning = RK(-1,0);
    if(k==Qt::Key_Left) m_rkRiktning = RK(0,-1);
    if(k==Qt::Key_Right) m_rkRiktning = RK(0,1);

}

void Spelplan::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(rect(), Qt::white);
    painter.fillRect(m_rkHuvud.m_k*m_cellstorlek,
                     m_rkHuvud.m_r*m_cellstorlek,
                     m_cellstorlek,
                     m_cellstorlek,
                     Qt::black);

    for(unsigned int i=0; i<m_masken.size(); ++i){
        RK rk= m_masken[i];
        painter.fillRect(rk.m_k*m_cellstorlek,
                         rk.m_r*m_cellstorlek,
                         m_cellstorlek,
                         m_cellstorlek,
                         Qt::black);
    }
}
