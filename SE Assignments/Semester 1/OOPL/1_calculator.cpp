#include<iostream>
using namespace std;
class calculator
 {
   private:
   int num1,num2;
   char op;
   float ans;
   void getexp()
     {
      cout<<"\nEnter any expression :";
      cin>>num1>>op>>num2;
     }
   void add()
     {
       ans=num1+num2;
     }
   void subtract()
     {
      ans=num1-num2;
     }
   void multiply()
     {
      ans=num1*num2;
     }
   void divide()
     {
      ans=(float)num1/num2;
     }
     void mod()
     {
      ans=num1%num2;
     }
          void display()
     {
     	cout<<num1<<op<<num2<<" = "<<ans;
     }
   public:
     void operations()
     {
     	getexp();
     	switch(op)
     	{
     		case '+':add();
     		break;
     		case '-':subtract();
     		break;
     		case '*':multiply();
     		break;
     		case '/':if(num2==0)
			{
				cout<<"\n!!! Divide by zero error !!!";
			}
			divide();
     		break;
     		case '%':mod();
     		break;
     		default:cout<<"\n!!! Wrong choice entered !!!";
     		break;
     	}
     	display();
     }
 };
 int main()
 {
  char choice;
  calculator c;
  do
  {
  	c.operations();
  	cout<<"\nDo you want to continue (Y/N) : ";
  	cin>>choice;	
  }while(choice=='Y'||choice=='y');
  cout<<"\nExittng...\n";
  return 0;
 }
 
 
 
 
 
 
 
 
