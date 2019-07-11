#include "mypoly.h"
#include "ui_mypoly.h"

mypoly::mypoly(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mypoly)
{
        flag=0;
        count=0;
        colour=0;
    ui->setupUi(this);
}

mypoly::~mypoly()
{
    delete ui;
}
void mypoly::mousePressEvent(QMouseEvent *m)
{

   // while(count<5)
    {
     x[count]=m->x();
     y[count]=m->y();
   //  String s1;
    // s1=x[count];
     ui->textEdit->setText(QString::number(x[count]));
     ui->textEdit_2->setText(QString::number(y[count]));
     count++;
    }
    x[count]=x[0];
    y[count]=y[0];
}

void mypoly:: paintEvent(QPaintEvent *event)
    {
        QPainter p(this);
        if(flag==1)
        {
           for(int i=0;i<5;i++)
               p.drawLine(x[i],y[i],x[i+1],y[i+1]);
        }
        if(flag==2)
        {
            myfunct();

        }

 }

void mypoly::myfunct()
{
    QPainter qp(this);

    if(colour==1)
        qp.setPen(QPen(Qt::red));
    else if(colour==2)
        qp.setPen(QPen(Qt::blue));
    else if(colour==3)
        qp.setPen(QPen(Qt::yellow));


    int ymax=y[0],ymin=y[0],y1,i,cnt;
            double dx,dy,m[count],a[count],temp;

            for(i=0;i<count;i++)
            {
                if(y[i]>=ymax)
                {
                    ymax=y[i];
                }
                if(y[i]<=ymin)
                {
                    ymin=y[i];
                }
                dx=x[(i+1)]-x[i];
                dy=y[(i+1)]-y[i];

                if(dx==0)
                {
                    m[i]=0;
                }
                if(dy==0)
                {
                    m[i]=1;
                }
                if(dx!=0 && dy!=0)
                {
                    m[i]=(dx/dy);
                }
            }


            for(y1=ymax;y1>=(ymin+1);y1--)
            {
                cnt=0;
                for(i=0;i<count;i++)
                {
                    if((y[i]>y1 && y[i+1]<=y1) ||(y[i]<=y1 && y[i+1]>y1))
                    {
                        a[cnt]=x[i]+(m[i]*(y1-y[i]));
                        cnt++;
                    }
                }
                for(int k=0;k<(cnt-1);k++)
                {
                    for(i=0;i<(cnt-1);i++)
                    {
                        if(a[i]>a[i+1])
                        {
                            temp=a[i];
                            a[i]=a[i+1];
                            a[i+1]=temp;
                        }
                    }
                }
                for(i=0;i<(cnt-1);i=i+2)
                {
                    qp.drawLine(a[i],y1,(a[i+1]+1),y1);
                }
            }

}

void mypoly::on_pushButton_clicked()
{
    flag=1;
    update();
}

void mypoly::on_pushButton_2_clicked()
{
    flag=2;
    update();
}

void mypoly::on_radioButton_clicked()
{
    colour=1;
}

void mypoly::on_radioButton_2_clicked()
{
    colour=2;
}

void mypoly::on_radioButton_3_clicked()
{
    colour=3;
}
