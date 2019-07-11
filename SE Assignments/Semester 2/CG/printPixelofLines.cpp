#include "iostream"
#include "math.h"
#include "stdio.h"
using namespace std;

class plotpixel
{
  int x,y;
         
};

class myline:protected plotpixel
{
 int p,q,r,f,d;

 public:
         void draw(int,int,int,int);
         void draw(int,int,int,int,int);
         int sign(int);
         myline()
         {
          d=0;
         }

         void plot(int x, int y)
           {
            //putpixel(x,y,"RED");
            cout<<"X: "<<x<<" ; Y: "<<y<<endl;
           }
};



 void myline :: draw(int x1, int y1, int x2, int y2)
 {
  int dx=abs(x2-x1);
  int dy=abs(y2-y1);
  //cout<<"dx is:"<<dx<<endl;
  //cout<<"dy is:"<<dy<<endl;
  int i,length;
  float xinc,yinc,x,y;
  if(abs(dx)>=abs(dy))  //To decide the value of 'length'...
   {
    length=dx;
   }
  else
  {
   length=dy;
  }
  xinc= (float) (dx/length);
  yinc= (float) (dy/length);
  x=x1;
  y=y1;
  plot(x,y); //First point is plotted...
  for(i=0;i<length;i++)
   {
    x=x+xinc;
    y=y+yinc;
    x1=x+0.5; //Accuracy increased...
    y1=y+0.5; //Accuracy increased...
    plot(x1,y1);         //Remaining points are plotted
   }
   //delay(8000);
 }
  

 void myline :: draw(int x1, int y1, int x2, int y2, int id)
 {
   int xinc,yinc,i,flag=0;
   id=d;
   int dx,dy,length,temp;
   
   dx=abs(x2-x1);
   //cout<<"dx is:"<<dx<<endl;
   dy=abs(y2-y1);
   //cout<<"dy is:"<dy<<endl;
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
  //delay(8000);
 }

int myline::sign(int r)
{
    if(r<0)
        return -1;
    else if(r==0)
        return 0;
    else
        return 1;
}

int main()
{
 int gd,z,ch;
 int x1,y1,x2,y2,de;
 //gd=DETECT;
 //initgraph(&gd, &z, NULL);
  cout<<"Enter the first pair of co-ordinates of line"<<endl;
  cin>>x1>>y1;
  cout<<"Enter the second pair of co-ordinates of line"<<endl;
  cin>>x2>>y2;
  myline m;
  do
  {
   cout<<"Which Algorithm you want to use"<<endl;
   cout<<"1. DDA Algorithm"<<endl<<"2. Bresenham Algorithm"<<endl;
   cout<<"Enter your choice"<<endl;
   cin>>ch;
   switch(ch)
   {
    case 1:m.draw(x1,y1,x2,y2);
           break;
    case 2: m.draw(x1,y1,x2,y2,de);
            break;
    case 3: cout<<"THANK YOU"<<endl;
   }
  }while(ch!=3);
  
 return 0;
}




    
