#include<iostream>
using namespace std;

const int MAX=50;

class node;
class tree;

class Stack
{
	int top;
 	node *info[MAX];
	public:
 	Stack()
	{
  		top=-1;
	}
 	void push(node *cnode)
 	{
 	 	top=top+1;
  		info[top]=cnode;
 	}
 	node* rtop()
 	{
  		return info[top];
 	}
 	node* pop()
 	{
  		if(!empty())
  		{
   			return info[top--];
  		}
  		return NULL;
 	}
 	int empty()
 	{
  		if(top==-1)
		{
   			return 1;
		}
  		else
		{
   			return 0;
		}
 	}
 	int isFull()
 	{
  		if(top==(MAX-1))
   		{
   			return 1;
		}
  		else
		{
   			return 0;
		}
 	}
};

class node
{
 	node *left,*right;
 	char data;
	public:
 	node()
	{	
 		left=right=NULL;
	}
 	node(char ch)
 	{
  		left=right=NULL;
  		data=ch;
 	}
 	friend class tree;
};

class tree
{
	public:
	node *root;
 	tree()
	{
  		root=NULL;
	}
 	void create(string str);
	int priority(char ch);
 	void inorderR(node *rnode);
 	void preorderR(node *rnode);
 	void postorderR(node *rnode);
 	void inorderNR();
 	void preorderNR();
 	void postorderNR();
};
int tree::priority(char ch)
{
 	switch(ch)
 	{
 		case '+':
 		case '-':
  			return 0;
  		break;
 		case '*':
 		case '/':
  			return 1;
  		break;
 		case '^':
  			return 2;
  		break;
 	}
 	return -1;
}
void tree::postorderNR()
{
 	Stack s1;
 	node *ptr=root;
 	int arr[MAX],i=-1,flag;
 	LOOP:
	while(ptr!=NULL)
 	{
  		s1.push(ptr);
  		arr[++i]=0;
  		if(ptr->right!=NULL)
 	 	{
   			s1.push(ptr->right);
   			arr[++i]=1;
  		}
  		ptr=ptr->left;
 	}
 	ptr=s1.pop();
 	flag=arr[i--];
 	while(flag==0 && i>=0)
 	{
  		cout<<" "<<ptr->data;
  		ptr=s1.pop();
  		flag=arr[i--];
 	}
 	if(flag==1 && i>=0)
 	{
  		goto LOOP;
 	}
 	cout<<" "<<ptr->data;
}
void tree::preorderNR()
{
 	Stack s1;
 	node *ptr=root;
 	while(ptr!=NULL)
 	{
 		cout<<" "<<ptr->data;
  		if(ptr->right!=NULL)
   			s1.push(ptr->right);
  		if(ptr->left!=NULL)
   			ptr=ptr->left;
  		else
   			ptr=s1.pop();
 	}
}
void tree::inorderNR()
{
 	node *ptr=root;
 	Stack s1;
 	X:
	while(ptr!=NULL)
 	{
  		s1.push(ptr);
  		ptr=ptr->left;
 	}
 	ptr=s1.pop();
 	while(ptr!=NULL)
 	{
  		cout<<" "<<ptr->data;
  		if(ptr->right!=NULL)
  		{
   			ptr=ptr->right;
   			goto X;
  		}
  		ptr=s1.pop();
 	}
}
void tree::inorderR(node* rnode)
{
 	if(rnode)
 	{
  		inorderR(rnode->left);
  		cout<<" "<<rnode->data;
  		inorderR(rnode->right);
 	}
}
void tree::preorderR(node* rnode)
{
 	if(rnode)
 	{
  		cout<<" "<<rnode->data;
  		preorderR(rnode->left);
  		preorderR(rnode->right);
 	}
}
void tree::postorderR(node *rnode)
{
 	if(rnode)
 	{
  		postorderR(rnode->left);
  		postorderR(rnode->right);
  		cout<<" "<<rnode->data;
 	}
}
void tree::create(string str)
{
 	Stack s1,s2;
 	int i=0;
 	char ch;
 	while(str[i]!='\0')
 	{
  		ch=str[i];
  		if(isalpha(ch))
  		{
   			node *temp=new node(ch);
   			s1.push(temp);
  		}
  		else
  		{
   			if(s2.empty())				//if 2nd stack is empty, 
   			{
    				node *temp=new node(ch);
    				s2.push(temp);
   			}
   			else if(priority(ch)>priority(s2.rtop()->data))
   			{
    				node *temp=new node(ch);
    				s2.push(temp);
   			}
   			else
   			{
    				while(!s2.empty() && priority(ch)<=priority(s2.rtop()->data))
    				{
     					node *op=s2.pop();
     					node *rchild=s1.pop();
     					node *lchild=s1.pop();
     					op->right=rchild;
     					op->left=lchild;
     					s1.push(op);
    				}
    				s2.push(new node(ch));
   			}
  		}
  		i++;
	}
 	while(!s2.empty())
 	{
  		node *op=s2.pop();
  		node *rchild=s1.pop();
  		node *lchild=s1.pop();
  		op->right=rchild;
  		op->left=lchild;
  		s1.push(op);
 	}
 	root=s1.pop();
}

int main()
{
 	tree t1;
 	string exp;
 	cout<<"\n____________________________________________\n";
 	cout<<"Enter an expression : ";
 	cin>>exp;
 	cout<<"\n____________________________________________\n";
 	cout<<"\nOriginal Expression : "<<exp;
 	cout<<"\n____________________________________________\n";
 	t1.create(exp);
 	cout<<"\nInorder Traversal Recursive: ";
 	t1.inorderR(t1.root);
 	cout<<"\nInorder Non-Recursive: ";
 	t1.inorderNR();
 	cout<<"\n____________________________________________\n";
 	cout<<"\nPreorder Traversal Recursive: ";
 	t1.preorderR(t1.root);
 	cout<<"\nPreorder traversal Non-Recursive: ";
 	t1.preorderNR();
 	cout<<"\n____________________________________________\n";
 	cout<<"\nPostorder Traversal recursive: ";
 	t1.postorderR(t1.root);
 	cout<<"\nPostorder Non-Recursive: ";
 	t1.postorderNR();
 	cout<<"\n____________________________________________\n";
 	return 0;
}

