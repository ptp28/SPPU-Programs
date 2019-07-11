#include<iostream>
using namespace std;
#define MAX 10
class Deque
{
    int  arr[MAX];
    int  front;
    int  rear;
    int  size;
    public :
    Deque()
    {
        front = -1;
        rear = 0;
        size=MAX;
    }
    void  insertfront(int data)
    {
        if (isFull())
        {
            if (front == -1)
            {
                front = 0;
                rear = 0;
            }
            else if (front == 0)
                front = size - 1 ;
            else
                front = front-1;
            arr[front] = data ;
        }
    }
    void  insertrear(int data)
    {
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else if (rear == size-1)
            rear = 0;
        else
            rear = rear+1;
        arr[rear] = data ;

    }
    void  deletefront()
    {
        if (isEmpty())
        {
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else if (front == size -1)
                front = 0;
            else
                front = front+1;
        }
    }
    void  deleterear()
    {
        if (isEmpty())
        {
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else if (rear == 0)
                rear = size-1;
            else
                rear = rear-1;
        }
    }
    int  isFull()
    {
        if((front == 0 && rear == size-1)||front == rear+1)
        {
            cout<<"\nOverflow\n";
            return 0;
        }
        else
            return 1;
    }
    int  isEmpty()
    {
        if(front==-1)
        {
            cout << "\nUnderflow\n" << endl ;
            return 0;
        }
        else
            return 1;
    }
    void display()
    {
        int i;
        if(isEmpty())
        {
            cout<<"\nThe queue is : \n";
            for(i=front;i<=rear;i++)
            {
                cout<<arr[i]<<endl;
            }
        }
    }

};
int main()
{
    Deque d;
    int choice,choice2,data;
    cout<<"\n\n*******************************************\n";
    do
    {
        cout<<"\n1.Insert Data\n2.Delete Data\n3.Display Queue\n4.Exit\nEnter your choice :";
        cin>>choice;
        switch(choice)
        {
            case 1:cout<<"\nEnter data to insert : ";
                cin>>data;
                e1:
                cout<<"\n1.Insert from front\n2.Insert from back\nEnter your choice : ";
                cin>>choice2;
                switch(choice2)
                {
                case 1:d.insertfront(data);
                    break;
                case 2:d.insertrear(data);
                    break;
                default:cout<<"!!! Wrong choice entered !!!";
                    goto e1;
                    break;
            }
                break;
            case 2:e2:
                cout<<"\n1.Delete from front\n2.Delete from back\nEnter your choice :";
                cin>>choice2;
                switch(choice2)
            {
                case 1:d.deletefront();
                    break;
                case 2:d.deleterear();
                    break;
                default:cout<<"!!! Wrong choice entered !!!";
                    goto e2;
                    break;
            }
                break;
            case 3:d.display();
                break;
            case 4:cout<<"\nExitting...\n";
                break;
            default:cout<<"!!! Wrong choice entered !!!";
                break;
        }
        cout<<"\n\n*******************************************\n";
    }while(choice!=4);
}
