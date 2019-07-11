#include<iostream>
using namespace std;
class Sort
{
	int i,j;
	public:
	void swap(float* a,float* b)
	{
    		float t=*a;
    		*a=*b;
    		*b=t;
	}
    void QuickSort(float arr[],const int left,const int right,const int n)
    {
        if (left>=right)
            return;
        int part=partition(arr,left,right);
        cout<<"\nPivot : "<<arr[part]<<"\n";
        display(arr,n);
        cout<<endl;
        QuickSort(arr,left,part-1,n);
        QuickSort(arr,part+1,right,n);
    }
    int partition(float arr[],const int left,const int right)
    {
        const float pivot=arr[left];
        i=left+1;
        j=right;
        while(i<=j)
        {
            while(i<=j&&arr[i]<=pivot)
                i++ ;
            while(i<=j&&arr[j]>pivot)
                j--;
            if (i<j)
                swap(&arr[i],&arr[j]);
        }
        swap(&arr[i-1],&arr[left]);
        return i-1;
    }
	void display(float arr[],int num)
	{
		for(i=0;i<num;i++)
		{
			cout<<arr[i]<<"  ";
		}
		cout<<endl;
	}
};
int main()
{
	Sort s;
	int i,j,n,choice;
	cout<<"\nEnter the number of students :";
	cin>>n;
	cout<<endl;
	float percentage[n];
	for(i=0;i<n;i++)
	{
		cout<<"Enter percentage of student "<<i+1<<" : ";
		cin>>percentage[i];
	}
	cout<<"\n\n****** Sorting using Quick Sort ******";
	s.QuickSort(percentage,0,n-1,n);
	cout<<"\n****** The list has been sorted ******\n";
	s.display(percentage,n);
	cout<<"\n****** The top 5 percentages ******\n";
	for(i=n-1,j=1;i>n-6 && j!=n+1;i--,j++)
	{
		cout<<j<<". "<<percentage[i]<<endl;
	}
}	
