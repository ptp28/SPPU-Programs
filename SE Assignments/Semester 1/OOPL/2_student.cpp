#include <iostream>
#include <iomanip>
using namespace std;
class Student
{	
	int marks,rollno;
	string name,bg;
	public:
	Student()
	{
		marks=0;
		rollno=0;
		bg=' ';
		name=" ";
	}
	void getroll()
	{	
		cout<<"Enter the roll number of the student :";
		cin>>rollno;
	}
	void getname()
	{
		cout<<"Enter the name of the student :";
		cin>>name;
	}
	void getmarks()
	{
		cout<<"Enter the marks of the student :";
		cin>>marks;
	}
	void getbg()
	{
		cout<<"Enter the blood group of the student :";
		cin>>bg;	
	}
	void display()
	{
        cout<<setw(10)<<rollno;
		cout<<setw(10)<<name;
		cout<<setw(10)<<marks;
		cout<<setw(10)<<bg;
	}
	int ret_rn()
	{
		return rollno;
	}
};	
int main()
{
	int i,choice,c,n,rn,flag;
	cout<<"\nEnter the number of students to be entered :";
	cin>>n;
	Student s[20];
	cout<<"Enter data for "<<n<<" students -";
	for(i=0;i<n;i++)
	{
		s[i].getroll();			
		s[i].getname();
		s[i].getmarks();
		s[i].getbg();
	}
	cout<<endl<<endl;
	do
	{
	cout<<"\n1. Display \n2. Search \n3. Modify \n4. Delete \n5. Exit\nEnter your choice :";
	cin>>choice;
	switch(choice)
	{
		case 1: cout<<"*************** DATABASE ***************\n\n";
			cout<<endl<<setw(10)<<"ROLL NO."<<setw(10)<<"NAME"<<setw(10)<<"MARKS"<<setw(10)<<"BLOOD GROUP\n\n";
			for(i=0;i<n;i++)
			{
				s[i].display();
				cout<<endl;
			}
			cout<<"\n\n*************** ******** ***************";
		break;
		case 2:cout<<"\nEnter the roll number of student to be searched : ";
			cin>>rn;
			flag=0;
			for(i=0;i<n;i++)
			{
				if(s[i].ret_rn()==rn)			
				{
					cout<<"\nRoll number "<<rn<<" is student number "<<i+1;
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				cout<<"\nRoll number entered is not found ";
			}
		
		break;
		case 3: cout<<"\nEnter the roll number of student whose data has to be modified : ";
			cin>>rn;
			flag=0;
			for(i=0;i<n;i++)
			{
				if(s[i].ret_rn()==rn)			
				{
					do
					{
					cout<<"\nWhich data do you want to modify";
					cout<<"\n1. Name\n2. Marks\n3. Blood Group\n4. Go Back to previous menu\nEnter your choice : ";
					cin>>c;
					cout<<endl;
					switch(c)
					{
						case 1: s[i].getname();
						break;
						case 2: s[i].getmarks();
						break;
						case 3: s[i].getbg();
						break;
						case 4:break;
						default:cout<<"\nWrong choice entered...try again...";
					}
					}while(c!=4);
					flag=1;				
					break;			
				}
			}
			if(flag==0)
			{
				cout<<"\nRoll number entered is not found ";
			}
            else
                cout<<"\n*** Data modified successfully ***";
		break;
		case 4: cout<<"\nEnter the roll number of student whose data has to be deleted : ";
			cin>>rn;
			flag=0;
			for(i=0;i<n-1;i++)
			{
				if(s[i].ret_rn()==rn)			
				{
				 	flag=1;
				}
				if(flag==1)
				{
					s[i]=s[i+1];
				}
			}
			if(flag==0)
			{
				cout<<"\nEntered roll number is not found ";
			}
			else
            {
                cout<<"\n*** Data deleted successfully ***";
                n=n-1;
            }
		break;
		case 5:cout<<"\nExitting...\n";
            break;
		default:cout<<"\nWrong choice entered...try again...";
	}
	}while(choice!=5);
}
