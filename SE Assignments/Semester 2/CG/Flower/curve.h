#ifndef curve_H
#define curve_H

#include <QMainWindow>
#include <QtGui>
#include <QPainter>
#include<QMouseEvent>

namespace Ui {
class curve;
}

class curve : public QMainWindow
{
    Q_OBJECT
    int flag,n,x,y;
public:
    void function(int,int,int,int,int,int,int,int,int);
    explicit curve(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *m);
    ~curve();

private slots:

    void on_Draw_clicked();

private:
    Ui::curve *ui;
};

#endif // curve_H
