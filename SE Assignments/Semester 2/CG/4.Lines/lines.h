#ifndef LINES_H
#define LINES_H

#include <QMainWindow>
#include<QPainter>
#include<math.h>

namespace Ui {
class lines;
}

class lines : public QMainWindow
{
    Q_OBJECT
    int flag;
    int color;

public:
    explicit lines(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void draw_three(int,int,int,int);
    void draw_thick(int,int,int,int);
    void draw(int, int,int,int,int);
    int sign(int);
    void plot(int x,int y);
    void hideUI();
    void showUI();
    ~lines();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::lines *ui;
};

#endif // LINES_H
