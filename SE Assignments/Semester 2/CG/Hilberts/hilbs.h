#ifndef HILBS_H
#define HILBS_H

#include <QMainWindow>
//#include<QKeyEvent>
namespace Ui {
class hilbs;
}

class hilbs : public QMainWindow
{
    Q_OBJECT

public:
    explicit hilbs(QWidget *parent = 0);
    ~hilbs();\
    void hilbert(int r, int d, int l, int u, int i, int h, int &x, int &y);
    void move(int j, int h, int &x, int &y);
    void changeEvent(QEvent *e);
  //  void keyPressEvent(QKeyEvent *event);
    int p1,p2;
    int flag;
    void paintEvent(QPaintEvent *event);


private slots:
    void on_pushButton_clicked();

private:
    Ui::hilbs *ui;
};

#endif // HILBS_H
