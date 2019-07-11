#include<iostream>
using namespace std;

class node
{
	public :
	int data;
	node *lchild;
	node *rchild;

};
class stack
{
	private:
	node* chr;
	stack *previous;
	public:
	stack *temp2,*temp,*top;	
    	void push(node* data)
    	{
        	if(top==NULL)
        	{
       	     		top=new stack;
            		top->chr=data;
            		top->previous=NULL;
        	}
        	else
        	{
            		temp=new stack;
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
    	node* pop()
    	{
        	node* c;
        	c=top->chr;
        	deletetop();
        	return c;
    	}
    	node* r_top()			//return top
    	{
    		return top->chr;
    	}
    	int empty()
    	{
    		if(top==NULL)
    			return 1;
    		return 0;
    	}
};

node* root=NULL;
node* newroot=NULL;

void create(int x)
{
	node* current=NULL;
	
	if(root==NULL)
	{
		root=new node;
		root->data=x;
		root->lchild=NULL;
		root->rchild=NULL;
	}
	else
	{
		current=root;
		while(1)		//infinite loop
		{
			if(x<current->data)
			{
				if(current->lchild==NULL)
				{
					current->lchild=new node;
					current->lchild->data=x;
					current->lchild->lchild=NULL;
					current->lchild->rchild=NULL;
					return;
				}
				else
				{
					current=current->lchild;
				}
			}
			else if(x==current->data)
			{
				cout<<"\n!!! Repeated value is found !!!";
				break;
			}
			else if(x>current->data)
			{
				
				if(current->rchild==NULL)
				{
					current->rchild=new node;
					current->rchild->data=x;
					current->rchild->lchild=NULL;
					current->rchild->rchild=NULL;
					return;
				}
				else
				{
					current=current->rchild;
				}
			}	
		
		}
	}
}


/*void inorder(node* root)
{
	stack s;
	node* current=root;
	while(1)		//infinite loop
	{
		while(current!=NULL)
		{
			s.push(current);
			current=current->lchild;			
		}	
		if(s.empty())		//is stack empty ? will hppn if all nodes are on right thatis when left side is null
			return;			//Go back to function call
		//current=s.r_top();
		current=s.pop();
		cout<<current->data<<"  ";
		current=current->rchild;
	}
}*/

void inorder(node *root)
{
	stack s;
	node *current=root;
	if(current)
	{
	inorder(current->lchild);
	cout<<current->data;
	inorder(current->rchild);
	}
}

int maxDepth(node* root1) 
{
   if (root1==NULL) 
       return 0;
   else
   {
       int lDepth = maxDepth(root1->lchild);
       int rDepth = maxDepth(root1->rchild);
 
       if (lDepth > rDepth) 
           return(lDepth+1);
       else return(rDepth+1);
   }
} 

int search(node* root,int key)
{
	node* current=NULL;
	node* parent=NULL;
	
	if(root==NULL)
	{
		cout<<"The tree is empty.\n";
		return 0;
	}
	else
	{
		current=root;
		while(1)
		{
			if(key<current->data)
			{
				if(current->lchild==NULL)
				{	
					return 0;
				}
				else if(current->data==key)
				{
					return 1;
				}
				current=current->lchild;
			}
			else
			{
				if(current->rchild==NULL)
				{		
					return 0;
				}
				else if(current->data==key)
				{
					return 1;
				}
				current=current->rchild;
			}
		}
	}
}
void mirror(node* root)
{
	if(root==NULL)
	{
		return;
	}
	else
	{
		node *temp;
		mirror(root->lchild);
		mirror(root->rchild);
		temp=root->lchild;
		root->lchild=root->rchild;
		root->rchild=temp;
	}
}
    

int main()
{
	int x,y;
	cout<<"\nHow many nodes do you want to add - ";
	cin>>x;
	cout<<"Enter the root value of tree : \n";
	cin>>y;
	create(y);
	while(x--)
	{
		
		cout<<"Enter the value to be inserted ::\n";
		cin>>y;
		create(y);
	}
	
	
	do
	{
	cout<<"\n\nMain Menu \n1.Add node\n2.Display Tree\n3.Search\n4.Mirror\n5.Depth\n6.Exit\nEnter your choice : ";
	cin>>x;
	switch(x)
		{
			case 1:
			cout<<"Enter the value to be inserted ::\n";
			cin>>y;
			create(y);
			break;
			case 2:
			cout<<"The inorder of tree is ::\n";
			inorder(root);
			cout<<endl;
			break;
			case 3:
			cout<<"Enter the value to be searched::\n";
			cin>>y;
			y=search(root,y);
			if(y==1)
			cout<<"THE VALUE IS PRESENT IN BST\n";
			else
			cout<<"THE VALUE IS NOT PRESENT IN BST\n";
			break;
			case 4:
			cout<<"The inorder of MIRROR tree is ::\n";
			mirror(root);
			inorder(root);
			cout<<endl;
			mirror(root);
			break;
			case 5:
			cout<<"The max DEPTH of the tree is :: "<<maxDepth(root)<<endl;
			break;
		}	
	}while(x!=6);
	return 0;
	
}  
