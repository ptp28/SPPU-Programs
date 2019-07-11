#include<iostream>
using namespace std;
template <class T>
class Sort
{
	T min;
	int index,i,j,num;
	void arrange(T data[])
	{
		for(i=0;i<num;i++)
		{
			min=data[i];
			index=i;
			for(j=i+1;j<num;j++)
			{
				if(min>data[j])
				{
					min=data[j];
					index=j;
				}
			}
			data[index]=data[i];
			data[i]=min;
		}
	}
	void accept(T data[])
	{
		for(i=0;i<num;i++)
		{
			cin>>data[i];	
		}
	}
	void display(T data[])
	{
		for(i=0;i<num;i++)
		{
			cout<<data[i]<<" ";
		}
	}
	public:
	Sort(int n)
	{
		num=n;
	}
	void start()
	{
		T data[num];
		accept(data);
		arrange(data);
		cout<<"\nAfter soring, the numbers in ascending order are -\n";
		display(data);
		cout<<endl;
	}
	
};
int main()
{
	int i,n,choice;
	cout<<"\n1.INTEGERS\n2.FLOAT\n3.CHARACTERS\nENTER YOUR CHOICE :";
	cin>>choice;
	cout<<"\nEnter the number of elements :";
	cin>>n;
	Sort<int> s1(n);
	Sort<float> s2(n);
	Sort<char> s3(n);
	switch(choice)
	{
		case 1:
		s1.start();
		break;
		case 2:
		s2.start();
		break;
		case 3:
		s3.start();
		break;
	}
}
