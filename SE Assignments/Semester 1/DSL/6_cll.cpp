#include <iostream>
using namespace std;
class Node
{
    private:
    int data;
    Node *next;
    public:
    Node *start,*start1,*start2,*head,*temphead;
    void accept()
    {
        int i,limit;
        cout<<"\nEnter number of nodes : ";
        cin>>limit;
        for(i=0;i<limit;i++)
        {
            cout<<"Enter data : ";
            cin>>data;
            create(data);
        }
    }
    void create(int data)
    {
        if(start==NULL)
        {
            start=new Node;
            start->data=data;
            start->next=start;
            head=start;
        }
        else
        {
            head->next=new Node;
            head=head->next;
            head->data=data;
            head->next=start;
        }
    }
    void print(Node *tempstart)
    {
        head=tempstart;
        do
        {
            cout<<head->data<<" ";
            head=head->next;
        }while(head!=tempstart);
    }
    void sort(Node *tempstart)
    {
        int i,j,temp,count=0;
		head=tempstart;
		do
        {
            count++;
            head=head->next;
        }while(head!=tempstart);
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
   void join(Node *tempstart)
   {
       temphead=tempstart;
       do
       {
           create(temphead->data);
           temphead=temphead->next;
       }while(temphead!=tempstart);
   }
   void deletelist(Node **tempstart)
   {
        head=*tempstart;
        do
        {
            head=temphead;
            temphead=temphead->next;
            head=NULL;
        }while(temphead!=NULL);
   }
};
int main()
{
    Node n;
    int data,i,limit,choice,choice2;
    n.start=NULL;
    n.head=n.start;
    cout<<"\n***** *** *****\n";
    cout<<"\nEnter the 1st list\n";
    n.accept();
    n.start1=n.start;
    n.start=NULL;
    cout<<"\n***** *** *****\n";
    cout<<"\nEnter the 2st list\n";
    n.accept();
    n.start2=n.start;
    n.start=NULL;
    cout<<"\n***** *** *****\n";
    cout<<"\nThe 1st list is :\n";
    n.print(n.start1);
    cout<<"\nThe 2nd list is :\n";
    n.print(n.start2);
    cout<<"\n\n***** *** *****\n";
    n.start=NULL;
    n.join(n.start1);
    n.join(n.start2);
    n.sort(n.start);
    cout<<"\nAfter joining the two lists\n";
    n.print(n.start);
    cout<<"\n\n***** *** *****\n";
    n.deletelist(&n.start1);
    n.deletelist(&n.start2);
    cout<<"\n\n***** *** *****\n";
}


