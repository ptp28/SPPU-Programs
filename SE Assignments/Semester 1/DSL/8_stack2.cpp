#include <iostream>
#include<string.h>
using namespace std;
class Node
{
private:
    char chr;
    Node *previous;
public:
    Node *temp2,*temp,*top;
    void push(char chr)
    {
        if(top==NULL)
        {
            top=new Node;
            top->chr=chr;
            top->previous=NULL;
        }
        else
        {
            temp=new Node;
            temp->chr=chr;
            temp->previous=top;
            top=temp;
        }
    }
    char pop()
    {
        char c;
        c=top->chr;
        deletetop();
        return c;
    }
    void deletetop()
    {
        temp=top;
        top=top->previous;
        delete(temp);
    }
    void convert(char str[],Node *n)
    {
        char c;
        int i=0;
        while(str[i]!='\0')
        {
            if((str[i]>='A' && str[i]<='Z')||(str[i]>='a' && str[i]<='z'))
            {
                n->push(str[i]);
            }
            else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/')
            {
                if(top==NULL )
                {
                    push(str[i]);
                }
               	else if((top->chr=='*' || top->chr=='/'))
               	{
                    if(str[i]=='+' || str[i]=='-')
                    {
                        do
                        {
                            c=pop();
                            n->push(c);
                        }while(top!=NULL);
                        push(str[i]);
                    }
                    else
                        push(str[i]);
                }
                else if((top->chr=='+' || top->chr=='-'))
                {
                    if(str[i]!='*' || str[i]!='/')
                    {
                        push(str[i]);
                    }
                    else
                    {
                        do
                        {
                            c=pop();
                            n->push(c);
                            push(str[i]);
                        }while(top->previous!=NULL);
                    }
			
                }
            }
            i++;
        }
        while(top!=NULL)
        {
            c=pop();
            n->push(c);
        }
    }
    void evaluate(char postfix[])
    {
        char c;
        int i=0,j=0,data1,data2,val,store[100];
        for(i=0;postfix[i]!='\0';i++)
        {
            if((postfix[i]>='A' && postfix[i]<='Z')||(postfix[i]>='a' && postfix[i]<='z'))
            {
                cout<<"Enter the value for operand "<<postfix[i]<<" : ";
                cin>>postfix[i];
            }
        }
        cout<<"\n\n**********************************************************\n";
        for(i=0;postfix[i]!='\0';i++)
        {
            if((postfix[i]>='0' && postfix[i]<='9')||postfix[i]=='#')
            {
                push(postfix[i]);
            }
            else if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/')
            {
                c=pop();
                if(c=='#')
                {
                    data1=store[j];
                    j++;
                }
                else
                {
                    data1=(int)c-48;
                }
                c=pop();
                if(c=='#')
                {
                    data2=store[j];
                    j++;
                }
                else
                {
                    data2=(int)c-48;
                }
                switch(postfix[i])
                {
                    case '+' :  val=data2+data1;
                        break;
                    case '-' :  val=data2-data1;
                        break;
                    case '*' :  val=data2*data1;
                        break;
                    case '/' :  val=data2/data1;
                        break;
                }
                if(val>9)
                {
                    push('#');
                    store[j]=val;
                }
                else
                    push(val+48);
            }
        }
        c=pop();
        cout<<"\nAfter evaluation, The result of the entered expression is = ";
        if(c=='#')
        {
            cout<<store[j]<<endl;
        }
        else
            cout<<c<<endl;
    }
};
int main()
{
    Node n,n1;
    char str[100],str1[100];
    n.top=NULL;
    n1.top=NULL;
    cout<<"\n\n**********************************************************\n";
    cout<<"\nEnter an infix expression : ";
    cin.getline(str,100);
    int i=0,length=strlen(str),j,count=0;
    cout<<"\n\n**********************************************************\n";
    cout<<"\nThe entered infix expression is : "<<str<<endl;
    n1.convert(str,&n);
    for(i=length-1;i>=0;i--)
    {
        str1[i]=n.pop();
    }
    cout<<"\n\n**********************************************************\n";
    cout<<"\nThe postfix expression is : "<<str1<<endl<<endl;
    n.evaluate(str1);
    cout<<"\n\n**********************************************************\n";

}
