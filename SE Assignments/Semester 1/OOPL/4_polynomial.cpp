#include <iostream>
#include<math.h>
using namespace std;
class Pol
{
	int a,b,c,x1,x2,sq;
	float ans;
	public:
    Pol()
    {
        a=b=c=x1=x2=0;
    }
    Pol(int x,int y,int z)
    {
    	a=x;
    	b=y;
    	c=z;
    }
	Pol operator +(Pol p)
	{
		 Pol pp;
		 pp.a=a+p.a;
		 pp.b=b+p.b;
		 pp.c=c+p.c;
		 return pp;
	}
	float operator %(int x)
	{
		ans=(a*x*x)+(b*x)+(c);
		return ans;
	}
	void operator !()
	{
		sq=(b*b)-(4*a*c);
		if(sq>=0)
		{
			x1=(-b+sqrt(sq))/(2*a);
			x2=(-b-sqrt(sq))/(2*a);
			cout<<"\nThe roots are :\n"<<x1<<endl<<x2<<endl;
		}
		else
			cout<<"\nRoots are imaginary";
	}
    friend ostream & operator<<(ostream &o ,Pol &p)
    {
        o<<"\nThe polynomial is = "<<p.a<<"x\u00b2 + "<<p.b<<"x + "<<p.c<<endl;
        return o;
    }
    friend istream & operator>>(istream &i,Pol &p)
    {
        cout<<"\nEnter a : ";
        i>>p.a;
        cout<<"\nEnter b : ";
        i>>p.b;
        cout<<"\nEnter c : ";
        i>>p.c;
        return i;
    }
};
int main()
{
	int choice,x,a,b,c;
	cout<<"\nEnter the first polynomial :";
	cout<<"\nEnter a : ";
        cin>>a;
        cout<<"\nEnter b : ";
        cin>>b;
        cout<<"\nEnter c : ";
        cin>>c;
        Pol p1(a,b,c),p2,p3;
    cout<<p1;
    cout<<"\n\nEnter the second polynomial :";
    cin>>p2;
    cout<<p2;
	do
	{
        cout<<"\n\n*************\n\n";
	cout<<"\n1.Addition\n2.Evaluation\n3.Get Roots\n4.Exit\nEnter your choice : ";
	cin>>choice;
        cout<<"\n\n*************\n\n";
	switch(choice)
	{
		case 1 :p3=p1+p2;
		cout<<"\nThe addition of the two entered polynomials is : ";
        cout<<p3;
		break;
		case 2 : cout<<"\nEnter the value of x = ";
		cin>>x;
		cout<<"\nFor polynomial 1 : "<<p1%x;
		cout<<"\nFor polynomial 2 : "<<p2%x;
		break;
		case 3 :cout<<"For polynomial 1 :";
		!p1;
		cout<<"For polynomial 2 :";
		!p2;
		break;
        case 4 :cout<<"\nExitting...\n";
        break;
		default:cout<<"\nWrong choice entered...try again...";
	}
	}while(choice!=4);
}
