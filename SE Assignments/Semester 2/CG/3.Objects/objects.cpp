#include "objects.h"
#include "ui_objects.h"

Objects::Objects(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Objects)
{
    flag=0;
    colour=0;
    ui->setupUi(this);
    ui->pushButton_2->setVisible(0);
}

void Objects::plot(int X1, int Y1, int x, int y)
{
    QPainter p(this);
    if(colour==1)
    {
        p.setPen(QPen(Qt::red,2));
    }
    else if(colour==2)
    {
        p.setPen(QPen(Qt::red,2));
    }
    else if(colour==3)
    {
        p.setPen(QPen(Qt::blue,2));
    }
    p.drawPoint(X1+x,Y1+y);
    p.drawPoint(X1-x,Y1+y);
    p.drawPoint(X1+x,Y1-y);
    p.drawPoint(X1-x,Y1-y);
    p.drawPoint(X1+y,Y1+x);
    p.drawPoint(X1+y,Y1-x);
    p.drawPoint(X1-y,Y1+x);
    p.drawPoint(X1-y,Y1-x);


}

void Objects:: dcircle(int xc,int yc,int r)
{

            int x=0,y=r;

            int p=3-2*r;
            do
            {
                plot(xc,yc,x,y);
                if(p<0)
                {

                    p=p+4*x+6;
                }
                else
                {
                    y=y-1;
                    p=p+4*x-4*y+10;
                }
                x++;
            }while(x<=y);
}


void Objects::paintEvent(QPaintEvent *)
{
    int x,y,r,h,b;
    x=ui->textEdit->toPlainText().toInt();
    y=ui->textEdit_2->toPlainText().toInt();
    r=ui->textEdit_3->toPlainText().toInt();
    if(flag==1)
    {
        dcircle(x,y,r);
    h=2*r;
    b=(qSqrt(3)/(2))*h;
    dline(x-b,y+r,x+b,y+r);
    dline(x,y-h,x+b,y+r);
    dline(x,y-h,x-b,y+r);
    dcircle(x,y,h);
    }

}

void Objects:: plot(int x,int y)
{
    QPainter p(this);
    if(colour==1)
    {
        p.setPen(QPen(Qt::yellow,3));
    }
    else if(colour==2)
    {
        p.setPen(QPen(Qt::blue,2));
    }
    else if(colour==3)
    {
        p.setPen(QPen(Qt::yellow,3));
    }
    p.drawPoint(x,y);

}

void Objects::dline(int x1, int y1, int x2, int y2)
{

    //QPainter p(this);
    //p.drawLine(x1,y1,x2,y2);
    int xinc,yinc,i,flag=0,id=0;
       int dx,dy,length,temp;

       dx=abs(x2-x1);
       dy=abs(y2-y1);
       if(abs(dx)>=abs(dy))  //To decide the value of 'length'...
       {
        length=dx;
       }
      else
      {
       length=dy;
      }
      xinc=sign(x2-x1);
      yinc=sign(y2-y1);
      if(dy>dx)
      {
       temp=dx;
       dx=dy;
       dy=temp;
       flag=1;
      }
      else
      {
       flag=0;
      }

      id=(2*dy)-dx;
      x1=x1+0.5;
      y1=y1+0.5;
      for(i=0;i<length;i++)
      {
       plot(x1,y1);
       if(id<0)
       {
        if(flag==1)
                {
                   y1=y1+yinc;
                }
                else
                {
                    x1=x1+xinc;
                }
                id=id+(2*dy);
       }

       else
       {
        x1=x1+xinc;
        y1=y1+yinc;
        id=id+(2*dy)-(2*dx);
       }
      }
   }

int Objects::sign(int s)
{
    if(s<0)
            return -1;
        else if(s==0)
            return 0;
        else
            return 1;
}

Objects::~Objects()
{
    delete ui;
}

void Objects::on_pushButton_clicked()
{
    flag=1;
    ui->label->setVisible(0);
    ui->label_2->setVisible(0);
    ui->label_3->setVisible(0);
    ui->textEdit->setVisible(0);
    ui->textEdit_2->setVisible(0);
    ui->textEdit_3->setVisible(0);
    ui->pushButton->setVisible(0);
    ui->label_4->setVisible(0);
    ui->radioButton->setVisible(0);
    ui->radioButton_2->setVisible(0);
    ui->radioButton_3->setVisible(0);
    ui->pushButton_2->setVisible(1);
    update();
}

void Objects::on_pushButton_2_clicked()
{
    flag=0;
    ui->pushButton_2->setVisible(0);
    ui->label->setVisible(1);
    ui->label_2->setVisible(1);
    ui->label_3->setVisible(1);
    ui->textEdit->setVisible(1);
    ui->textEdit_2->setVisible(1);
    ui->textEdit_3->setVisible(1);
    ui->pushButton->setVisible(1);
    ui->label_4->setVisible(1);
    ui->radioButton->setVisible(1);
    ui->radioButton_2->setVisible(1);
    ui->radioButton_3->setVisible(1);
    update();
}

void Objects::on_radioButton_clicked()
{
    colour=1;
}

void Objects::on_radioButton_3_clicked()
{
    colour=2;
}

void Objects::on_radioButton_2_clicked()
{
    colour=3;
}
