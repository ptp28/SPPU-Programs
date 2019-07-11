#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
class File
{
    char ch;
    string str;
    public:
    File()
    {
	ofstream fout("lettercheck.txt");
	if(fout.fail()==1 )
            cout<<"\n!!! There was an Error in opening the file !!!"<<endl;
        else
            cout<<"\n*** The file was opened successfully ***"<<endl;
	fout.close();
    }
    void input()
    {
        char ch;
        ofstream fout("lettercheck.txt",ios::app);
        cout<<"\nEnter a paragraph : ";
        do
        {
            getline(cin,str);
            fout<<str<<endl;
        }while(str.length()>0);
        fout.close();
    }
    void output()
    {
        ifstream f("lettercheck.txt");
        cout<<"\nThe text written in file is : "<<endl;
        while(!f.eof())
        {
            f.get(ch);
            cout<<ch;
        }
        f.close();
    }
    void lettercheck()
    {
        int vow=0,spa=0,character=0,line=0;
        ifstream f;
        f.open("lettercheck.txt");
        while(f.eof()==0)
        {
            f.get(ch);
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
            {
                vow++;
            }
            if(ch==' ')
            {
                spa++;
            }
            if((int(ch)>=65 && int(ch)<=90) || (int(ch)>=97 && int(ch)<=122))
            {
                character ++;
            }
            if(ch=='\n' || ch=='.')
            {
                line++;
            }
        }
        f.close();
        cout<<"\n\n\n\t***** *** *****\n";
        cout<<"The number of vowels = "<<vow<<endl;
        cout<<"The number of spaces = "<<spa<<endl;
        cout<<"The number of characters = "<<character<<endl;
        cout<<"The number of lines = "<<line-2<<endl;
    }
};
int main()
{
    File f;
    char ch;
    f.input();
    f.output();
    f.lettercheck();
}

          
