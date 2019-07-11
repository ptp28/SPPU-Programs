#ifndef HOIST_H
#define HOIST_H

#include <QMainWindow>
#include<QPainter>

namespace Ui {
class hoist;
}

class hoist : public QMainWindow
{
    Q_OBJECT

public:
    explicit hoist(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void start_anim();
    void initiate();
    void flag_hoist();
    int z=5;
    float i=100,flag=0,y=470;
    float c=i-50;
    ~hoist();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::hoist *ui;
};

#endif // HOIST_H
