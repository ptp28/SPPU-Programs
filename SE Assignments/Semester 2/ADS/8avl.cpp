#include <iostream>
#include<iomanip>
#include<string.h>
using namespace std;

class node
{
 char key[20];
 char meaning[20];
 node *left,*right;
 int height;
public:
 node()
{
  left=right=NULL;
  height=1;
  strcpy(meaning,"");
  strcpy(key,"-1");
}
 node(char key[],char meaning[])
 {
  strcpy(this->key,key);
  strcpy(this->meaning,meaning);
  left=right=NULL;
  height=1;
 }
 void print()
 {
  cout<<endl<<setw(10)<<key<<setw(10)<<meaning;
 }
 friend class Dictionary;
};
class Dictionary
{
 node *root;
 node *loc, *par;
public:
 Dictionary()
{
  root=NULL;
}
 int max(int,int);
 int getheight(node*);
 node *insert(node *rnode,node*);
 void insertInit(char key,char meaning[]);
 node *rightRotate(node *);
 node *leftRotate(node *);
 int getbalance(node*);
 void preorder();
 void preorderRec(node*);
 void postorder();
 void postorderRec(node *);
 void inorder();
 void inorderRec(node *);
 void input();
 void search(char x[]);
 node* search1(node*, char x[]);
 void removeitem(char []);
 void remove1(node*, node*);
 void remove2(node*, node*);
 void update(char []);
};

void Dictionary :: update(char x[])
{
  search(x);
  cin>>loc->meaning;
  cout<<"updated\n";
}



void Dictionary::removeitem(char x[])
{
    search(x);
    if(loc==NULL)
    {
        cout<<"\nitem is not there";
        return;
    }
    if(loc->right!=NULL&&loc->left!=NULL)
        remove1(loc,par);
    else
        remove2(loc,par);
}
void Dictionary::remove1(node *l,node *p)
{
    node *ptr,*save,*suc,*psuc;
    ptr=l->right;
    save=l;
    while(ptr->left!=NULL)
    {
        save=ptr;
        ptr=ptr->left;
    }
    suc=ptr;
    psuc=save;
    remove2(suc,psuc);
    if(p!=NULL)
        if(l==p->left)
            p->left=suc;
        else
            p->right=suc;
    else
        root=l;
    suc->left=l->left;
    suc->right=l->right;
    return;
}
void Dictionary::remove2(node *s,node *p)
{
    node *child;
    if(s->left==NULL && s->right==NULL)
        child=NULL;
    else if(s->left!=NULL)
        child=s->left;
    else
        child=s->right;
    if(p!=NULL)
        if(s==p->left)
            p->left=child;
        else
            p->right=child;
    else
        root=child;
}

void Dictionary::search(char x[])
{
  par = NULL;
    search1(root,x);
}
node* Dictionary::search1(node *temp,char x[])
{
    if (temp == NULL)
    {
      return temp;
    }
    if (!strcmp(temp->key, x))
    {
      cout<<"found and meaning is:- "<<temp->meaning<<endl;
      loc = temp;
      return temp;
    }
    par = root;
    
    if (strcmp(temp->key, x)>0)
    {
      par = temp;
      search1(temp->left, x);
    }
    else
    {
        par = temp;
      search1(temp->right, x);
    }

}

void Dictionary:: input()
{
  int n;
  
  
    node* temp = new node;
    cin>>temp->key;
    cin>>temp->meaning;
    root = insert(root, temp);
  


}
int Dictionary::max(int a,int b)
{
 return (a>b)?a:b;
}
int Dictionary::getheight(node *nnode)
{
 if(nnode==NULL)
  return 0;
 else
  return nnode->height;
}
int Dictionary::getbalance(node *n)
{
 if(n==NULL)
  return 0;
 else
  return (getheight(n->left)-getheight(n->right));
}
node* Dictionary::rightRotate(node *y)
{
 node *x=y->left;
 node *xr=x->right;

 x->right=y;
 y->left=xr;

 y->height=max(getheight(y->left),getheight(y->right))+1;
 x->height=max(getheight(x->left),getheight(x->right))+1;
 return x;
}

node* Dictionary::leftRotate(node *y)
{
 node *x=y->right;
 node *t2=x->left;

 x->left=y;
 y->right=t2;

 y->height=max(getheight(y->left),getheight(y->right))+1;
 x->height=max(getheight(x->left),getheight(x->right))+1;

 return x;
}

node* Dictionary::insert(node *rnode,node* temp)
{

 if(rnode==NULL) 
  return temp;

 if(strcmp(temp->key,rnode->key)<0)
  rnode->left=insert(rnode->left, temp);
 else if(strcmp(temp->key,rnode->key)>0)
  rnode->right=insert(rnode->right, temp);
 else 
  return rnode;

 rnode->height=1+max(getheight(rnode->left),getheight(rnode->right));
 int balance=getbalance(rnode);

 if(balance>1 && strcmp(temp->key,rnode->left->key)<0)
  return rightRotate(rnode);


 if(balance<-1 && strcmp(temp->key,rnode->right->key)>0)
  return leftRotate(rnode);


 if(balance>1 && strcmp(temp->key,rnode->left->key)>0)
 {
  rnode->left=leftRotate(rnode->left);
  return rightRotate(rnode);
 }

 
 if(balance<-1 && strcmp(temp->key,rnode->right->key)<0)
 {
  rnode->right=rightRotate(rnode->right);
 return leftRotate(rnode);
 }

 return rnode; 
}
void Dictionary::preorder()
{
 preorderRec(root);
}
void Dictionary::postorder()
{
 postorderRec(root);
}
void Dictionary::inorder()
{
 inorderRec(root);
}
void Dictionary::preorderRec(node *n)
{
 if(n)
 {
  n->print();
  preorderRec(n->left);
  preorderRec(n->right);
 }
}

void Dictionary::inorderRec(node *n)
{
 if(n)
 {
  inorderRec(n->left);
  n->print();
  inorderRec(n->right);
 }
}

void Dictionary::postorderRec(node *n)
{
 if(n)
 {
  postorderRec(n->left);
  postorderRec(n->right);
  n->print();
 }
}

int main() {
 Dictionary d;
int ch;
do
{
  cout<<"enter 1.input 2.disp 3.preorder 4.postorder 5.search 6.update 7.delete 0.exit\n";
  cout<<"enter choice\n";
  cin>>ch;
  switch(ch)
  {
    case 1:
    {
      cout<<"enter key and meaning\n";
      d.input();

    }
    break;
    case 2:
    {
       cout<<"\nASCENDING ORDER:";
 d.inorder();
 cout<<endl;
    }
    break;
    case 3:
    {
 cout<<"\nPreorder: ";
 d.preorder();
 cout<<endl;
    }
    break;
    case 4:
    {
 cout<<"\nPostorder: ";
 d.postorder();
 cout<<endl;
    }
    break;
    case 5:
    {
 char a[20];
 cout<<"Enter word to be searched:\n";
 cin>>a;
 d.search(a);
    }
    break;
    case 6:
    {
 char a[20];
 cout<<"Enter word to be updated:\n";
 cin>>a;
 d.update(a);
    }
    break;
    case 7:
    {
 char a[20];
 cout<<"Enter word to be deleted\n";
 cin>>a;
 d.removeitem(a);
 cout<<"deleted\n";
    }
    break;
  }

}while(ch!=0);
 










 return 0;
}
