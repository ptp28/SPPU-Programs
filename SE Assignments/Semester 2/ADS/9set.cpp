#include <iostream>
using namespace std;
class Node
{
    private:
    int data;
    Node *next;
    public:
    Node *start,*head,*temp,*start1,*start2;
    
    void create(int data)       //simple linked list creation...recall DSA
    {                           //Trace on paper
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

    void insert(Node *tempstart,int data)   //Inserting at end
    {
        head=tempstart;
        while(head->next!=NULL)         //while loop to get to end node
        {
            head=head->next;            //head Goes forward
        }
        head->next=new Node;
        head=head->next;
        head->data=data;
        head->next=NULL;
    }
    void print(Node *tempstart)     //Print from start till head!=NULL
    {
        cout<<"\nThe set is :\n";
        head=tempstart;
        cout<<"{ ";
        while(head!=NULL)
        {
            cout<<head->data<<" ";
            head=head->next;            //Goes forward
        }
        cout<<"}";
	cout<<"\n\n***** *** *****\n";
    }
    
    int search(Node *tempstart,int data)       //Simple linear search
    {
        int flag=0;
        head=tempstart;
        while(head!=NULL)
        {
            if(head->data==data)
            {
                flag=1;
                return 1;           //if true return 1 to where function is call
            }
            head=head->next;
        }
        if(flag==0)
        {
            return 0;
        }
    }
    
    int remove(Node *tempstart,int data)    //removes single element
    {
        head=tempstart;
        
        if(head->data==data)    //checking if first node is equal
        {
            temp=head;
            head=head->next;
            start=head;
            delete(temp);
            return 1;
        }
        while(head->next!=NULL)
        {
            if((head->next->data)==data)
            {
                temp=head->next;
	    		head->next=head->next->next;
                delete(temp);
                return 1;       //returns 1 to function call if deleted
            }
            else
                head=head->next;
        }
        return 0;       //returns 0 if not deleted
    }
    
    void intersection(Node *tempstart1,Node *tempstart2)
    {
        head=tempstart1;
        cout<<"\nThe intersection of the two sets is : \n";
        while(head!=NULL)
        {
            temp=tempstart2;    //temp repeatedly will be assigned to start as it is inside while
            while(temp!=NULL)
            {
                if(head->data==temp->data)  //nested while loop
                {                           //head will be constant,temp will keep changing
                    cout<<head->data<<" ";
                }
                temp=temp->next;
            }
            head=head->next;
        }
    }
    
    void unionset(Node *tempstart1,Node *tempstart2)
    {
        head=tempstart1;
        temp=tempstart2;
        cout<<"\nThe union of the two sets is : \n";
        while(temp!=NULL || head!=NULL)
        {
            if(head==NULL)                  //if first set is null then only display temp
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            else if(temp==NULL)             //if second set is null then only display head
            {
                cout<<head->data<<" ";
                head=head->next;
            }
            else if(head->data==temp->data)     //if it is equal then display any one (union has only one occurence)
            {
                cout<<head->data<<" ";
                head=head->next;
            }
            else if(head->data>temp->data)      //if first set element is greater, then display second set element
            {                                   //Basically display the lower one of the two sets
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            else if(head->data<temp->data)  //if second set element is greater, then display first set element
            {                               //Basically display the lower one of the two sets
                cout<<head->data<<" ";
                head=head->next;
            }
        }
    }
};

int main()
{
    Node n;
    int data,i,limit,choice,flag;
    n.start=NULL;
    n.start1=NULL;
    n.start2=NULL;
    cout<<"\n***** *** *****\n";
    cout<<"\nEnter number of elements in the set : ";
    cin>>limit;
    cout<<"\nEnter elements sequencially only,\n";
    for(i=0;i<limit;i++)
    {
        cout<<"Enter data : ";
        cin>>data;
        n.create(data);         //create first set
    }
    n.start1=n.start;           //store starting address of first set to start1
    n.start=NULL;               //set start to null again so that we can accept second set
    n.print(n.start1);
    cout<<"\nEnter number of elements in the second set : ";
    cin>>limit;
    cout<<"\nEnter elements sequencially only,\n";
    for(i=0;i<limit;i++)
    {
        cout<<"Enter data : ";
        cin>>data;
        n.create(data);     //create second set
    }
    n.start2=n.start;       //store start of second set in start2
    n.print(n.start2);
    cout<<"\n***** *** *****\n";
    do
    {
        cout<<"\n1.Insert Elements\n2.Search\n3.Delete Element\n4.Intersection\n5.Union\n6.Exit\nEnter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"\nEnter data you want to insert :";
                cin>>data;
                n.insert(n.start1,data);        //call insert function
                limit++;
                cout<<"\n***** *** *****\n";
                cout<<"\nThe element is added";
                n.print(n.start1);
                break;
            case 2:
                cout<<"Enter the data to be searched : ";
                cin>>data;
                flag=n.search(n.start1,data);       //call search function
                if(flag==1)
                    cout<<"Element is present";
                else
                    cout<<"Element is not present";
                break;
            case 3:
                cout<<"Enter the element to be deleted : ";
                cin>>data;
                flag=n.remove(n.start1,data);       //call remove function
                if(flag==1)
                {
                    cout<<"Element deleted successfully";
                    limit--;
                }
                else
                    cout<<"Element not deleted successfully";
                cout<<"\n***** *** *****\n";
                break;
            case 4:
                n.intersection(n.start1,n.start2);      //call intersection function
                cout<<"\n***** *** *****\n";
                break;
            case 5:
                n.unionset(n.start1,n.start2);          //call union function
                cout<<"\n***** *** *****\n";
                break;
            case 6:
                cout<<"\nExitting...\n";
                break;
            default:
                cout<<"\nWrong choice entered...Try Again";
                break;
        }
    }while(choice!=6);
}
