#include<iostream>
#include<string.h>
#define MAX 10
using namespace std;

class HashTable
{
	public : char name[15];
			 int chain;
			 void show()
			 {
				cout << "\n "<<"\t"<<name<<"\t"<<chain;
			 }
};

class Database
{
	private : HashTable ht[MAX];
			  int n1,n2;
			  
	public  : Database()
			  {
				n1 = 0;
				for(int i=0;i<MAX;i++)
				{
					ht[i].chain = -1;
					strcpy(ht[i].name,"----------");						
				}
			  }
			  
			  void menu();
			  void add_chain_without_rep();
			  void display(HashTable[]);
			  int division_method(char []);			  
			  void search(char name[]);	
};

void Database :: search(char sname[])
{
	int key;
	
	key = division_method(sname);
	
	while(1)
	{
		if ( strcmp(ht[key].name,sname) == 0 )
		{
			cout << "\n Record found ";
			ht[key].show();
			break;
		}
		else
		{
			if(ht[key].chain == -1)
			{
				cout << "\n Search Record not found ";
				break;
			}
			else
				key = ht[key].chain;
		}
	}
}

int Database :: division_method(char name[])
{
	return name[0] % 10;
}
void Database :: display(HashTable ht[])
{
	cout << "\nKEY \t WORD \t CHAIN \n";
	for(int i=0;i<MAX;i++)
		cout << "\n "<<i<<"\t"<<ht[i].name<<"\t"<<"\t"<<ht[i].chain;
}



void Database :: add_chain_without_rep()
{
	char ch;
	int oldkey,key;
	HashTable temp;
	
	do
	{
		temp.chain=-1;
		cout << "\n Enter the word : ";
		cin >> temp.name;
		
		if (n1 == MAX)		//means table is full
		{
			cout << "\n Hast table is full ";
			break;
		}
		else
		{
			key = division_method(temp.name);
			cout <<  key;
			if( strcmp(ht[key].name,"----------") == 0 )
			{
				ht[key] = temp;
				n1++;
				cout << "\n Record "<<temp.name<< " inserted ...";
			}
			else
			{
				cout << "\n Collision has occured \n";
				// find next empty slot
				oldkey = key;

				while(1)
				{
					if( strcmp(ht[key].name,"----------") == 0 )
					{
						ht[key] = temp;
						n1++;
						break;
					}
					else
					{
						key = (key + 1) % MAX;
					}
				}
				// built the chain
			
				while(1)
				{
					if( ht[oldkey].chain == -1)
					{
						ht[oldkey].chain = key;
						break;
					}
					else
					{
						oldkey = ht[oldkey].chain;
					}
				}
			}
		}

		cout << "\n Do u want to add more rec (y.n) => ";
		cin >> ch;

	}while(ch!='n');		
}

void Database :: menu()
{
	int ch2;
	char sname[15];

	do	
	{
		cout << "\n 1 : Add record";
		cout << "\n 2 : Display hashtable";
		cout << "\n 3 : Search a word ";
		cout << "\n 4 : Exit ";
		cout << "\n Enter u choice : ";
		cin >> ch2;
		switch(ch2)
		{
			case 1 : add_chain_without_rep();
				 break;
			case 2 : cout << "\nHASH TABLE FOR CHAIN WITHOUT REP.\n";
				 display(ht);
				 break;
			case 3 : cout << "\n Enter the word to be searched : ";
				 cin >> sname;
				 search(sname);
				 break;
		}
	}while(ch2!=4);
}

int main()
{
	Database obj;
	obj.menu();
}

