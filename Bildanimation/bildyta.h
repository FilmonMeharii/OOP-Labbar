#ifndef BILDYTA_H
#define BILDYTA_H

#include <QWidget>
#include<qlabel.h>

class Bildyta : public QWidget
{
    Q_OBJECT
public:
    explicit Bildyta(QWidget *parent = nullptr);

    void visaFramsidan(bool visaFram);

signals:

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event)override;


private:
    QLabel *m_pLabel;
    QPixmap m_framsida;
    QPixmap m_baksida;

};

#endif // BILDYTA_H
