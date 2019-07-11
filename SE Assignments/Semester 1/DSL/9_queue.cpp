#include<iostream>
using namespace std;
class Queue
{
	private:
	string job;
	Queue *next;
	public:
	Queue *current,*temp,*travtemp;
	void create(string job)
	{
		if(current==NULL)
		{
			current=new Queue;
			current->job=job;
			current->next=NULL;
			temp=current;
		}
		else
		{
			temp->next=new Queue;
			temp=temp->next;
			temp->job=job;
			temp->next=NULL;
		}
	}
    int isEmpty()
    {
        if(current==NULL)
            return 0;
        else
            return 1;
    }
	void deletenode()
	{
        if(isEmpty())
        {
            travtemp=current;
            current=current->next;
            cout<<"\nThe job '"<<travtemp->job<<"' has been deleted";
            delete(travtemp);
        }
        else
            cout<<"\n!!! The Queue is empty !!!";
    }
	void display()
	{
		travtemp=current;
		if(isEmpty())
		{
            cout<<"\nThe jobs in the queue are : ";
            while(travtemp!=NULL)
            {
                cout<<endl<<i<<". "<<travtemp->job;
                travtemp=travtemp->next;
                i++;
            }
		}
		else
		{
            cout<<"\n!!! The Queue is empty !!!";
		}
	}
};
int main()
{
	Queue q;
	q.current=NULL;
	int i,choice;
	string job;
	cout<<"\nEnter number of jobs to be added : ";
	cin>>choice;
	for(i=0;i<choice;i++)
	{
		cout<<"Enter job name : ";
		cin>>job;
		q.create(job);
	}
	do
	{
		cout<<"\n\n\n****** MENU ******";
		cout<<"\n1.Add a job\n2.Display queue\n3.Delete job\n4.Exit\nEnter your choice: ";
		cin>>choice;
		cout<<"\n*********************\n";
		switch(choice)
		{
			case 1:	cout<<"\nEnter job name : ";
				cin>>job;
				q.create(job);
			break;
			case 2:	q.display();
			break;
			case 3:	q.deletenode();
			break;
			case 4:	cout<<"\nExitting...\n";
			break;
			default:cout<<"\nWrong choice entered";
			break;		
		}
		cout<<"\n\n*********************\n";
	}while(choice!=4);	
}
