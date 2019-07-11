#include<graphics.h>
#include<iostream>

using namespace std;

class pixel
{
	public:
	void plot(int X1,int Y1,int x,int y)
	{
		putpixel(X1+x,Y1+y,WHITE);
		putpixel(X1-x,Y1+y,WHITE);
		putpixel(X1+x,Y1-y,WHITE);
		putpixel(X1-x,Y1-y,WHITE);
		putpixel(X1+y,Y1+x,WHITE);
		putpixel(X1+y,Y1-x,WHITE);
		putpixel(X1-y,Y1+x,WHITE);
		putpixel(X1-y,Y1-x,WHITE);
		delay(20);
	}

};

class drawcircle:public pixel
{

	public:
		
		void dcircle(int xc,int yc,int r)
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
		

};

int main()
{
	int xc,yc,r,ch;
	int a=DETECT,b;
	cout<<"\n\nEnter the co-ordinates of center of the circle\nX : ";
		cin>>xc;
		cout<<"Y : ";
		cin>>yc;
		cout<<"\nEnter radius : ";
		cin>>r;
	drawcircle c;
	do
	{
		
		cout<<"Menu \n1. Circle\n2. Symbol- Audi\n3. Symbol- Olympics\n4. Exit\nEnter your choice : ";
		cin>>ch;
		int t=3*r/2;
		
		switch(ch)
		{
			case 1:initgraph(&a,&b,NULL);
				c.dcircle(xc,yc,r);
				delay(2000);
				closegraph();
					break;
			case 2:initgraph(&a,&b,NULL);
					c.dcircle(xc,yc,r);
					xc=xc+t;
					c.dcircle(xc,yc,r);
					xc=xc+t;
					c.dcircle(xc,yc,r);
					xc=xc+t;
					c.dcircle(xc,yc,r);
					delay(2000);
				closegraph();
					break;
			case 3:
				initgraph(&a,&b,NULL);
				c.dcircle(xc,yc,r);
					xc=xc+t;
					c.dcircle(xc,yc,r);
					xc=xc+t;
					c.dcircle(xc,yc,r);
					xc=xc-2*t+r;
					yc=yc+t;
					c.dcircle(xc,yc,r);
					xc=xc+t;
					c.dcircle(xc,yc,r);
					delay(2000);
				closegraph();
					break;
			case 4:cout<<"\nExitting...";
					break;
			default:cout<<"\n!!! Wrong choice entered !!!"<<endl;
					break;
		}
	}while(ch!=3);
}
