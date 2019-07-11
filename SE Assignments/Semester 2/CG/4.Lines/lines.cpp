#include "lines.h"
#include "ui_lines.h"

lines::lines(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::lines)
{
    ui->setupUi(this);
    ui->pushButton_5->setVisible(0);
    flag=0;
}

lines::~lines()
{
    delete ui;
}

void lines :: paintEvent(QPaintEvent *)
{
    int x1,y1,x2,y2,thick;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    if(flag==1)
    {
        draw(10,x1,y1,x2,y2);
    }
    else if(flag>1)
    {
        draw_three(x1,y1,x2,y2);
    }
}

void lines :: plot(int x,int y)
{
    QPainter p(this);
    if(color==1)
        p.setPen(Qt::red);
    else if(color==2)
        p.setPen(Qt::blue);
    else if(color==3)
        p.setPen(Qt::yellow);
    else if(color==4)
        p.setPen(Qt::green);
    p.drawPoint(x,y);
}

void lines :: draw(int t, int x1, int y1, int x2, int y2)
{
    int w;
    w = (t-1)/2*(sqrt((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1)))/(x2-x1);
    int Y1, Y2;
    Y1 = y1+w; Y2 = y2-w;
    int k = w+w+1;
    while(k--)
    {
          draw_thick(x1, Y1, x2, Y2);
          Y1--; Y2++;
    }
}

void lines :: draw_three(int x1,int y1,int x2,int y2)
{
    double dx,dy,length,i,l1,l2;
    double xinc,yinc,x,y;

      dx=(x2-x1);
       dy=(y2-y1);

          if(dx<0)
          {
             l1=-dx;
          }
          else
             l1=dx;

          if(dy<0)
          {
             l2=-dy;
          }
          else
             l2=dy;

          if(l2>=l1)
          {
             length=l2;
          }
          else
          {
             length=l1;
          }
          yinc=dy/length;
          xinc=dx/length;

          x=x1+0.5;
          y=y1+0.5;
          for(i=0;i<length;i++)
          {
              if(int(x)%5!=0 ||int(y)%5!=0 && flag==2)
              {
                plot(x,y);
              }
              if((int(x)%2!=0 ||int(y)%2!=0) && flag==3)
              {
                plot(x,y);
              }
              if((int)i%9!=1 && (int)i%9!=8 && flag==4)
              {
                plot(x,y);
              }
             x=x+xinc;
             y=yinc+y;

             }
}



void lines :: draw_thick(int x1,int y1,int x2,int y2)
{
    int xinc,yinc,i,flag=0;
    int id=0;
       int dx,dy,length,temp;

       dx=abs(x2-x1);

       dy=abs(y2-y1);

       if(abs(dx)>=abs(dy))
       {
        length=dx;
       }
      else
      {
       length=dy;
      }
      xinc=sign(x2-x1);
      yinc=sign(y2-y1);
      if(abs(dy)>abs(dx))
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

    int lines::sign(int r)
    {
        if(r<0)
        {
            return -1;
        }
        else if(r==0)
        {
            return 0;
         }
        else
        {
           return 1;
        }
    }

    void lines :: hideUI()
    {
        ui->textEdit->setVisible(false);
        ui->textEdit_2->setVisible(false);
        ui->textEdit_3->setVisible(false);
        ui->textEdit_4->setVisible(false);
        ui->radioButton->setVisible(false);
        ui->radioButton_2->setVisible(false);
        ui->radioButton_3->setVisible(false);
        ui->radioButton_4->setVisible(false);
        ui->label->setVisible(false);
        ui->label_2->setVisible(false);
        ui->label_3->setVisible(false);
        ui->label_4->setVisible(false);
        ui->label_5->setVisible(false);
        ui->label_6->setVisible(false);
        ui->label_7->setVisible(false);
        ui->pushButton->setVisible(false);
        ui->pushButton_2->setVisible(false);
        ui->pushButton_3->setVisible(false);
        ui->pushButton_4->setVisible(false);
        ui->pushButton_5->setVisible(true);
    }

    void lines :: showUI()
    {
        ui->textEdit->setVisible(true);
        ui->textEdit_2->setVisible(true);
        ui->textEdit_3->setVisible(true);
        ui->textEdit_4->setVisible(true);
        ui->radioButton->setVisible(true);
        ui->radioButton_2->setVisible(true);
        ui->radioButton_3->setVisible(true);
        ui->radioButton_4->setVisible(true);
        ui->label->setVisible(true);
        ui->label_2->setVisible(true);
        ui->label_3->setVisible(true);
        ui->label_4->setVisible(true);
        ui->label_5->setVisible(true);
        ui->label_6->setVisible(true);
        ui->label_7->setVisible(true);
        ui->pushButton->setVisible(true);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_3->setVisible(true);
        ui->pushButton_4->setVisible(true);
        ui->pushButton_5->setVisible(false);
    }

void lines::on_pushButton_clicked()
{
    flag=1;
    hideUI();
    update();
}

void lines::on_pushButton_2_clicked()
{
    flag=2;
    hideUI();
    update();
}

void lines::on_pushButton_3_clicked()
{
     flag=3;
     hideUI();
     update();
}

void lines::on_pushButton_4_clicked()
{
     flag=4;
     hideUI();
     update();
}

void lines::on_radioButton_clicked()
{
    color=1;
}

void lines::on_radioButton_2_clicked()
{
    color=2;
}

void lines::on_radioButton_3_clicked()
{
    color=3;
}

void lines::on_radioButton_4_clicked()
{
    color=4;
}

void lines::on_pushButton_5_clicked()
{
    showUI();
    update();
}
