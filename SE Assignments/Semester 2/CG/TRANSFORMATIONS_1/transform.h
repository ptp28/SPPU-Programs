#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <QMainWindow>
#include<QPainter>
#include<QMouseEvent>
#include<QScreen>
#include<QRect>
#include<QPoint>
#include<QMetaType>
#include<QtGui>
#include<qmath.h>
#include<math.h>

namespace Ui {
class transform;
}

class transform : public QMainWindow
{
    Q_OBJECT

public:
    explicit transform(QWidget *parent = 0);
    ~transform();
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *m);
    float n[20][3];
    float p[20][3],t[20][3];
    float sca[20][3],rot[20][3];
    int width,height;
    int count=0,flag=0;

private slots:
    void on_comboBox_activated(int index);

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::transform *ui;
};

#endif // TRANSFORM_H
