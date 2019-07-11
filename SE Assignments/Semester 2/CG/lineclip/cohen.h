#ifndef COHEN_H
#define COHEN_H
#include <QPainter>
#include <QMainWindow>
#include <QMouseEvent>

namespace Ui {
class cohen;
}

class cohen : public QMainWindow
{
    Q_OBJECT
    int flag, x1, x2, y1, y2, xr1, xr2, yr1, yr2, x[20], y[20], code[20][4], ix, iy, f;
    int count = 0, d[20];
public:

    explicit cohen(QWidget *parent = 0);

    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void clip();
    void opcode();
    int test();
    ~cohen();

private slots:
    void on_clip_clicked();

private:
    Ui::cohen *ui;
};

#endif // COHEN_H
