#include<iostream>
#include<fstream>
using namespace std;
class student
{
	public:	int rollno;
		char name[50],div,add[50];
		void getdata()
		{
			cout<<"\nEnter rollno,name,div,address of student:";
			cin>>rollno>>name>>div>>add;
		}
		void putdata()
		{
			cout<<"\n"<<rollno<<" "<<name<<" "<<div<<" "<<add;
		}
};
class Database
{
	private:char fname[30];
		int n;
	public:	Database()
		{
			cout<<"\nEnter name of file to be opened:";
			cin>>fname;
		}
		void changefile();
		void create();
		void display();
		void addrec();
		void search(int);
		void modify(int);
		void del(int);
		void menu();
};
void Database::changefile()
{
	ifstream fin;
	student s;
	int ans;
	fin.open(fname);
	if(fin)
	{
		cout<<"\nFile Exists";
		cout<<"\nContents of File";
		while(fin.read((char *)&s,sizeof(s)))
		{
			s.putdata();
		}
		cout<<"\nWould you like to 1.add records or 2.overwrite them or 3.change file 4.Continue:";
		cin>>ans;
		switch(ans)
		{
			case 1:	addrec();
				break;
			case 2:	create();
				break;
			case 3:	cout<<"\nEnter new file name:";
				cin>>fname;
				break;
			case 4:	break;
		}
	}
	else
	{
		cout<<"\nFile Does Not Exist";
		create();
	}
	fin.close();
}
void Database::create()
{
	ofstream fout;
	student s;
	fout.open(fname);
	if(fout.fail())
	{
		cout<<"\nError Opening File";
	}
	else
	{
		cout<<"\nEnter number of records:";
		cin>>n;
		for(int i=0;i<n;i++)
		{
			s.getdata();
			fout.write((char *)&s,sizeof(s));
		}
	}
	fout.close();
}
void Database::display()
{
	ifstream fin;
	student s;
	fin.open(fname);
	if(fin.fail())
	{
		cout<<"\nError Opening File";
	}
	else
	{
		while(fin.read((char *)&s,sizeof(s)))
		{
			s.putdata();
		}
	}
	fin.close();
}
void Database::addrec()
{
	ofstream fout;
	student s;
	fout.open(fname,ios::app);
	if(fout.fail())
	{
		cout<<"\nError Opening File";
	}
	else
	{
		cout<<"\nEnter number of records to be added:";
		cin>>n;
		for(int i=0;i<n;i++)
		{
			s.getdata();
			fout.write((char *)&s,sizeof(s));
		}
	}
	fout.close();
}
void Database::search(int a)
{
	int flag=0;
	ifstream fin;
	student s;
	fin.open(fname);
	if(fin.fail())
	{
		cout<<"\nError Opening File";
	}
	else
	{
		while(fin.read((char *)&s,sizeof(s)))
		{
			if(a==s.rollno)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
			s.putdata();
		else
			cout<<"\nRecord Not Found";
	}
	fin.close();
}
void Database::modify(int r)
{
	int flag=0,ch,pos=0;
	fstream finout;
	student s;
	finout.open(fname,ios::in|ios::out|ios::binary);
	if(finout.fail())
	{
		cout<<"\nError Opening File";
	}
	else
	{
		while(finout.read((char *)&s,sizeof(s)))
		{
			if(r==s.rollno)
			{
				flag=1;
				break;
			}
			else
			{
				pos++;
			}
		}
		if(flag==1)
		{
			cout<<"\nEnter what is to be modified:1.Rollno 2.Name 3.Div 4.Address:";
			cin>>ch;
			switch(ch)
			{
				case 1:	cout<<"\nEnter new rollno:";
					cin>>s.rollno;
					finout.seekp(pos*sizeof(s),ios::beg);
					finout.write((char *)&s,sizeof(s));
					break;
				case 2:	cout<<"\nEnter new name:";
					cin>>s.name;
					finout.seekp(pos*sizeof(s),ios::beg);
					finout.write((char *)&s,sizeof(s));
					break;
				case 3:	cout<<"\nEnter new divison:";
					cin>>s.div;
					finout.seekp(pos*sizeof(s),ios::beg);
					finout.write((char *)&s,sizeof(s));
					break;
				case 4:	cout<<"\nEnter new address:";
					cin>>s.add;
					finout.seekp(pos*sizeof(s),ios::beg);
					finout.write((char *)&s,sizeof(s));
					break;
			}
		}
		else
		{
			cout<<"\nRecord Not Found";
		}
	}
	finout.close();
}
void Database::del(int a)
{
	int flag=0;
	fstream fin,fout;
	student s;	
	fin.open(fname,ios::in|ios::binary);
	fout.open("temp",ios::out|ios::binary);
	if(fin.fail() || fout.fail())
	{
		cout<<"\nError Opening File";
	}
	else
	{
		while(fin.read((char *)&s,sizeof(s)))
		{
			if(a!=s.rollno)
			{
				fout.write((char*)&s,sizeof(s));
			}
			else
			{
				flag=1;
			}
		}
		if(flag==1)
		{
			fin.close();
			fout.close();

			remove(fname);
			rename("temp",fname);
			cout<<"\nRecord Deleted";
		}
		else
		{
			cout<<"\nRecord Not Found";
		}
	}
}
void Database::menu()
{
	int ch,r,m,srno;
	do
	{
		cout<<"\nEnter your choice 1.Create 2.Display 3.Addrec 4.Search 5.Modify 6.Delete 7.Exit:";
		cin>>ch;
		switch(ch)
		{
			case 1:	changefile();
				break;
			case 2:	display();
				break;
			case 3:	addrec();
				break;
			case 4:	cout<<"\nEnter rollnumber to be searched:";
				cin>>r;
				search(r);
				break;
			case 5:	cout<<"\nEnter rollnumber to be modified:";
				cin>>m;
				modify(m);
				break;
			case 6:	cout<<"\nEnter rollnumber to be deleted:";
				cin>>srno;
				del(srno);
				break;
		}
	}while(ch!=7);
}
int main()
{
	Database obj;
	obj.menu();
}
