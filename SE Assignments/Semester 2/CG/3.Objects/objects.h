#ifndef OBJECTS_H
#define OBJECTS_H

#include <QMainWindow>
#include<QPainter>
#include<qmath.h>
#include<QtGlobal>
namespace Ui {
class Objects;
}

class Objects : public QMainWindow
{
    Q_OBJECT
    int flag;
    int colour;
public:
    void paintEvent(QPaintEvent*);
    explicit Objects(QWidget *parent = 0);
    void plot(int x,int y);
    void plot(int x1,int y1,int x,int y);
    void dcircle(int xc,int yc,int r);
    void dline(int x1,int y1,int x2,int y2);
    int sign(int s);

    ~Objects();

private slots:
    void on_pushButton_clicked();
    
    void on_pushButton_2_clicked();

    void on_radioButton_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_2_clicked();

private:
    Ui::Objects *ui;
};

#endif // OBJECTS_H
