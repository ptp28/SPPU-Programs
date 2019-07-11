 #include <iostream>
using namespace std;
class Complex
{
	int real,imag;
	public:
    Complex()
    {
        real=0;
        imag=0;
    }
	Complex(int x,int y)
    {
        real=x;
        imag=y;
    }
	Complex operator +(Complex c)
	{
		 Complex cc;
		 cc.real=real+c.real;
		 cc.imag=imag+c.imag;
		 return cc;
	}
    Complex operator -(Complex c)
    {
        Complex cc;
        cc.real=real-c.real;
        cc.imag=imag-c.imag;
        return cc;
    }
	friend Complex operator *(Complex c,Complex c1)
	{
		 Complex cc;
		 cc.real=(c.real*c1.real)+(c.imag*c1.imag*-1);
		 cc.imag=(c.real*c1.imag)+(c.imag*c1.real);
		 return cc;
	}
	friend ostream & operator<<(ostream &o ,Complex &c)
    {
       cout<<"\nThe complex number is = ("<<c.real<<") + i("<<c.imag<<")";
       return o;
    }
    friend istream & operator>>(istream &i,Complex &c)
    {
       cout<<"\nEnter the real part : ";
    	i>>c.real;
    	cout<<"\nEnter the imaginary part : ";
    	i>>c.imag;
    	return i;
    }
    Complex(Complex & c)
    {
    	real=c.real;
    	imag=c.imag;
    }
};
int main()
{
	int choice,x,y;
	cout<<"\nEnter the first complex number :";
    cout<<"\nEnter the real part : ";
    cin>>x;
    cout<<"\nEnter the imaginary part : ";
    cin>>y;
    Complex c1(x,y),c2,c3(c2);
	cout<<c1;
	cout<<"\n\nEnter the second complex number :";
    	cin>>c2;
    	cout<<c2;
	do
	{
	cout<<"\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Exit\nEnter your choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1 :c3=c1+c2;
		cout<<"\n\n\nThe addition of the two entered complex numbers is : ";
		cout<<c3;
		break;
		case 2 :c3=c1-c2;
		cout<<"\n\n\nThe Subtraction of the two entered complex numbers is : ";
		cout<<c3;
            break;
        case 3 :c3=c1*c2;
            cout<<"\n\n\nThe Multiplication of the two entered complex numbers is : ";
            cout<<c3;
            break;
		case 4 :cout<<"\nExitting...\n";
        break;
		default:cout<<"\nWrong choice entered...try again...";
		break;
	}
	}while(choice!=4);
}	
