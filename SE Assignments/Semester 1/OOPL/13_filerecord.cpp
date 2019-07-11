#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
class people
{
    public:
    char name[25];
    long int ph;
    void get()
    {
        int i=0,m;
        people p;
        ofstream of;
        of.open("peopledatabase.txt", ios::app);
        if(check())
        {
            cout<<"\nHow many records do you want to enter : ";
            cin>>m;
            for(i=0;i<m;i++)
            {
                cout<<"\nEnter name of student : ";
                cin>>p.name;
                cout<<"\nEnter the phone number of student : ";
                cin>>p.ph;
                of.write((char*)&p,sizeof(p) );
            }
        }
        of.close();
    }
    void show()
    {
        people p;
        ifstream fi;
        fi.open("peopledatabase.txt");
        if(check())
        {
            cout<<"\n\nNAME\t"<<"PHONE NUMBER\n";
            while( fi.read((char*)&p,sizeof(p)))
            {
                cout<<p.name<<"\t"<<p.ph<<"\n";
            }
        }
        fi.close();
    }
    int check()
    {
        ifstream fi;
        if(fi.fail())
        {
            cout<<"\n!!! There was an Error in opening the file !!!"<<endl;
            return 0;
        }
        else
            return 1;
        fi.close();
        
    }
};
void search_name()
{
    char temp[25];
    cout<<"\nEnter name to be searched : ";
    cin>>temp;
    int flag=0;
    ifstream fi;
    people p;
    fi.open("peopledatabase.txt");
    if(p.check())
    {
        while( fi.read((char*)&p,sizeof(p)))
        {
            if(strcmp(p.name,temp)==0)
            {
                    cout<<"*** The record is found ***"<<endl;
                    cout<<"\n\nNAME\t"<<"PHONE NUMBER\n";
                    cout<<p.name<<"\t"<<p.ph<<"\n";
                    flag=1;
            }
        }
        if(flag==0)
        {
            cout<<"\n!!! The record not found !!!"<<endl;
        }
    }
    fi.close();
}
void search_ph()
{
    int flag=0;
    ifstream fi;
    long int temp;
    people p;
    cout<<"\nEnter the number to be searched : ";
    cin>>temp;
    fi.open("peopledatabase.txt");
    if(p.check())
    {
        while( fi.read((char*)&p,sizeof(p)))
        {
            if(p.ph==temp)
            {
                cout<<"\n*** The Record is found ***"<<endl;
                cout<<"\n\nNAME\t"<<"PHONE NUMBER\n";
                cout<<p.name<<"\t"<<p.ph<<"\n";
                flag=1;
            }
	    }
        if(flag==0)
	    {
            cout<<"\n!!! The record cannot be found !!!"<<endl;
	    }
    }
    fi.close();
}
void modify()
{
    char temp[100];
    int flag=0,posn=0;
    people p;
    fstream fi;
    cout<<"\nEnter name whose phone number you want to edit : ";
    cin>>temp;
    fi.open(("peopledatabase.txt"));
    if(p.check())
	{
        while(fi.read((char*)&p,sizeof(p)))
        {
            if(strcmp(p.name,temp)==0)
            {
                cout<<"\n*** The record is found ***"<<endl;
                cout<<"\nEnter new phone number for "<<p.name<<" : ";
                cin>>p.ph;
                fi.seekp(posn*sizeof(p),ios::beg);
                fi.write((char*)&p,sizeof(p));
                flag=1;
            }
            else
            {
                posn++;
            }
        }
        if(flag==1)
        {
            cout<<"\n*** Record is Edited ***"<<endl;
        }
        else
        {
            cout<<"\n!!! Record not found !!!"<<endl;
        }
    }
    fi.close();
}
int main()
{
  int ch,i=0;
  people p;
  do
  {
      cout<<"\n*** MENU ****";
      cout<<"\n1.Create Record\n2.Display Records\n3.Search by name\n4.Search by ph no.\n5.Edit phone number\n6.Exit\nEnter your choice : ";
      cin>>ch;
      switch(ch)
      {
          case 1:p.get();
              break;
          case 2:p.show();
              break;
          case 3:search_name();
              break;
          case 4:search_ph();
              break;
          case 5:modify();
              break;
          case 6: cout<<"Exitting..."<<endl;
              break;
          default: cout<<"\n!!! Wrong choice entered...Try again !!!"<<endl;
      }
  }while(ch!=6);
}

              
        
