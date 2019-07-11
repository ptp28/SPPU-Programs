#include<iostream>
using namespace std;
class Sort
{
	int i,j,index;
	float temp,min;
	public:
	void BubbleSort(float arr[],int num)
	{
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
	void SelectionSort(float arr[],int num)
	{
		for(i=0;i<num;i++)
		{
			min=arr[i];
			index=i;
			for(j=i+1;j<num;j++)
			{
				if(min>arr[j])
				{
					min=arr[j];
					index=j;
				}
			}
			arr[index]=arr[i];
			arr[i]=min;
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
	cout<<"\n1.Bubble Sort\n2.Selection Sort\nEnter your choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1:	s.BubbleSort(percentage,n);
		break;
		case 2:	s.SelectionSort(percentage,n);
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
