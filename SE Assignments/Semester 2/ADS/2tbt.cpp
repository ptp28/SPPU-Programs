#include <iostream>
using namespace std;

class node
{
    node *left,*right;
    int data;
    bool lbit,rbit;
    public:
    node()		//constructor
    {
        left=NULL;
        right=NULL;
        rbit=lbit=0;
    }
    node(int d)		//para const
    {
        left=NULL;
        right=NULL;
        rbit=lbit=0;
        data=d;
    }
    friend class TBT;		//
};

class TBT
{
    node *root;
    public:
    TBT()		//const
    {
        root=new node();		//here we get the dummy node
        root->left=root;	
        root->rbit=1;
        root->lbit=0;
        root->right=root;
    }
    void create();
    void insert(int data);
    node* inorder_suc(node *);
    void inorder_traversal();
    node* preorder_suc(node *c);
    void preorder_traversal();
};

void TBT::preorder_traversal()
{
    node *c=root->left;
    while(c!=root)
    {
        cout<<" "<<c->data;
        c = preorder_suc(c);
    }
}
node *TBT::preorder_suc(node *c)
{
    if(c->lbit==1)
    {
        return c->left;
    }
    while(c->rbit==0)
    {
        c=c->right;		//linked
    }
    return c->right;
}
void TBT::inorder_traversal()
{
    node *c=root->left;
    while(c->lbit==1)
        c=c->left;
    while(c!=root)
    {
        cout<<" "<<c->data;
        c=inorder_suc(c);
    }
}
node* TBT::inorder_suc(node *c)
{
    if(c->rbit==0)
        return c->right;
    else
        c=c->right;
    while(c->lbit==1)
    {
        c=c->left;
    }
    return c;
}
void TBT::create()
{
    int n;
    cout<<"\nEnter number of nodes:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int info;
        cout<<"\nEnter data: ";
        cin>>info;
        insert(info);
    }
}
void TBT::insert(int data)
{
    if(root->left==root&&root->right==root) //no node in tree
    {
        node *p=new node(data);
        p->left=root->left;
        p->lbit=root->lbit; //0
        p->rbit=0;
        p->right=root->right;
        root->left=p;
        root->lbit=1;		//promotion from thread to child
        cout<<"\nInserted start"<<data;		//here we get the actual root
        return;
    }
    node *cur;
    cur=root->left;
    while(1)
    {
        if(cur->data<data)   //insert right
        {
            node *p=new node(data);
            if(cur->rbit==0)
            {
                p->right=cur->right;
                p->rbit=cur->rbit;
                p->lbit=0;
                p->left=cur;
                cur->rbit=1;
                cur->right=p;
                cout<<"\nInserted right "<<data;
                return;
            }
            else
                cur=cur->right;
        }
        if(cur->data>data) //insert left
        {
            node *p=new node(data);
            if(cur->lbit==0)
            {
                p->left=cur->left;
                p->lbit=cur->lbit;
                p->rbit=0;
                p->right=cur; //successor
                cur->lbit=1;
                cur->left=p;
                cout<<"\nInserted left"<<data;
                return;
            }
            else
                cur=cur->left;
        }
    }
}


int main()
{
    TBT t1;
    int value;
    int choice;
    do
    {
        cout<<"\n1.Create Tree\n2.Insert into tree\n3.Preorder\n4.Inrder\n0.Exit\nEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                t1.create();
                break;
            case 2:
                cout<<"\nEnter Number(data): ";
                cin>>value;
                t1.insert(value);
                break;
            case 3:
                cout<<"\nPreorder traversal of TBT:";
                t1.preorder_traversal();
                break;
            case 4:
                cout<<"\nInoder Traversal of TBT:";
                t1.inorder_traversal();
                break;
            default:
                cout<<"\nWrong choice";
        }
        
    }while(choice!=0);
    return 0;
}
