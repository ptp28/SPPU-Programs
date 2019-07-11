#include "transform.h"
#include "ui_transform.h"
#include<iostream>
using namespace std;
transform::transform(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::transform)
{
    ui->setupUi(this);
    flag=0;
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<2;j++)
        {
            p[i][j]=0;t[i][j]=0;n[i][j]=0;rot[i][j]=0;
        }
        p[i][2]=1;t[i][2]=1;n[i][2]=1;rot[i][2]=1;
    }
    ui->comboBox_2->setVisible(0);
            ui->comboBox_3->setVisible(0);
            ui->pushButton_2->setVisible(0);
            ui->textEdit->setVisible(0);
            ui->label_angle->setVisible(0);
            ui->textEdit->setVisible(0);
            ui->label_6->setVisible(0);
            ui->label_7->setVisible(0);
            ui->textEdit_4->setVisible(0);
            ui->label_8->setVisible(0);
            ui->textEdit_5->setVisible(0);
}

transform::~transform()
{
    delete ui;
}

void transform::paintEvent(QPaintEvent *)
{
    QPainter q(this);
    int i;
    float x,y,xt,yt;
    {
        char buf[3];
        int k=0;
        QScreen *screen=QGuiApplication::primaryScreen();
        QRect screenGeometry=screen->geometry();
        height=screenGeometry.height();
        width=screenGeometry.width();
        q.drawLine(width/2,0,width/2,height);
        q.drawLine(0,height/2,width,height/2);
        for(i=width/2;i<width;i=i+50)
        {
        sprintf(buf,"%d",k);
        q.drawText(i,height/2+15,buf);
        k++;
        }
        k=-1;
        for(i=((width/2)-50);i>0;i=i-50)
        {
        sprintf(buf,"%d",k);
        q.drawText(i,height/2+15,buf);
        k--;
        }
        k=1;
        for(i=height/2-50;i>0;i=i-50)
        {
            sprintf(buf,"%d",k);
            q.drawText(width/2-15,i,buf);
            k++;
        }
        k=-1;
        for(i=height/2+50;i<height;i=i+50)
        {
            sprintf(buf,"%d",k);
            q.drawText(width/2-15,i,buf);
            k--;
        }
    }
     q.drawLine(0,height,width,0);
   for(i=0;i<=count;i++)
   {
     n[i][0]=(width/2-p[i][0])*-1/50;
     n[i][1]=(height/2-p[i][1])/50;
   }
   if(flag!=0)
   {
       q.setPen(QPen(Qt::red,2));
    for(i=0;i<count;i++)
    {

        q.drawLine(p[i][0],p[i][1],p[i+1][0],p[i+1][1]);
    }
   }
   q.setPen(QPen(Qt::blue,2));
   if(flag==2)
   {
       for(i=0;i<=count;i++)
       {
           t[i][0]=n[i][0];
           t[i][1]=n[i][1];
       }
      for(i=0;i<=count;i++)
       {
           t[i][1]=-1*t[i][1];
       }
       for(i=0;i<=count;i++)
       {
           t[i][0]=width/2+t[i][0]*50;
           t[i][1]=height/2-t[i][1]*50;
       }
       for(i=0;i<count;i++)
        q.drawLine(t[i][0],t[i][1],t[i+1][0],t[i+1][1]);
   }
   else if(flag==3)
   {
       for(i=0;i<=count;i++)
       {
           t[i][0]=n[i][0];
           t[i][1]=n[i][1];
       }
      for(i=0;i<=count;i++)
       {
           t[i][0]=-1*t[i][0];
       }
       for(i=0;i<=count;i++)
       {
           t[i][0]=width/2+t[i][0]*50;
           t[i][1]=height/2-t[i][1]*50;
       }
       for(i=0;i<count;i++)
        q.drawLine(t[i][0],t[i][1],t[i+1][0],t[i+1][1]);
   }
   else if(flag==4)
   {
       q.drawLine(0,height,width,0);
       for(i=0;i<=count;i++)
       {
           t[i][0]=n[i][0];
           t[i][1]=n[i][1];
       }
      for(i=0;i<=count;i++)
       {
           x=t[i][0];
           t[i][0]=t[i][1];
           t[i][1]=x;
       }
       for(i=0;i<=count;i++)
       {
           t[i][0]=width/2+t[i][0]*50;
           t[i][1]=height/2-t[i][1]*50;
       }
       for(i=0;i<count;i++)
        q.drawLine(t[i][0],t[i][1],t[i+1][0],t[i+1][1]);
   }
   else if(flag==5 || flag==6)
   {
       float k=ui->textEdit->toPlainText().toInt();
       k=k*3.14/180;
       x=ui->textEdit_4->toPlainText().toFloat();
       y=ui->textEdit_5->toPlainText().toFloat();
       for(i=0;i<=count;i++)
       {
           rot[i][0]=n[i][0];
           rot[i][1]=n[i][1];
       }
       if(flag==6)
       {
           for(i=0;i<=count;i++)
           {
               t[i][0]=rot[i][0]-x;
               t[i][1]=rot[i][1]-y;
           }
           for(i=0;i<=count;i++)
           {
               rot[i][0]=t[i][0]*qCos(k)-t[i][1]*qSin(k);
               rot[i][1]=t[i][0]*qSin(k)+t[i][1]*qCos(k);
           }
           for(i=0;i<=count;i++)
           {
               rot[i][0]=rot[i][0]+x;
               rot[i][1]=rot[i][1]+y;
           }
       }
       else
       {
       for(i=0;i<=count;i++)
       {
           rot[i][0]=n[i][0]*qCos(k)-n[i][1]*qSin(k);
           rot[i][1]=n[i][0]*qSin(k)+n[i][1]*qCos(k);
       }
       }
       for(i=0;i<=count;i++)
       {
           rot[i][0]=width/2+rot[i][0]*50;
           rot[i][1]=height/2-rot[i][1]*50;
       }
       for(i=0;i<count;i++)
           q.drawLine(rot[i][0],rot[i][1],rot[i+1][0],rot[i+1][1]);

   }
   else if(flag==7 || flag==8)
   {
       float k=ui->textEdit->toPlainText().toInt();
       k=k*3.14/180;
       x=ui->textEdit_4->toPlainText().toFloat();
       y=ui->textEdit_5->toPlainText().toFloat();
       for(i=0;i<=count;i++)
       {
           rot[i][0]=n[i][0];
           rot[i][1]=n[i][1];
       }
       if(flag==8)
       {
           for(i=0;i<=count;i++)
           {
               t[i][0]=rot[i][0]-x;
               t[i][1]=rot[i][1]-y;
           }
           for(i=0;i<=count;i++)
           {
               rot[i][0]=t[i][0]*qCos(k)+t[i][1]*qSin(k);
               rot[i][1]=(-1)*t[i][0]*qSin(k)+t[i][1]*qCos(k);
           }
           for(i=0;i<=count;i++)
           {
               rot[i][0]=rot[i][0]+x;
               rot[i][1]=rot[i][1]+y;
           }

       }
       else
       {
       for(i=0;i<=count;i++)
       {
           rot[i][0]=n[i][0]*qCos(k)+n[i][1]*qSin(k);
           rot[i][1]=(-1)*n[i][0]*qSin(k)+n[i][1]*qCos(k);
       }
       }
       for(i=0;i<=count;i++)
       {
           rot[i][0]=width/2+rot[i][0]*50;
           rot[i][1]=height/2-rot[i][1]*50;
       }
       for(i=0;i<count;i++)
           q.drawLine(rot[i][0],rot[i][1],rot[i+1][0],rot[i+1][1]);

   }
}

void transform::on_pushButton_clicked()
{
    flag=1;
    ui->label->setText("Choose Transformation :");
    ui->label_2->setVisible(0);
        ui->label_3->setVisible(0);
        ui->label_4->setVisible(0);
        ui->label_5->setVisible(0);
        ui->pushButton->setVisible(0);
        ui->comboBox_2->setVisible(1);
                ui->comboBox_3->setVisible(1);
                ui->pushButton_2->setVisible(1);
    update();
}

void transform::on_pushButton_2_clicked()
{
    ui->label_angle->setVisible(0);
    ui->textEdit->setVisible(0);
    ui->label_6->setVisible(0);
    ui->label_7->setVisible(0);
    ui->textEdit_4->setVisible(0);
    ui->label_8->setVisible(0);
    ui->textEdit_5->setVisible(0);
    update();
}

void transform ::mousePressEvent(QMouseEvent *m)
{
    if(flag==0)
    {
    p[count][0]=m->x();
    p[count][1]=m->y();
    n[count][0]=(width/2-p[count][0])*-1/50;
    n[count][1]=(height/2-p[count][1])/50;
    ui->label_3->setText(QString::number(n[count][0]));
    ui->label_5->setText(QString::number(n[count][1]));
    count++;
    p[count][0]=p[0][0];
    p[count][1]=p[0][1];
    }
}

void transform::on_comboBox_3_activated(int index)
{
    ui->label_angle->setVisible(1);
    ui->textEdit->setVisible(1);
    if(index==0)
    {
        flag=7;
    }
    if(index==1)
    {
        flag=5;
    }
    if(index==2)
    {
        flag=8;
        ui->label_6->setVisible(1);
        ui->label_7->setVisible(1);
        ui->textEdit_4->setVisible(1);
        ui->label_8->setVisible(1);
        ui->textEdit_5->setVisible(1);
    }
    if(index==3)
    {
        flag=6;
        ui->label_6->setVisible(1);
        ui->label_7->setVisible(1);
        ui->textEdit_4->setVisible(1);
        ui->label_8->setVisible(1);
        ui->textEdit_5->setVisible(1);
    }
}

void transform::on_comboBox_2_activated(int index)
{
    if(index==0)
    {
        flag=2;
    }
    if(index==1)
    {
        flag=3;
    }
    if(index==2)
    {
        flag=4;
    }
}
