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
    ui->comboBox->setVisible(0);
    ui->radioButton->setVisible(0);
    ui->radioButton_2->setVisible(0);
    ui->textEdit->setVisible(0);
    ui->textEdit_2->setVisible(0);
    ui->pushButton_2->setVisible(0);
    ui->label_angle->setVisible(0);
    ui->label_Sx->setVisible(0);
    ui->label_Sy->setVisible(0);
    ui->label_Tx->setVisible(0);
    ui->label_Ty->setVisible(0);
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
        QScreen *screen=QGuiApplication::primaryScreen();       //app ke co ordi gets stored in *screen
        QRect screenGeometry=screen->geometry();        //app is rectangular. whatever geom we take from above inst,gets stored
        //in screen geometry
        height=screenGeometry.height();     //height of sg is stored in var height
        width=screenGeometry.width();       //  "
        q.drawLine(width/2,0,width/2,height);    //to get x-axis
                    //(x1,    y1,x2,   y2)
        q.drawLine(0,height/2,width,height/2);      //to get y-axis
        for(i=width/2;i<width;i=i+50)
        {
        sprintf(buf,"%d",k);                //sprintf will convert k to char & store it in buf
        q.drawText(i,height/2+15,buf);          //plot the origin & buff is number to be plotted
        k++;                //k=1
        }           //i will go ahead by 50 pixels to right
        k=-1;
        for(i=((width/2)-50);i>0;i=i-50)    //negative xaxis
        {
        sprintf(buf,"%d",k);
        q.drawText(i,height/2+15,buf);
        k--;
        }
        k=1;
        for(i=height/2-50;i>0;i=i-50)               //k is already 1 coz we hv plotted 0
        {                                                    //positive yaxis
            sprintf(buf,"%d",k);
            q.drawText(width/2-15,i,buf);
            k++;
        }
        k=-1;
        for(i=height/2+50;i<height;i=i+50)              //neg yaxis
        {
            sprintf(buf,"%d",k);
            q.drawText(width/2-15,i,buf);
            k--;
        }
    }

   if(flag>=1)
   {
    for(i=0;i<count;i++)
    {
        q.setPen(QPen(Qt::red,2));
        q.drawLine(p[i][0],p[i][1],p[i+1][0],p[i+1][1]);    //draw original polygon
    }
   }
   q.setPen(QPen(Qt::blue,2));
   if(flag==2)
   {
       x=ui->textEdit->toPlainText().toInt();           //Accept Tx
       y=ui->textEdit_2->toPlainText().toInt();         //Accept Ty
       x=x*50;      //distance between two graph points is 50 pixels
       y=y*-50;     //
       for(i=0;i<=count;i++)        //Copying clicked points stored in p into t
       {
           t[i][0]=p[i][0];
           t[i][1]=p[i][1];
       }
       for(i=0;i<=count;i++)        // Adding Tx and Ty
       {
                t[i][0]=t[i][0]+x;
                t[i][1]=t[i][1]+y;
       }
       for(i=0;i<count;i++)
           q.drawLine(t[i][0],t[i][1],t[i+1][0],t[i+1][1]);  //Draw polygon after translation
   }
   if(flag==3)          //scaling
   {
    x=1;
    y=1;
    xt=ui->textEdit->toPlainText().toInt();
    yt=ui->textEdit_2->toPlainText().toInt();
    yt=yt*-1;
    for(i=0;i<=count;i++)
    {
        sca[i][0]=n[i][0];
        sca[i][1]=n[i][1];
    }
    for(i=0;i<=count;i++)
    {
        sca[i][0]=sca[i][0]*xt;
        sca[i][1]=sca[i][1]*yt;
    }
    for(i=0;i<=count;i++)
    {
        sca[i][0]=width/2+sca[i][0]*50;
        sca[i][1]=height/2-sca[i][1]*50;
    }


    for(i=0;i<count;i++)
        q.drawLine(sca[i][0],sca[i][1],sca[i+1][0],sca[i+1][1]);        //draw poly after scaling
   }
   if(flag==5)      //for clockwise rot
   {
       float k=ui->textEdit->toPlainText().toInt();
       k=k*3.14/180;
       for(i=0;i<=count;i++)
       {
           rot[i][0]=n[i][0];
           rot[i][1]=n[i][1];
       }
       for(i=0;i<=count;i++)
       {
           rot[i][0]=n[i][0]*qCos(k)-n[i][1]*qSin(k);
           rot[i][1]=n[i][0]*qSin(k)+n[i][1]*qCos(k);
       }
       for(i=0;i<=count;i++)
       {
           rot[i][0]=width/2+rot[i][0]*50;
           rot[i][1]=height/2-rot[i][1]*50;
       }
       for(i=0;i<count;i++)
           q.drawLine(rot[i][0],rot[i][1],rot[i+1][0],rot[i+1][1]);

   }
   if(flag==7)      //anticlockwise rot
   {
       float k=ui->textEdit->toPlainText().toInt();
       k=k*3.14/180;
       for(i=0;i<=count;i++)
       {
           rot[i][0]=n[i][0];
           rot[i][1]=n[i][1];
       }
       for(i=0;i<=count;i++)
       {
           rot[i][0]=n[i][0]*qCos(k)+n[i][1]*qSin(k);
           rot[i][1]=(-1)*n[i][0]*qSin(k)+n[i][1]*qCos(k);
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

void transform::on_comboBox_activated(int index)
{
    if(index==0)
    {
        ui->radioButton->setVisible(1);
        ui->radioButton_2->setVisible(1);
    }
    else if(index==1)
    {
        flag=3;
        ui->textEdit->setVisible(1);
        ui->textEdit_2->setVisible(1);
        ui->pushButton_2->setVisible(1);
        ui->label_Sx->setVisible(1);
        ui->label_Sy->setVisible(1);

    }
    else if(index==2)
    {
        flag=2;
        ui->textEdit->setVisible(1);
        ui->textEdit_2->setVisible(1);
        ui->pushButton_2->setVisible(1);
        ui->label_Tx->setVisible(1);
        ui->label_Ty->setVisible(1);
    }
}

void transform::on_radioButton_clicked()
{
    flag=7;
    ui->textEdit->setVisible(1);
    ui->pushButton_2->setVisible(1);
    ui->label_angle->setVisible(1);
}

void transform::on_radioButton_2_clicked()
{
    flag=5;
    cout<<flag;
    ui->textEdit->setVisible(1);
    ui->pushButton_2->setVisible(1);
    ui->label_angle->setVisible(1);
}

void transform::on_pushButton_clicked()
{
    flag=1;
    ui->comboBox->setVisible(1);
    ui->pushButton_2->setVisible(0);
    ui->label->setText("Choose a Transformation :");
    ui->label_2->setVisible(0);
    ui->label_3->setVisible(0);
    ui->label_4->setVisible(0);
    ui->label_5->setVisible(0);
    ui->pushButton->setVisible(0);
    update();
}

void transform::on_pushButton_2_clicked()
{
    ui->textEdit->setVisible(0);
    ui->textEdit_2->setVisible(0);
    ui->radioButton->setVisible(0);
    ui->radioButton_2->setVisible(0);
    ui->label_angle->setVisible(0);
    ui->label_Sx->setVisible(0);
    ui->label_Sy->setVisible(0);
    ui->label_Tx->setVisible(0);
    ui->label_Ty->setVisible(0);
    update();
}

void transform ::mousePressEvent(QMouseEvent *m)
{
    if(flag==0)
    {
    p[count][0]=m->x();
    p[count][1]=m->y();
    n[count][0]=(width/2-p[count][0])*-1/50;        //converting actual values to altered values
    n[count][1]=(height/2-p[count][1])/50;
    ui->label_3->setText(QString::number(n[count][0]));
    ui->label_5->setText(QString::number(n[count][1]));
    count++;
    p[count][0]=p[0][0];
    p[count][1]=p[0][1];
    }
}
