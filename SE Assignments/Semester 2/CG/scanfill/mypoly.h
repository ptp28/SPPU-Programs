#ifndef MYPOLY_H
#define MYPOLY_H

#include <QMainWindow>
#include<QtGui>
#include<QPainter>
#include<QMouseEvent>
namespace Ui {
class mypoly;
}

class mypoly : public QMainWindow
{
    Q_OBJECT

public:
    int flag,colour;
    int x[10],y[10],count;
    void mousePressEvent(QMouseEvent *m);
    explicit mypoly(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    void myfunct();



    ~mypoly();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

private:
    Ui::mypoly *ui;
};

#endif // MYPOLY_H
