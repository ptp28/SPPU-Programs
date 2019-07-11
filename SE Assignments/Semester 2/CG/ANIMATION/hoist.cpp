#include "hoist.h"
#include "ui_hoist.h"

hoist::hoist(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::hoist)
{
    ui->setupUi(this);
}

hoist::~hoist()
{
    delete ui;
}

void hoist::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    int a=0;
    p.drawLine(00,600,1500,600);            //
    if(flag==1)
        initiate();
    if(flag==2)
    {
     {
            if(i<600)
             {
                start_anim();
            }
            else
            {
                a=1;
            }
        if(a==1)
        {
             initiate();
             flag_hoist();
        }
     }
    }
}
void hoist::initiate()
{
    QPainter q(this);

    q.setPen(QPen(Qt::black,3));
    q.drawEllipse(QPointF(i,400), 30, 30);
    q.drawEllipse(QPointF(c,500), 20, 20);

    q.setPen(QPen(Qt::black,3));
    q.drawLine(i,430,i,530);            //vertical line  man1
    q.drawLine(i,530,i-10,600);
    q.drawLine(i,530,i+20,600);
    q.drawLine(i,450,i-20,470);
    q.drawLine(i,450,i+40,470);

    q.drawRect(633,200,10,400);        //flag pole

    q.drawLine(c,520,c,570);
    q.drawLine(c,570,c-10,600);
    q.drawLine(c,570,c+20,600);         //man2
    q.drawLine(c,550,c-20,570);
    q.drawLine(c,550,c+40,570);

    q.drawRect(643,y,z,33);                     //flag drawing starts here
    q.fillRect(643,y+1,z,33,Qt::red);
    q.drawRect(643,y+33,z,33);
    q.fillRect(643,y+34,z,33,Qt::white);
    q.drawRect(643,y+66,z,33);
    q.fillRect(643,y+67,z,33,Qt::green);
}
void hoist::start_anim()
{
    QPainter q(this);
    int j=i,k=c;
    q.setPen(QPen(Qt::black,3));
    q.drawEllipse(QPointF(i,400), 30, 30);
    q.drawEllipse(QPointF(c,500), 20, 20);

    q.setPen(QPen(Qt::black,3));
    q.drawLine(i,430,i,530);
    q.drawLine(c,520,c,570);
    if(j%3==0)
    {
        q.drawLine(i,530,i-10,600);
        q.drawLine(i,530,i+20,600);
        q.drawLine(i,450,i-20,470);
        q.drawLine(i,450,i+20,470);

        q.drawLine(c,570,c-10,600);
        q.drawLine(c,570,c+20,600);
        q.drawLine(c,550,c-20,570);
        q.drawLine(c,550,c+40,570);
    }
    else
    {
        q.drawLine(i,530,i-20,600);
        q.drawLine(i,530,i+10,600);
        q.drawLine(i,450,i-20,470);
        q.drawLine(i,450,i+15,470);

        q.drawLine(c,570,c-20,600);
        q.drawLine(c,570,c+10,600);
        q.drawLine(c,550,c-20,570);
        q.drawLine(c,550,c+15,570);
    }
    i=i+0.5;
    c=c+0.5;
    q.drawRect(633,200,10,400);     //flag pole
    update();
}

void hoist::flag_hoist()
{
    QPainter q(this);
    q.drawRect(643,y,z,33);             //draw & colour while hoisting
    q.fillRect(643,y+1,z,33,Qt::red);
    q.drawRect(643,y+33,z,33);
    q.fillRect(643,y+34,z,33,Qt::white);
    q.drawRect(643,y+66,z,33);
    q.fillRect(643,y+67,z,33,Qt::green);
    if(y>200)
    y=y-1;
    if(z<150)
        z=z+1;
    update();
}

void hoist::on_pushButton_clicked()         //start
{
    flag=2;
    update();
}

void hoist::on_pushButton_2_clicked()
{
    flag=1;
    update();
}

void hoist::on_pushButton_3_clicked()
{
    flag=1;
    update();
}
