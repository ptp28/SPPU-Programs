#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

class book
{
        int bookid,stock;
        float price;
        char *bookname,*bookauthor;
	public:
	book()
	{
	}
	book(int bookid,char bookname[],char bookauthor[],int stock,float price)
	{
	        this->bookid=bookid;
	        this->bookname=new char(strlen(bookname)+1);
	        this->bookauthor=new char(strlen(bookauthor)+1);
	        strcpy(this->bookname,bookname);
	        strcpy(this->bookauthor,bookauthor);
	        this->stock=stock;
	        this->price=price;
	}
	void display ()
	{
	        cout<<"\n"<<setw(30)<<"BookID: "<<bookid;
	        cout<<"\n"<<setw(30)<<"Book Name: "<<bookname;
	        cout<<"\n"<<setw(30)<<"Author: "<<bookauthor;
	        cout<<"\n"<<setw(30)<<"Stock Available: "<<stock;
	        cout<<"\n"<<setw(30)<<"Price: "<<price<<endl;
	}
	int buy(char x[],char z[],int y)
	{
		int i,k,a;
			if(strcmp(bookname,x)==0 && strcmp(bookauthor,z)==0)
			{
				cout<<"The book is available.\n";
				if(y<=stock)
				{
					cout<<y<<" copies are available.\n";k=1;
				}
				else
				{
					cout<<"Insufficient stock available.\nThe number of copies available are :"<<stock<<endl;
					k=0;
				}	
			}
			else 
				return 1;
		if(k==1)
		{
			stock=stock-y;
			cout<<"The cost of "<<y<<" copies is :: "<<(y*price)<<endl;
			cout<<"The stock is updated to : "<<stock<<endl;
		}
		else
		{
			cout<<"The stock is less then your request.\n";
			cout<<"Press 1 to buy all the stock available.\nOr Press 0 to cancel the request.\n";
			cin>>a;
			if(a==1)	
			{
				cout<<"The cost of "<<stock<<" books is :: "<<(stock*price)<<endl;
				stock=0;
			}		
		}
	}
	int search(char a[],char b[])
	{
		if(strcmp(bookname,b)==0 && strcmp(bookauthor,a)==0)
		{
			cout<<"\nThe book is available.\n";
			return 1;
		}
		else
			return 0;
	}
};
int main()
{

        int bookid,stock;
        float price;
        char bookname[30];
        char bookauthor[30];
        int i,x,y,k,n;
        cout<<"**********************************************\n";
        cout<<"\nEnter the number of Book entries to be done in database :";
        cin>>x;
        book *b[x];
        for(i=0;i<x;i++)
        {
		cout<<"**********************************************\n";
                cout<<"\nEnter the BookID: ";
                cin>>bookid;
                cout<<"Enter the Book Name: ";
                cin>>bookname;
                cout<<"Enter the Book Author: ";
                cin>>bookauthor;
                cout<<"Enter the stock: ";
                cin>>stock;
                cout<<"Enter the Book Price: ";
                cin>>price;
                cout<<endl;
                b[i]=new book(bookid,bookname,bookauthor,stock,price);
	}        
        do 
        {
		cout<<"**********************************************\n";
        	cout<<"\n1.Display Database\n2.Search for a book\n3.Check Availability and Purchase books\n4.Exit\nEnter your choice :";
        	cin>>n;
        	switch (n)
       		{ 
			case 1:
				for(i=0;i<x;i++)
                		{
					cout<<"**********************************************\n";
			                b[i]->display();
			                cout<<"**********************************************\n";
		                }
		                break;
			case 2:
				cout<<"**********************************************\n";
				cout<<"\nEnter the book title and book author:";
				cout<<"\nEnter the book name :";cin>>bookname;
				cout<<"Enter author name :";cin>>bookauthor;
				for(i=0;i<x;i++)
				{
					k=b[i]->search(bookauthor,bookname);
				}
				if(k==0)
					cout<<"Book is not available.\n";
				cout<<"**********************************************\n";
				break;	
			case 3:
				cout<<"**********************************************\n";
				cout<<"\nEnter the book name, author name and number of copies to be purchased:\n";
				cout<<"Book name: ";cin>>bookname;
				cout<<"Book author: ";cin>>bookauthor;
				cout<<"Copies required: ";cin>>y;
				for(i=0;i<x;i++)
				{
					k=b[i]->buy(bookname,bookauthor,y);
					if(k==1)
						break;
				}
				if(k==0)
					cout<<"Book is not available.\n";
				cout<<"**********************************************\n";
				break;
			case 4:
				cout<<"**********************************************\n";
				cout<<"\nExitting...\n";
				cout<<"**********************************************\n";
				break;
			default:
				cout<<"**********************************************\n";
				cout<<"\n!!! Wrong choice entered !!!\n";
				cout<<"**********************************************\n";
				break;
		}
	}while(n!=4);
}
