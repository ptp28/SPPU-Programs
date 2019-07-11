#include<iostream>
#include<stack>
using namespace std;
int main()
{
	stack<int>s1,s2,s3;
	int i,x;
	
		t1:		
		cout<<"\n*** Enter bits (0/1) or enter any other number to continue ***";
		cout<<"\nEnter First Binary Number : ";
		for(;;)
		{		
			cin>>x;	
			if(x==0 || x==1)	
			{
				s1.push(x);
			}
			else 
			{
				if(!s1.empty())
					break;
				else
				{
					cout<<"\n!!! The stack is empty !!!";
					goto t1;
				}
			}
		}
		t2:
		cout<<"\n*** Enter bits (0/1) or enter any other number to continue ***";
		cout<<"\nEnter Second Binary Number : ";
		for(;;)
		{
			cin>>x;		
			if(x==0 || x==1)	
			{
				s2.push(x);
			}
			else 
			{
				if(!s2.empty())
					break;
				else
				{
					cout<<"\n!!! The stack is empty !!!";
					goto t2;
				}
			}
		}
		
		int sum=0,carry=0;
		int b1,b2;
		while(!s1.empty() || !s2.empty())
		{
			if(!s1.empty())
			{			
				b1=s1.top();
				s1.pop();
			}
			else
				b1=0;
			if(!s2.empty())
			{
				b2=s2.top();
				s2.pop();
			}
			else
				b2=0;
			sum=b1+b2+carry;
			carry=sum/2;
			sum=sum%2;
			s3.push(sum);
		}
		if(carry==1)
		{
			s3.push(carry);
		}

		cout<<"\nThe Addition is: ";
		while(!s3.empty())
		{
			cout<<s3.top()<<" ";
			s3.pop();
		}
		cout<<endl;
}
