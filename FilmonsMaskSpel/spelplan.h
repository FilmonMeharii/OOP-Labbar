#ifndef SPELPLAN_H
#define SPELPLAN_H

#include <QWidget>
#include <deque>
#include <QKeyEvent>

class Spelplan : public QWidget
{
    Q_OBJECT
public:
    //Spelplan();
    explicit Spelplan(QWidget *parent = nullptr);


protected:
    void keyPressEvent(QKeyEvent *event) override;
    void paintEvent (QPaintEvent *event) override;
   // bool snakeEvent(QPaintEvent *head);
    void timerEvent(QTimerEvent *event) override;

private:
    //const int m_cellstorlek = 5;
    QImage dot;
    QImage head;
    QImage apple;
    QImage ded;


    static const int b_widith = 700;
    static const int b_height = 700;
    static const int dot_size = 10;
    static const int all_dots = 900;
    static const int rand_pos = 29;
    static const int delay = 140;

    int timerId;
    int dots;
    int apple_x;
    int apple_y;
    int score;

    int x[all_dots];
    int y[all_dots];

    bool leftDirection;
    bool rightDirection;
    bool upDirection;
    bool downDirection;
    bool inGame;

    void loadImages();
    void initGame();
    void locateApple();
    void checkApple();
    void checkCollision();
    void move();
    void doDrawing();
    void gameOver(QPainter &);

    /*struct RK{
        RK(int r =0, int k=0) : m_r(r), m_k(k){}
        int m_r;
        int m_k;
    };
    RK m_rkRiktning;
    RK m_rkHuvud;
    std::deque<RK> m_masken*/;
};

#endif // SPELPLAN_H
