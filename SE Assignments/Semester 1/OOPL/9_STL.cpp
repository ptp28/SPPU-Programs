#include <iostream>
#include <list>
using namespace std;
class Stack
{
    list <int> l1;
    int v;
    public:
    void push(int v)
	{
   		l1.push_back(v);
   	}
    void show()
	{
		cout<<"\nThe elements in the stack are :\n";
		list <int>::iterator i1;
		for(i1=l1.begin();i1!=l1.end();i1++)
   			cout<<*i1<<endl;
   		cout<<endl;
	}	   
	int isempty()
	{
		if(l1.empty()==1)
   			return 0;
   		else
   			return 1;
	}
    int pop()
	{
   		v=l1.back();
   		l1.pop_back();
   		return v;
	}
};
class Queue
{
	list <int> l1;
	int v;
    public:
    void push(int v)
	{
	   	l1.push_back(v);
	}
    void show()
	{
		cout<<"\nThe elements in the queue are :\n";
		list <int>::iterator i1;
		for(i1=l1.begin();i1!=l1.end();i1++)
    			cout<<*i1<<endl;
    		cout<<endl;
	}	  
    int isempty()
	{
		if(l1.empty()==1)
   			return 0;
   		else
   			return 1;
	}
    int pop()
	{
   		v=l1.front();
   		l1.pop_front();
   		return v;	
	}
};
int main()
{
    Stack s;
	Queue q;
	int ch,n,x,m,i;
	cout<<"\n************************************************\n\n";     	
	do
       	{
        	cout<<"\n1.Push the Elements in stack"<<endl<<"2.Pop the Elements of stack"<<endl<<"3.Display the Elements of stack"<<endl<<"4.Push elements in Queue"<<endl<<"5.Pop Elements in Queue"<<endl<<"6.Display Elements of Queue"<<endl<<"7.Exit"<<endl;
         	cout<<"Enter your choice : ";
         	cin>>ch;
         	switch(ch)
           	{
             		case 1:cout<<"\nEnter number of elements to push in the Stack : "<<endl;
                     	cin>>n;
                     	for(i=0;i<n;i++)
                      	{
                        	cout<<"Enter the element : "<<endl;
                        	cin>>x;
                        	s.push(x);
                      	}
                	break;
             		case 2:	if(s.isempty())
             			{
					cout<<"\nEnter number of element to pop : "<<endl;
                     			cin>>m;
                     			if(m>n)
                      				cout<<"\n!!! There are not enough elements in the Stack !!!"<<endl;
                     			else
                       			{
						cout<<"\nThe following elements were popped : ";
                            			for(i=0;i<m;i++)
                             			{
                               				cout<<s.pop()<<" ";
                             			}
                                        cout<<endl;
                          		}
				}
				else
					cout<<"\n!!! The stack is empty !!!";
                       	break;
			case 3:	if(s.isempty())			
					s.show();
				else
					cout<<"\n!!! The stack is empty !!!";
                      	break;
               		case 4:	cout<<"\nEnter number of elements to push in the Queue : "<<endl;
                    		cin>>n;
              			for(i=0;i<n;i++)
                      		{
                        		cout<<"Enter the element : "<<endl;
                        		cin>>x;
                        		q.push(x);
                      		}
                      	break;
               		case 5:	if(q.isempty())
				{
					cout<<"\nEnter number of element to pop : "<<endl;
                     			cin>>m;
                     			if(m>n)
                      				cout<<"\n!!! There are not enough elements in the Queue !!!"<<endl;
                     			else
                       			{
						cout<<"\nThe following elements were popped : ";
                            			for(i=0;i<m;i++)
                             			{
                               				cout<<q.pop()<<" ";
                             			}
						cout<<"\n";
                          		}
				}
				else
					cout<<"\n!!! The queue is empty !!!";
                       	break;
              		case 6:	if(q.isempty())			
					q.show();
				else
					cout<<"\n!!! The queue is empty !!!";
                      	break;
             		case 7:	cout<<"\nExitting...\n"<<endl;
			break;
			default:cout<<"\nWrong choice entered...Try again";
			break;		
		}
		cout<<"\n\n************************************************\n";
	}while(ch!=7);
}        
