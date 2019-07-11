#include<iostream>
using namespace std;
class Personal_Record
{
	private:
	string name,city;
	long phone_no;
	public:
	void getData()
	{
		cout<<"\nEnter name : ";
		cin>>name;
		cout<<"\nEnter city : ";
		cin>>city;
		cout<<"\nEnter phone number : ";
		cin>>phone_no;
	}
	void showData()
	{
		cout<<"\nName : ";
		cout<<name;
		cout<<"\nEnter city : ";
		cout<<city;
		cout<<"\nPhone Number : ";
		cout<<phone_no;
	}
};
class Professional_Record
{
	private:
	string company,post;
	int exp_yrs;
	public:
	void getData()
	{
		cout<<"\nCompany : ";
		cin>>company;
		cout<<"\nPost : ";
		cin>>post;
		cout<<"\nWork Experience : ";
		cin>>exp_yrs;
	}
	void showData()
	{
		cout<<"\nCompany : ";
		cout<<company;
		cout<<"\nPost : ";
		cout<<post;
		cout<<"\nWork Experience : ";
		cout<<exp_yrs;
	}
};
class Academic_Record
{
	private:
	string college,degree;
	int marks;
	public:
	void getData()
	{
		cout<<"\nEnter college name : ";
		cin>>college;
		cout<<"\nEnter degree : ";
		cin>>degree;
		cout<<"\nEnter marks : ";
		cin>>marks;
	}
	void showData()
	{
		cout<<"\nCollege Name : ";
		cout<<college;
		cout<<"\nDegree : ";
		cout<<degree;
		cout<<"\nMarks : ";
		cout<<marks;
	}
};
class Employee : protected Personal_Record , protected Professional_Record , protected Academic_Record 
{
	private:
	public:
	friend istream & operator >>(istream &i,Employee &ee)
	{
		cout<<"\n****** PERSONAL RECORD ******\n";
		ee.Personal_Record :: getData();
		cout<<"\n****** PROFESSIONAL RECORD ******\n";
		ee.Professional_Record :: getData();
		cout<<"\n****** ACEDEMIC RECORD ******\n";
		ee.Academic_Record :: getData();
		return i;
	}
	friend ostream & operator <<(ostream &o,Employee & ee)
	{
		cout<<"\n****** PERSONAL RECORD ******\n";
		ee.Personal_Record :: showData();
		cout<<endl;		
		cout<<"\n****** PROFESSIONAL RECORD ******\n";
		ee.Professional_Record :: showData();
		cout<<endl;		
		cout<<"\n****** ACEDEMIC RECORD ******\n";
		ee.Academic_Record :: showData();
		cout<<endl;
		return o;
	}
};
int main()
{
	int i,n;
	cout<<"\n******** ****** ********\n";
	cout<<"\nEnter number of employees :";
	cin>>n;
	Employee e[n];
	cout<<"\n\n\n ******** INPUT ******** \n";
	cout<<" ******** ***** ******** \n\n";
	for(i=0;i<n;i++)
	{
		cin>>e[i];
	}
	cout<<"\n\n\n ******** OUTPUT ********";
	cout<<"\n******** ****** ******** \n\n";
	for(i=0;i<n;i++)
	{
		cout<<e[i];
	}
	cout<<"\n******** ****** ********\n";
	cout<<"\n******** END ********\n";
}
