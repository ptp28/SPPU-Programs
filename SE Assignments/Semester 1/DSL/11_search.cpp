#include<iostream>
using namespace std;
class Student
{
    private:
    int i,j,flag,key;
	public:
    void display(int arr[],int num)
    {
        for(i=0;i<num;i++)
        {
            cout<<arr[i]<<"  ";
        }
    }
    void LinearSearch(int arr[],int num,int key)
    {
        flag=0;
        for(i=0;i<num;i++)
        {
            if(key==arr[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            cout<<"\n!!! The Roll Number was found using Linear Search !!!"<<endl;
        }
        else
        {
            cout<<"\n!!! The Roll Number was Not found !!!"<<endl;
        }
    }
    void SentinelSearch(int arr[],int num,int key)
    {
        i=0;
        int last=arr[num-1];
        arr[num-1]=key;
        while(arr[i]!=key)
        {
            i++;
        }
        arr[num-1]=last;
        if((i<num-1)||(key==arr[num-1]))
        {
            cout<<"\n!!! The Roll Number was found using Sentinel Search !!!"<<endl;
        }
        else
        {
            cout<<"\n!!! Roll Number was not found !!!"<<endl;
        }
    }
    void BinarySearch(int arr[],int num,int key)
    {
        int low=0,high=num-1,mid;
        flag=0;
        while(low<=high)
        {
            mid = (low+high)/2;
            if(arr[mid]<key)
            {
                low=mid+1;
            }
            else if(arr[mid]>key)
            {
                high=mid-1;
            }
            else
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            cout<<"\n!!! The Roll Number was found using Binary Search !!!"<<endl;
        }
        else
        {
            cout<<"\n!!! The Roll Number was not found !!!"<<endl;
        }

    }
    void FibonacciSearch(int arr[], int num, int key)
    {
        flag=0;
        int fib2=0;
        int fib1=1;
        int fibM=fib2+fib1;
        while(fibM<num)
        {
            fib2=fib1;
            fib1=fibM;
            fibM=fib2+fib1;
        }
        int offset=-1;
        while(fibM>1)
        {
            if(offset+fib2<=num-1)
                i=offset+fib2;
            else
                i=num-1;
            if(arr[i]<key)
            {
                fibM=fib1;
                fib1=fib2;
                fib2=fibM-fib1;
                offset=i;
            }
            else if(arr[i]>key)
            {
                fibM=fib2;
                fib1=fib1-fib2;
                fib2=fibM-fib1;
            }
            else
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            cout<<"\n!!! The Roll Number was found using Fibonacci Search !!!"<<endl;
        }
        else
        {
            cout<<"\n!!! The Roll Number was not found !!!"<<endl;
        }
    }
    void Sort(int arr[],int num)
    {
        int temp;
        for(i=0;i<num;i++)
        {
            for(j=0;j<num-1;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }				
    }
};
int main()
{
    int choice,key,num,i;
    Student s;
    cout<<"\n\n*******************************************\n";
    cout<<"\nEnter number of students : ";
    cin>>num;
    int arr[num];
    cout<<"\n\n";
    for(i=0;i<num;i++)
    {
        cout<<"Enter roll number of the student : ";
        cin>>arr[i];
    }
    cout<<"\n\n*******************************************\n";
    cout<<"\nThe entered roll numbers are :\n";
    s.display(arr,num);
    cout<<"\n\n*******************************************\n";
    do
    {
        cout<<"\n*** SEARCH USING ***\n1.Linear Search\n2.Sentinel Search\n3.Binary Search\n4.Fibonacci Search\n5.Exit\nEnter your choice : ";
        cin>>choice;
        if(choice<5)
        {
            cout<<"\nEnter the roll number to be searched : ";
            cin>>key;
        }
        switch(choice)
        {
            case 1:s.LinearSearch(arr,num,key);
                break;
            case 2:s.SentinelSearch(arr,num,key);
                break;
            case 3:s.Sort(arr,num);
                s.BinarySearch(arr,num,key);
                break;
            case 4:s.Sort(arr,num);
                s.FibonacciSearch(arr,num,key);
                break;
            case 5:cout<<"\nExitting...\n";
                break;
            default: cout<<"\n!!! Wrong choice entered !!!";
                break;
        }
        cout<<"\n\n*******************************************\n";
    }while(choice!=5);
}

