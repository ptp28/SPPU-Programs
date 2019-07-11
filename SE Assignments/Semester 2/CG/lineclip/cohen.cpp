#include "cohen.h"
#include "ui_cohen.h"
#include<iostream>
using namespace std;
cohen::cohen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cohen)
{
    ui->setupUi(this);
    count = 0;
    for(int i = 0; i<20; i++)
        d[i] = 1;
}

cohen::~cohen()
{
    delete ui;
}


void cohen :: paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    if (flag == 3)
    {
        clip();
        cout<<"cliiip\n";
    }
        if (flag>0 && flag <4)
        p.drawRect(x[0], y[0], x[1]-x[0], y[1]-y[0]);
//        p.drawRect(100, 100, 100, 100);
    if (flag == 2 || flag==3)
        for(int c= 4; c<=count ; c+=2)
            if(d[c-1]==1)
                p.drawLine(x[c-1], y[c-1], x[c-2], y[c-2]);
    flag = 0;


}

void cohen :: mousePressEvent(QMouseEvent *m)
{
//    x[count] = m->globalX();
//    y[count] = m->globalY();
    if(count<18)
    {
        x[count] = m->x();
        y[count] = m->y();

        ui->x->setText(QString::number(x[count]));
        ui->y->setText(QString::number(y[count]));

        count++;

        if(count == 2)
        {
            flag = 1;
            update();
        }
        else if(count>2 && count %2 == 0)
        {
            flag = 2;
            update();
        }
    }
}

void cohen :: clip()
{
    opcode();
    cout<<"qqq\n";
    for(int i =2; i< 4; i++)
    {
        for(int j=0; j<4; j++)
        cout<<code[i][j]<<"  ";
        cout<<"zzz"<<endl;
    }

    int p=0;
    for(int c=2; c<count-1; c+=2)
    {
        int temp = 0;
        for(int j=0; j<4; j++)
            if(code[c][j] == code[c+1][j])
                if(code[c+1][j]==0)
                    temp++;
        if(temp != 4)
        {
            int temp1 = 0;
            for(int j=0; j<4; j++)
                if((code[c+1][j]&&code[c][j]) == 0)
                    temp1++;
           // ui->x->setText(QString::number(temp));
            cout<<"temp1   "<<temp1<<endl;
            if(temp1 != 4)
            {
                d[c+1] = d[c] = 0;
                p++;
                cout<<"ppp  "<<p<<endl;
            }
            else
            {
                int i;
                for(i=3; i>=0; i--)
                //for(i=0; i<=3; i++)
                {
                    cout<<"in loop  "<<i<<endl;
                    if(code[c][i]==0 && code[c+1][i]==0)
                    {
                        cout<<"------------------\n";
                        cout<<code[c][i]<<"    "<<code[c+1][i]<<endl;
                        continue;
                    }
                    else if(code[c+1][i]==1 || code[c][i]==1)
                {
                    switch(i)
                    {
                    case 3:
                        {
                            if(x[c]<x[0] && x[c+1]<x[0])
                                    d[c]=0;
                            else
                            {
                            ix = x[0];
                            iy = y[c] + (ix-x[c])*(y[c]-y[c+1])/(x[c]-x[c+1]);
                           // cout<<"aaaaa "<<ix<<"  "<<iy<<endl;
                            if(x[c]>x[c+1])
                            {
                                y[c+1] = iy;
                                x[c+1] = ix;
                             }
                                else
                            {
                                y[c] = iy;
                                x[c] = ix;
                             }
                            cout<<"3-";
                            opcode();
                        }}
                    break;
                    case 2:
                        {
                                    if(x[c]>x[1] && x[c+1]>x[1])
                                            d[c]=0;
                                    else
                                    {
                            ix = x[1];
                            iy = y[c] + (ix-x[c])*(y[c]-y[c+1])/(x[c]-x[c+1]);
                            if(x[c]<x[c+1])
                            {
                                y[c+1] = iy;
                                x[c+1] = ix;
                             }
                                else
                            {
                                y[c] = iy;
                                x[c] = ix;
                             }
                            cout<<"2-";
                            opcode();
                        }}
                    break;
                    case 1:
                        { if(y[c]>y[1] && y[c+1]>y[1])
                            d[c]=0;
                    else
                    {
                            iy = y[1];
                            ix = x[c] + (iy-y[c])*(x[c]-x[c+1])/(y[c]-y[c+1]);
                            if(y[c]<y[c+1])
                            {
                                x[c+1] = ix;
                                y[c+1] = iy;
                             }
                                else
                            {
                                y[c] = iy;
                                x[c] = ix;
                             }
                            cout<<"1-";
                            opcode();
                    }}
                    break;
                    case 0:
                        {

                        if(y[c]<y[0] && y[c+1]<y[0])
                            d[c]=0;
                    else
                    {
                            iy = y[0];
                            ix = x[c] + (iy-y[c])*(x[c]-x[c+1])/(y[c]-y[c+1]);
                            if(y[c]>y[c+1])
                            {
                                x[c+1] = ix;
                                y[c+1] = iy;
                             }
                                else
                            {
                                y[c] = iy;
                                x[c] = ix;
                             }
                            cout<<"0-";
                            opcode();
                    }}
                    break;

                    }

                cout<<"qqqqqqqqqqqqqqqqqqqqqq\n";

                }



        }
    }
}
}
    ui->x->setText(QString::number(p));

    for (int i = 2; i< count; ++i)
    {
        for (int j = 0; j< 4; ++j)
        {
          //      ui->listWidget->addItem(QString::number(code[i][j]));
      // ui->listWidget->addItem(number(code[i][j]));
     //   ui->listWidget->addItem(QString::QChar(' '));
        }
    }
}
void cohen :: opcode()
{
    for(int c=4 ; c<=count+1; c++)
    {
        if(y[c-2]<y[0])
            code[c-2][0] = 1;
        else
            code[c-2][0] = 0;
        if(y[c-2]>y[1])
            code[c-2][1] = 1;
        else
            code[c-2][1] = 0;
        if(x[c-2]>x[1])
            code[c-2][2] = 1;
        else
            code[c-2][2] = 0;
        if(x[c-2]<x[0])
            code[c-2][3] = 1;
        else
            code[c-2][3] = 0;
    }
//        ui->a1->setText(QString::number(code[c-2][0]));
//        ui->a2->setText(QString::number(code[c-2][1]));
//        ui->a3->setText(QString::number(code[c-2][2]));
//        ui->a4->setText(QString::number(code[c-2][3]));


}

void cohen::on_clip_clicked()
{
    flag = 3;
    update();
}
