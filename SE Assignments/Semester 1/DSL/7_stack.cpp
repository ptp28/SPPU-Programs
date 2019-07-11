#include <iostream>
using namespace std;
class Stack
{
private:
    char chr;
    Stack *previous;
public:
    Stack *temp2,*temp,*top;
    void push(char data)
    {
        if(top==NULL)
        {
            top=new Stack;
            top->chr=data;
            top->previous=NULL;
        }
        else
        {
            temp=new Stack;
            temp->chr=data;
            temp->previous=top;
            top=temp;
        }
    }
    void deletetop()
    {
        temp=top;
        top=top->previous;
        delete(temp);
    }
    int length(char arr[])
    {
        int i=0,count=0;
        while(arr[i]!='\0')
        {
            count++;
            i++;
        }
        return count;
    }
    void correct(char str[])
    {
        int i=0,j,count=0;
        while(str[i]!='\0')
        {
            if(str[i]==' ')
            {
                j=i;
                count++;
                while(str[j]!='\0')
                {
                    str[j]=str[j+1];
                    j++;
                }
            }
            if(str[i]>=65 && str[i]<=90)
            {
                str[i]=str[i]+32;
            }
            i++;
        }
    }
    char pop()
    {
        char c;
        c=top->chr;
        deletetop();
        return c;
    }
    void print(Stack *top)
    {
        cout<<"\nThe string in stack is : ";
        temp=top;
        while(temp!=NULL)
        {
            cout<<temp->chr;
            temp=temp->previous;
        }
    }
};
int main()
{
    Stack s;
    char str[100],str1[100];
    int i=0,length,j,count=0;
    s.top=NULL;
    cout<<"\n*********************************************** \n";
    cout<<"\nEnter a string : ";
    cin.getline(str,100);
    cout<<"\nThe sting is : "<<str;
    cout<<"\n\n*********************************************** \n";
    s.correct(str);
    while(str[i]!='\0')
    {
        s.push(str[i]);
        i++;
    }
    length=s.length(str);
    for(i=0;i<length;i++)
    {
        s.print(s.top);
        str1[i]=s.pop();
    }
    for(i=0;i<length;i++)
    {
        if(str[i]==str1[i])
        {
            count++;
        }
    }
    cout<<"\n\n*********************************************** \n";
    if(count==length)
    {
        cout<<"\n\n*** The string is palindrome ***\n";
    }
    else
    {
        cout<<"\n\n*** The string is not a palindrome ***\n";
    }
    cout<<"\n*********************************************** \n";
}


