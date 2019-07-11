#include <iostream>
using namespace std;
#define MAX 10
int mat[MAX][MAX]={0};
class q;
class node
{
 public:
 	int data;
 	node *next;
};

class stack
{
  public:
  	node *head=NULL;
  int isempty()
  {
  	if(head==NULL)
  		return 1;
  	else
  		return 0;
  }
  void push(int data)
  {
    node *temp=new node;
    temp->data=data;
    temp->next=NULL;
    if(head==NULL)
    	head=temp;
    else
    {
      head->next=temp;
      head=temp;
    }
  }  
};

class graphs
{
 int R=-1,F=-1; 
 int acc[10][3]={0};
 int visited[10]={0};
 int vertices,i31,i32;
 int data[30];
 public:
 node *start[10]={NULL};
 
 graphs(int edges)
 {
 for(int i=0;i<edges;i++)
  {
   start[i]=NULL;
  }
 }
 void accept(int vertice,int edges)
 {
  acc[10][2]=acc[edges][2];
  vertices=vertice;
  int i,j,flag=0;
  for(i=0;i<edges;i++)
  {
  cout<<"Enter vertices of edge: ";
   for(j=0;j<2;j++)
   {
    a:
    cin>>acc[i][j];
    if(acc[i][j]>edges)
    {
     	cout<<"\tInvalid vertex entered. Enter again: ";
    	goto a;
    }
   }
  }
  i31=acc[3][0];
  i32=acc[3][1];
 }

 void insert(int a,int b)
 {
  node *temp,*temp1;
  temp=new node;
  temp->data=a;
  temp->next=NULL;
  if(start[b]==NULL)
  	start[b]=temp;
  else
  {
   temp1=start[b];
   while(temp1->next!=NULL)
   	temp1=temp1->next;
   temp1->next=temp;
  }
 }




void li(int vertices)
{
 int i=0,j=0;
 while(j<vertices)
 {
  cout<<i<<"->";
  while(start[i]!=NULL)
  {
   cout<<start[i]->data<<"->";
   start[i]=start[i]->next;
  }
  cout<<"NULL"<<endl;
  i++;
  j++;
 }
}

int empty()
 {
  if(R==-1)
  	return 1;
  else 
  	return 0;
 }
 
 void insertq(int x)
 {
 if(empty())
 	R=F=0;
 else
 	R++;
 data[R]=x;
 }
 
 int deleteq()
 {
  int x=data[F];
  if(R==F)
  	R=F=-1;
  else 
  	F=F+1;
  return x;
 }






 void adjlist(int vertices,int edges)
 {
  node *temp,*temp1;
  int i,j,a,b;
  
  for(i=0;i<edges;i++)
  {
   for(j=0;j<1;j++)
   {
    a=acc[i][j];
    b=acc[i][j+1];
    insert(a,b);
    insert(b,a);
   }
  }
 }
  
 void adjmat(int vertices,int edges)
 {
  int a,b,i,j;
  mat[10][10]=mat[vertices][vertices];
  acc[3][0]=i31;
  acc[3][1]=i32;
  
  for(i=0;i<edges;i++)
  {
   for(j=0;j<1;j++)
   {
    a=acc[i][j];
    b=acc[i][j+1];
    mat[a][b]=1;
    mat[b][a]=1;
   }
  }
 }
 
 void dfsrecmat(int i,int n)
 {
  int j;
  cout<<i<<" ";
  visited[i]=1;
  for(j=0;j<n;j++)
  	if(!visited[j] && mat[i][j]==1)
  		dfsrecmat(j,vertices);
 }
 
 void matrix(int vertices)
 {
  int i,j;
  for(i=0;i<vertices;i++)
  {
  	for(j=0;j<vertices;j++)
  	{
  	cout<<mat[i][j]<<" ";
  	}
  	cout<<endl;
  }
 }
 void dfsreclist(int i)
 {
  node *temp;
  cout<<i<<" ";
  temp=start[i];
  visited[i]=1;
  while(temp!=NULL)
  {
   i=temp->data;
   if(!visited[i])
   	dfsreclist(i);
    temp=temp->next;
  }
 }
 
 void zero()
 {
 for(int i=0;i<10;i++)
  {
   visited[i]=0;
  }
 }

 void bfslist(int vertices,int i)
 {
  R=-1;F=-1;
  int visited[10]={0},p=0,c=0,q;
  data[30]={0};
  insertq(i);
  visited[i]=1;
  
  while(p<vertices)
  {
   while(start[data[i]]!=NULL)
   {
    if(visited[start[data[i]]->data]!=1)
    {
     insertq(start[data[i]]->data);
     visited[start[data[i]]->data]=1;
    }
    start[data[i]]=start[data[i]]->next;
   }i++;
   p++;
  } 
  for(i=0;i<vertices;i++)
  {
   cout<<data[i]<<" ";
  }

 }
 
 void bfs(int vertices,int v)
 {
  R=-1;F=-1;
  int visited[MAX]={0},i;
  for(i=0;i<vertices;i++)
  	visited[i]=0;
  insertq(v);
  cout<<v<<" ";
  visited[v]=1;
  while(!empty())
  {
    v=deleteq();
    for(i=0;i<vertices;i++)
    {
    	if(visited[i]==0 && mat[v][i]!=0)
    	{
    	 insertq(i);
    	 visited[i]=1;
    	 cout<<i<<" ";
    	}
    }
  }
 }
};


int main()
{
 
 int vertices,choice,edges;
 cout<<"Enter the number of vertices: ";
 cin>>vertices;
 cout<<"Enter the number of edges: ";
 cin>>edges;
 graphs g(edges);
 g.accept(vertices,edges);
 g.adjmat(vertices,edges);
 g.adjlist(vertices,edges);
 do
 {
 cout<<"\nPress 1.Display matrix 2.Display list 3.DFS recurssion matrix 4.DFS list\n";
 cout<<"5.BFS matrix 6.BFS list 7.Exit: ";
 cin>>choice;
 switch(choice)
 {
 case 1:
 cout<<"The matrix is: \n";
 g.matrix(vertices);
 break;
 case 2:
 cout<<"The lists are: \n";
 g.li(vertices);
 break;
 case 3:
 cout<<"\nDFS of matrix is: \n";
 g.dfsrecmat(0,vertices);
 g.zero();
 break;
 case 4:
 cout<<"\n\nDFS of list by recurssion is: \n";
 g.dfsreclist(0);
 break;
 case 5:
 cout<<"\n\nBFS of matrix by queue is: \n";
 g.bfs(vertices,0);
 break;
 case 6:
 cout<<"\n\nBFS of list by queue is: \n";
 g.bfslist(vertices,0);
 break;
 case 7:
 break;
 }
 }while(choice!=7);
}
