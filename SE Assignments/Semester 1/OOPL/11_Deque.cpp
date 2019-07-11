#include<iostream>
#include<stdlib.h>
#include<deque>
using namespace std;

class demostack
{
	deque <int> l1;
	
	public:
	
	void pushb(int v)
	{
		l1.push_back(v);	
	}
	
	void pushf(int v)
	{
		l1.push_front(v);	
	}
	
	void display()
	{
		deque <int> :: iterator i1;
		for(i1 = l1.begin(); i1!=l1.end(); i1++)
		cout<<*i1<<" ";
		cout<<endl;
	}
	
	int isempty()
	{
		if(l1.empty() == 1)
		{
			return 1;
		}
		else 
		return 0;
	}
	
	int popb()
	{
		int v;
		v = l1.back();
		l1.pop_back();
		return v;
	}
	
	int popf()
	{
		int v;
		v = l1.front();
		l1.pop_front();
		return v;
	}	
};

int main()
{
	demostack d;
	int i,n,x,choice;
	
	do
	{
		cout<<"\n1. Push an element at the back\n2. Push an element at the front\n3. Pop an element from the back\n4. Pop an element from the front\n5. Display the Stack\n6. Exit\nChoice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1: cout<<"\nEnter how many elements do you want to push at the back\nInput: ";
					cin>>n;
					
					for(i=0;i<n;i++)
					{
						cout<<"\nEnter number "<<i+1<<": ";
						cin>>x;
						d.pushb(x);
					}
					break;
					
			case 2: cout<<"\nEnter how many elements do you want to push at the front\nInput: ";
					cin>>n;
					
					for(i=0;i<n;i++)
					{
						cout<<"\nEnter number "<<i+1<<": ";
						cin>>x;
						d.pushf(x);
					}
					break;
					
			case 3: if(!d.isempty())
					{
						cout<<"\nPopped Number is: "<<d.popb();
						cout<<endl;
					}
					else
					{
						cout<<"\nQueue is empty";
						cout<<endl;
					}
					break;
					
			case 4: if(!d.isempty())
					{
						cout<<"\nPopped Number is: "<<d.popf();
						cout<<endl;
					}
					else
					{
						cout<<"\nQueue is empty";
						cout<<endl;
					}
					break;
							
			case 5: if(!d.isempty())
					{
						cout<<"\nThe Queue is:";
						d.display();
						cout<<endl;
					}
					
					else
					{
						cout<<"\nQueue is Empty";
						cout<<endl;
					}
					break;
					
			case 6: exit(0);
		}
		
	}while(1);
	
	return 0;
}
