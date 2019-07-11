#include<iostream>
using namespace std;
class Personal_Record
{
	private:
	string name,city;
	long phone_no;
	public:
	void getdata()
	{
		cout<<"\nEnter the name of the employee";
		cin>>name;
		cout<<"\nEnter the city";
		cin>>city;
		cout<<"\nEnter phone no. of the employee";
		cin>>phone_no;  
	}
	void display()
	{
		cout<<"Name="<<name<<endl<<"City="<<city<<endl<<"Phone no."<<phone_no<<endl;
	}	
};
class Professional_Record
{
	private:
	string company,post;
	int exp_years;
	public:
	void getdata()
	{
		cout<<"\nEnter the company name";
		cin>>company;
		cout<<"\nEnter the post of the employee";
		cin>>post;
		cout<<"\nEnter the years of experience";
		cin>>exp_years;
		
	}
	void display()
	{
		cout<<"Company="<<company<<endl<<"Post="<<post<<endl<<"Experience years="<<exp_years;
	}
};
class Academic_Record
{
	private:
	string college,degree;
	int marks;
	public:
	void getdata()
	{
		cout<<"\nEnter the college name";
		cin>>college;
		cout<<"\nEnter the degree";
		cin>>degree;
		cout<<"\nEnter marks";
		cin>>marks;	
	}
	void display()
	{
		cout<<"college="<<college<<endl<<"degree="<<degree<<endl<<"marks="<<marks;
	}
};
class Biodata:public Personal_Record , public Professional_Record , public Academic_Record
{
	public:
	void get()
	{
		Personal_Record::getdata();
		Professional_Record::getdata();
		Academic_Record::getdata();
	}
	void put()
	{
		Personal_Record::display();
		Professional_Record::display();
		Academic_Record::display();
	}
};
int main()
{
	Biodata bd;
	bd.get();
	bd.put();
}
