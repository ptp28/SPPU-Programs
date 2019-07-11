#include<iostream>
using namespace std;
class Sort
{
	int i,j,gap;
	float temp,min;
	public:
	void InsertionSort(float arr[],int num)
	{
   		for(i=1;i<num;i++)
   		{
       			min=arr[i];
       			j=i-1;
       			while(j>=0 && arr[j]>min)
      			{
           			arr[j+1]=arr[j];
           			j=j-1;
       			}
       			arr[j+1]=min;
   		}
	}
	void ShellSort(float arr[],int num)
	{
		for(gap=num/2;gap>0;gap=gap/2)
    		{
        		for(int i=gap;i<num;i++)
        		{
            			temp=arr[i];            
            			for(j=i;j>=gap && arr[j-gap]>temp;j=j-gap)
				{
                			arr[j]=arr[j-gap];                         	
				}
				arr[j]=temp;
        		}
    		}
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
	err:
	cout<<"\n\n****** SORT ******";
	cout<<"\n1.Insertion Sort\n2.Shell Sort\nEnter your choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1:	s.InsertionSort(percentage,n);
		break;
		case 2:	s.ShellSort(percentage,n);
		break;
		default:cout<<"\nWrong choice entered!";
			cout<<"\nTry again...";
			goto err;
		break;
	}
	cout<<"\n****** The list has been sorted ******\n";
	s.display(percentage,n);
	cout<<"\n****** The top 5 percentages ******\n";
	for(i=n-1,j=1;i>n-6&& j!=n+1;i--,j++)
	{
		cout<<j<<". "<<percentage[i]<<endl;
	}
}	
