#include "curve.h"
#include "ui_curve.h"

curve::curve(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::curve)
{
    ui->setupUi(this);
    flag=0;
    n=5;
}

void curve :: function(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4,int t)
{
    if(t>0)
    {
        QPainter p(this);
        int xb,xc,xd,xe,xf;
        int yb,yc,yd,ye,yf;
        xb=(x1+x2)/2;
        xc=(x2+x3)/2;          // form half rect who's midpoint will be xb,xc. u will geet triangle after joining 2 midpts
        xd=(x3+x4)/2;

        xe=(xd+x4)/2;
        xd=(xc+xd)/2;
        xc=(xb+xc)/2;
        xb=(x1+xb)/2;

        xf=(x4+xe)/2;
        xe=(xe+xd)/2;
        xd=(xd+xc)/2;
        xc=(xc+xb)/2;
        xb=(xb+x1)/2;

        yb=(y1+y2)/2;
        yc=(y2+y3)/2;
        yd=(y3+y4)/2;

        ye=(yd+y4)/2;
        yd=(yc+yd)/2;
        yc=(yb+yc)/2;
        yb=(y1+yb)/2;

        yf=(y4+ye)/2;
        ye=(ye+yd)/2;
        yd=(yd+yc)/2;
        yc=(yc+yb)/2;
        yb=(yb+y1)/2;

        if(t==1)
        {
            p.setRenderHint(QPainter::Antialiasing);
            p.drawLine(x1,y1,xb,yb);
            p.drawLine(xb,yb,xc,yc);
            p.drawLine(xc,yc,xd,yd);
            p.drawLine(xd,yd,xe,ye);
            p.drawLine(xe,ye,xf,yf);
            p.drawLine(xf,yf,x4,y4);
        }
        function(x1,y1,xb,yb,xc,yc,xd,yd,t-1);
        function(xd,yd,xe,ye,xf,yf,x4,y4,t-1);
    }
}

void curve :: mousePressEvent(QMouseEvent *m)
{
    x=m->x();
    y=m->y();
    flag=1;
    update();
}

void curve :: paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    if(flag==1)
    {
        ui->label_2->setText(QString :: number(x));
        ui->label_4->setText(QString :: number(y));
        function(x-50,y-50,x-50,y-250,x+50,y-250,x+50,y-50,n);
        function(x-50,y+50,x-250,y+50,x-250,y-50,x-50,y-50,n);
        function(x+50,y+50,x+50,y+250,x-50,y+250,x-50,y+50,n);
        function(x+50,y-50,x+250,y-50,x+250,y+50,x+50,y+50,n);
        function(x-100,y,x-200,y-150,x-150,y-250,x,y-100,n);
        function(x,y+100,x-150,y+250,x-200,y+150,x-100,y,n);
        function(x+100,y,x+200,y+150,x+150,y+250,x,y+100,n);
        function(x,y-100,x+150,y-250,x+200,y-150,x+100,y,n);
        flag=0;
    }
}

curve::~curve()
{
    delete ui;
}
