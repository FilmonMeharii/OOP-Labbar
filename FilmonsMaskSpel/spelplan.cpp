#include "spelplan.h"
#include <QTimer>
#include <QPainter>
#include <QKeyEvent>
#include <QPaintEvent>
#include <QTime>

Spelplan::Spelplan(QWidget *parent) : QWidget(parent){

    setStyleSheet("background-color:gray;");
    leftDirection = false;
    rightDirection = true;
    upDirection = false;
    downDirection = false;
    inGame = true;

    setFixedSize(b_widith, b_height);
    loadImages();
    initGame();
}
//Updatera masken
/*
 void Spelplan::uppdateraMasken()
{
    m_rkHuvud.m_r +=m_rkRiktning.m_r;
    m_rkHuvud.m_k += m_rkRiktning.m_k;
    m_masken.push_front(m_rkHuvud);

    if(m_masken.size()>100)
        m_masken.pop_back();
    if(m_masken.size()!=0||m_masken.size()< 100)
        m_masken.pop_front();
    update(); //uppdaterar kordinaterna varje gång man flyttar musen
}
*/
void Spelplan::loadImages()
{
    dot.load(":/bilder/dot.png");
    head.load(":/bilder/head.png");
    apple.load(":/bilder/apple.png");
    ded.load(":/bilder/redDot.png");
}
void Spelplan::initGame(){
    dots = 10;
    for (int z = 0; z < dots; z++) {
        x[z] = 50 - z * 10;
        y[z] = 50;
    }
    locateApple();
    timerId = startTimer(delay);
}
void Spelplan::paintEvent(QPaintEvent *event){
    //QPainter
            /*QPainter painter(this);
        painter.fillRect(rect(), Qt::white);
        painter.fillRect ( m_rkHuvud.m_k*m_cellstorlek,
                           m_rkHuvud.m_r*m_cellstorlek,
                           m_cellstorlek, m_cellstorlek,
                           Qt::black);

        for(unsigned int i=0; i<m_masken.size(); ++i){
            RK rk = m_masken[i];
            painter.fillRect(rk.m_k*m_cellstorlek,
                             rk.m_r*m_cellstorlek,
                             m_cellstorlek,
                             m_cellstorlek,
                             Qt::black);
        }*/
    Q_UNUSED(event);
    doDrawing();
}
void Spelplan::doDrawing(){
    QPainter qp(this);

    if (inGame) {
        qp.drawImage(apple_x, apple_y, apple);

        for (int z = 0; z < dots; z++) {
            if (z == 0) {
                qp.drawImage(x[z], y[z], head);
            } else {
                qp.drawImage(x[z], y[z], dot);
            }
        }

    } else {
        for (int b=0; b<dots; b++ ) {
            qp.drawImage(x[b], y[b],ded);

        }
        gameOver(qp);
    }
}
void Spelplan::gameOver(QPainter &qp){
    QString message = "Game over!";
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.horizontalAdvance(message);
    qp.setFont(font);
    int h = height();
    int w = width();

    qp.translate(QPoint(w/2, h/4));
    qp.drawText(- textWidth/2, 0, message);

    QString point ="Your score \n" + QString::number(score);

    qp.translate(QPoint(w/180, h/15));
    qp.drawText(-textWidth/1.5, 0, point);
}
void Spelplan::checkApple(){
    if ((x[0] == apple_x) && (y[0] == apple_y)) {
        dots++;
        score+=10;
        locateApple();
    }
}
void Spelplan::move(){

    for (int z = dots; z > 0; z--) {
        x[z] = x[(z - 1)];
        y[z] = y[(z - 1)];
    }

    if (leftDirection) {
        x[0] -= dot_size;
    }

    if (rightDirection) {
        x[0] += dot_size;
    }

    if (upDirection) {
        y[0] -= dot_size;
    }

    if (downDirection) {
        y[0] += dot_size;
    }
}
void Spelplan::checkCollision(){
    for (int z = dots; z > 0; z--) {
        if ((z > 4) && (x[0] == x[z]) && (y[0] == y[z])) {
            inGame = false;
        }
    }
    if (y[0] >= b_height) {
        inGame = false;
    }
    if (y[0] < 0) {
        inGame = false;
    }
    if (x[0] >= b_widith) {
        inGame = false;
    }
    if (x[0] < 0) {
        inGame = false;
    }
    if(!inGame) {
        killTimer(timerId);
    }
}
void Spelplan::locateApple(){
    QTime time = QTime::currentTime();
    srand((uint) time.msec());
    int r = rand() % rand_pos;
    apple_x = (r * dot_size);

    r = rand() % rand_pos;
    apple_y = (r * dot_size);
}
void Spelplan::timerEvent(QTimerEvent *event){
    Q_UNUSED(event);

    if (inGame) {

        checkApple();
        checkCollision();
        move();

    }
    update();
}
void Spelplan::keyPressEvent(QKeyEvent *event)
{
    int key= event->key();
    if ((key == Qt::Key_Left) && (!rightDirection)) {
        leftDirection = true;
        upDirection = false;
        downDirection = false;
    }
    if ((key == Qt::Key_Right) && (!leftDirection)) {
        rightDirection = true;
        upDirection = false;
        downDirection = false;
    }
    if ((key == Qt::Key_Up) && (!downDirection)) {
        upDirection = true;
        rightDirection = false;
        leftDirection = false;
    }
    if ((key == Qt::Key_Down) && (!upDirection)) {
        downDirection = true;
        rightDirection = false;
        leftDirection = false;
    }
    QWidget::keyPressEvent(event);
}



