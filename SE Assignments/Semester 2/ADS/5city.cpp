#include<iostream>
#include<string.h>
#include<stdlib.h>
#define MAX 30
using namespace std;

class node
{
  public:
    char data[MAX];
    int weight,value;
    node *next;
    node()
     {
        weight=value=0;
        next=NULL;
     }
};

class graph
{
  public:
    int n,i,j,k,key_s,key_e;
    int start,end,cost,min,key,sum;
    node *arr[MAX],*temp;
    int visited[MAX];
    graph();
    void accept();
    void display();
    void algo();
};

graph:: graph()
{
  sum=0;
  for(i=0;i<MAX;i++)
   {
      arr[i]=new node();
      visited[i]=0;
   }
}

void graph:: accept()
{
  char option='y';
  cout<<"\nEnter no of vertices:";
  cin>>n;
  if(n==0)
   {
     cout<<"\nGraph is empty";
     return;
   }
  for(i=0;i<n;i++)
   {
     cout<<"Enter name of city:";
     cin>>arr[i]->data;
     arr[i]->value=i;
   }
  cout<<"\nNames of cities:";
  for(i=0;i<n;i++)
   {
     cout<<"\n  "<<i<<"."<<arr[i]->data;
   }
  do
   {
     key_s=key_e=0;
     temp=NULL;
     cout<<"\nEnter starting and ending vertices number of edge:";
     cin>>start>>end;
     cout<<"Enter cost of edge:";
     cin>>cost;
     for(i=0;i<n;i++)
      {
        if(start==i)
           key_s=1;
        if(end==i)
           key_e=1;
      } 
     if(key_s==1 && key_e==1)
      {
        temp=new node();
        strcpy(temp->data,arr[end]->data);
        temp->weight=cost;
        temp->value=end;
        temp->next=arr[start]->next;
        arr[start]->next=temp;

        temp=NULL;
        temp=new node();
        strcpy(temp->data,arr[start]->data);
        temp->weight=cost;
        temp->value=start;
        temp->next=arr[end]->next;
        arr[end]->next=temp;
      }
     else
       cout<<"\nInvalid vertices\n";
     cout<<"\nDo you want to add more edges?(Y/N):";
     cin>>option;
   }while(option=='y' || option=='Y');
}

void graph:: display()
{
  temp=NULL;
  for(i=0;i<n;i++)
   {
      temp=arr[i];
      cout<<endl;
      while(temp!=NULL)
        {
          cout<<arr[i]->data<<" to "<<temp->data<<"-->Cost: "<<temp->weight<<endl;
          temp=temp->next;
        }
   }
}

void graph:: algo()
{
  temp=NULL;
  start=end=k=0;
  for(i=0;i<n;i++)
     visited[i]=0;
  visited[0]=1;
  for(i=0;i<(n-1);i++)
    {
     	min=999;
 	for(j=0;j<n;j++)
         {
              key=999;
              if(visited[j]==1)
               {
                   temp=arr[j]->next;
                   while(temp!=NULL)
                     {
                         if(!visited[temp->value] && temp->weight<key)
                           {
                              key=temp->weight;
			      k=temp->value;
                           }
                         temp=temp->next;
                     }
                   if(key<min)
                     {
                          min=key;
                          start=j;
                          end=k;
                     }
               }
         }   
       sum+=min;
       cout<<"\nPath:"<<arr[start]->data<<" to "<<arr[end]->data<<"-->Cost: ";
       visited[end]=1;
       temp=arr[start];
       while(temp->value!=end && temp!=NULL)
          temp=temp->next;
       cout<<temp->weight;
    }
  cout<<"\n\nCost of minimum spanning tree: "<<sum<<endl;
}

int main()
{
  int ch;
  char option;
  graph g;
  g.accept();
  do
   {
     cout<<"\n\n******* MENU ******\n1.Links to cities\n2.Shortest path\n";
     cout<<"Enter your choice:";
     cin>>ch;
     switch(ch)
      {
         case 1: cout<<"\n***** Links to cities *****\n";
                 g.display();
                 break;
         case 2: cout<<"\n***** Shortest paths *****\n";
                 g.algo();
                 break;
         default:cout<<"\nWrong choice";
                 break;
      }
     cout<<"\nDo you want to continue?(Y/N):";
     cin>>option;
   }while(option=='y' || option=='Y');
  return 0;
}

