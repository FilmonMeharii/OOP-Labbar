#ifndef GRAFIKYTA_H
#define GRAFIKYTA_H

#include <QWidget>

class Grafikyta : public QWidget
{
    Q_OBJECT
public:
    explicit Grafikyta(QWidget *parent = nullptr);

signals:


    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
};

#endif // GRAFIKYTA_H
