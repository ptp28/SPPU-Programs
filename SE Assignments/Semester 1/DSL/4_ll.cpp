#include <iostream>
using namespace std;
class Node
{
    private:
    int data;
    Node *next;
    public:
    Node *start,*head,*nhead,*nstart,*temp;
    void create(int data)
    {
        if(start==NULL)
        {
            start=new Node;
            start->data=data;
            start->next=NULL;
            head=start;
        }
        else
        {
            head->next=new Node;
            head=head->next;
            head->data=data;
            head->next=NULL;
        }
    }
    void print(Node *tempstart)
    {
        cout<<"\nThe list is :\n";
        head=tempstart;
        while(head!=NULL)
        {
            cout<<head->data<<" ";
            head=head->next;
        }
	cout<<"\n\n***** *** *****\n";
    }
    void insert(int data)
    {
        head=start;
        int choice,count,i;
        cout<<"\nWhere do you want to insert data ,";
        cout<<"\n1.Beginning\n2.In Middle\n3.End\nEnter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                temp=new Node;
                temp->data=data;
                temp->next=start;
                start=temp;
                break;
            case 2:
                cout<<"\nEnter the position where you want to insert data : ";
                cin>>count;
                for (i=1;i<(count-1);i++)
                {
                    head=head->next;
                }
                temp=new Node;
                temp->next=head->next;
                head->next=temp;
                temp->data=data;
                break;
            case 3:
                while(head->next!=NULL)
                {
                    head=head->next;
                }
                temp=new Node;
                temp->data=data;
                head->next=temp;
                temp->next=NULL;
                break;
                
        }
    }
    void seperate()
    {
        head=start;
        while(head!=NULL)
        {
            if( (head->data) < 0)
            {
                negative(head->data);
            }
            head=head->next;
        }
    }
    void negative(int data)
    {
        if(nstart==NULL)
        {
            nstart=new Node;
            nstart->data=data;
            nstart->next=NULL;
            nhead=nstart;
        }
        else
        {
            nhead->next=new Node;
            nhead=nhead->next;
            nhead->data=data;
            nhead->next=NULL;
        }
    }
    void remove()
    {
        head=start;
        if(head->data<0)
        {
            temp=head;
            head=head->next;
            start=head;
            delete(temp);
        }
        while(head->next!=NULL)
        {
            if((head->next->data)<0)
            {
                temp=head->next;
	    		head->next=head->next->next;
                delete(temp);
            }
            else
                head=head->next;
        }
    }
    void sort(Node *tempstart)
    {
        int i,j,temp,count=0;
		head=tempstart;
		while(head!=NULL)
        {
            count++;
            head=head->next;
        }
        for(i=0;i<count;i++)
        {
            head=tempstart;
            for(j=0;j<count-1;j++)
            {
                if(head->data > head->next->data)
                {
                    temp=head->data;
	 				head->data=head->next->data;
	 				head->next->data=temp;
                }
                head=head->next;
            }
        }
   }
   void join()
   {
            nhead=nstart;
            while(nhead->next!=NULL)
            {
                nhead=nhead->next;
            }
            nhead->next=start;
            start=nstart;
            nstart=NULL;
        }
}; 
int main()
{
    Node n;
    int data,i,limit,choice,choice2; 
    n.start=NULL;
    n.nstart=NULL;
    n.temp=NULL;
    n.head=n.start;
    n.nhead=n.nstart;
    cout<<"\n***** *** *****\n";
    cout<<"\nEnter number of nodes : ";
    cin>>limit;
    for(i=0;i<limit;i++)
    {
        cout<<"Enter data : ";
        cin>>data;
        n.create(data);
    }
    n.print(n.start);
    do
    {
        cout<<"\n1.Insert Node\n2.Seperate Negative numbers and delete them from the main list\n3.Sort list in ascending order\n4.Join the two lists of negative and positive numbers\n5.Exit\nEnter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"\nEnter data you want to insert :";
                cin>>data;
                n.insert(data);
		limit++;
		cout<<"\n***** *** *****\n";
		cout<<"\nThe element is added";
                n.print(n.start);
                break;
            case 2:n.seperate();
		   cout<<"\n***** *** *****\n";
		   cout<<"\nThe link list is seperated...";
		   cout<<"\nFor entered negative numbers :";
		   n.print(n.nstart);
		   n.remove();
		   cout<<"\n***** *** *****\n";
		   cout<<"\nAll negative numbers have been deleted";
		   cout<<"\nThe main list now only contains positive numbers";
		   n.print(n.start);
                break;
            case 3:do
		{
			cout<<"\n***** *** *****\n";
			cout<<"\n1.Sort list of\n1.Negative Numbers\n2.Positive Numbers\nEnter your choice : ";
			cin>>choice2;
			switch(choice2)
			{
				case 1:cout<<"\n***** *** *****\n";
				cout<<"\nThe list has been sorted";				
				n.sort(n.nstart);
				n.print(n.nstart);
				break;
				case 2:cout<<"\n***** *** *****\n";
				cout<<"\nThe list has been sorted";
				n.sort(n.start);
                		n.print(n.start);
				break;
				default:cout<<"\nWrong choice entered...Try Again";
				break;
			}
		}while(choice2!=1&&choice2!=2);
                break;
            case 4:if(n.nstart!=NULL)
            {
                n.join();
                cout<<"\n***** *** *****\n";
                cout<<"\nThe two lists have been merged";
                n.print(n.start);
            }
                else
                    cout<<"\nThe list isn't seperated OR there are no negative numbers to seperate\n\n***** *** *****\n";
                    
		break;
            case 5:
                cout<<"\nExitting...\n";
                break;
            default:
                cout<<"\nWrong choice entered...Try Again";
                break;
        }
    }while(choice!=5);
}


