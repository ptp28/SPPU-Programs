 #include <iostream>
using namespace std;
class Node
{
    private:
    int data;
    Node *next;
    Node *previous;
    public:
    Node *start,*head,*head1,*head2,*last,*start1,*last1,*start2,*last2,*startC1,*lastC1,*startC2,*lastC2;
    void accept()
    {
        int data;
        cout<<"\nEnter binary numbers ( 0 / 1 )\nEnter any other number to stop : ";
        do
        {
            cin>>data;
            if(data==0 || data==1)
            {
                create(data);
            }
        }while(data==0 || data==1);
    }
    void create(int data)
    {
        if(start==NULL)
        {
            start=new Node;
            start->data=data;
            start->previous=NULL;
            start->next=NULL;
            head=start;
            last=start;
        }
        else
        {
            head->next=new Node;
            head->next->previous=head;
            head=head->next;
            head->data=data;
            head->next=NULL;
            last=head;
        }
    }
    void print(Node *tempstart)
    {
        head=tempstart;
        while(head!=NULL)
        {
            cout<<head->data<<" ";
            head=head->next;
        }
        cout<<endl;
    }
    void oneC(Node *tempstart)
    {
        head2=tempstart;
        while(head2!=NULL)
        {
            if(head2->data==0)
                create(1);
            else
                create(0);
            head2=head2->next;
        }
    }
    Node* twoC(Node *templast,Node **tempstart)
    {
        head=templast;
        while(head!=NULL)
        {
            head->data=head->data+1;
            if(head->data>1)
            {
                head->data=0;
            }
            else
            {
                break;
            }
            if(head->previous==NULL)
            {
                head2=new Node;
                head2->data=1;
                head2->next=(*tempstart);
                head2->previous=NULL;
                (*tempstart)->previous=head2;
                (*tempstart)=head2;
                break;
            }
            head=head->previous;
        }
        return (*tempstart);
    }
    void add()
    {
        int sum=0,carry=0;
        cout<<"\nThe two numbers to be added are :\n";
        print(start1);
        cout<<"\n + \n";
        print(start2);
        head2=last2;
        head1=last1;
        while(head1!=NULL || head2!=NULL)
        {
            sum=0;
            sum=sum+carry;
            if(head2!=NULL)
            {
                sum=sum+head2->data;
                head2=head2->previous;
            }
            else
            {
                sum=sum+0;
            }
            if(head1!=NULL)
            {
                sum=sum+head1->data;
                head1=head1->previous;
            }
            else
            {
                sum=sum+0;
            }
            carry=sum/2;
            sum=sum%2;
            create(sum);
        }
        if(carry==1)
            create(carry);
        head=last;
        cout<<"______________________\n";
        while(head!=NULL)
        {
            cout<<head->data<<" ";
            head=head->previous;
        }
        cout<<endl;
    }
};
int main()
{
    Node n;
    int check=0,choice;
    n.start=NULL;
    n.start1=NULL;
    n.start2=NULL;
    n.last=NULL;
    n.last1=NULL;
    n.last2=NULL;
    n.head=n.start;
    n.head2=n.start;
    cout<<"\n**************************************************\n";
    cout<<"\nEnter the first binary number :";
    n.accept();
    n.start1=n.start;
    n.last1=n.last;
    n.start=NULL;
    n.last=NULL;
    cout<<"\nThe binary number is :\n";
    n.print(n.start1);
    cout<<"\nEnter the second binary number :";
    n.accept();
    n.start2=n.start;
    n.last2=n.last;
    n.start=NULL;
    n.last=NULL;
    cout<<"\nThe binary number is :\n";
    n.print(n.start2);
    cout<<"\n**************************************************\n";
    cout<<"\n\tONE's COMPLEMENT\n";
    n.oneC(n.start1);
    n.startC1=n.start;
    n.lastC1=n.last;
    n.start=NULL;
    cout<<"For the 1st Binary number :";
    n.print(n.startC1);
    n.oneC(n.start2);
    n.startC2=n.start;
    n.lastC2=n.last;
    n.start=NULL;
    cout<<"For the 2nd Binary number :";
    n.print(n.startC2);
    cout<<"\n**************************************************\n";
    cout<<"\n\tTWO's COMPLEMENT\n";
    n.startC1=n.twoC(n.lastC1,&n.startC1);
    cout<<"For the 1st Binary number :";
    n.print(n.startC1);
    n.startC2=n.twoC(n.lastC2,&n.startC2);
    cout<<"For the 2nd Binary number :";
    n.print(n.startC2);
    cout<<"\n**************************************************\n";
    cout<<"\n\tADDITION OF THE BINARY NUMBERS\n";
    n.add();
    cout<<"\n**************************************************\n";
    cout<<"\n\nExitting...\n";
}


