#include<iostream>
using namespace std;

struct node
{
	node *link,*down;
	int data;
};

struct node* create()
{
	struct node *parent,*child,*ptrp,*ptrc,*root=NULL;
	char ch;
	int ch1=1;
	ptrp=new node;
	cout<<"Enter the first node in Graph:";
	cout<<"\nEnter the parent node:";
	cin>>ptrp->data;
	ptrp->down=NULL;
	ptrp->link=NULL;
	parent=ptrp;
	child=ptrp;
	if(root==NULL)
	{
		root=ptrp;
	}
	do
	{
		ptrc=new node;
		cout<<"Enter adjacent node for "<<ptrp->data<<':';
		cin>>ptrc->data;
		ptrc->link=NULL;
		ptrc->down=NULL;
		child->link=ptrc;
		child=ptrc;
		cout<<"Want to add more adjacent node(y/n):";
		cin>>ch;
	}while(ch=='y' || ch=='Y');
	cout<<"\nEnter Another Parent nodes in Graph:";
	while(ch1==1)
	{
		ptrp=new node;
		cout<<"\nEnter the parent node:";
		cin>>ptrp->data;
		ptrp->down=NULL;
		ptrp->link=NULL;
		parent->down=ptrp;
		parent=ptrp;
		child=ptrp;
		do
		{
			ptrc=new node;
			cout<<"Enter adjacent node for "<<ptrp->data<<':';
			cin>>ptrc->data;
			ptrc->link=NULL;
			ptrc->down=NULL;
			child->link=ptrc;
			child=ptrc;
			cout<<"Want to add more adjacent node(y/n):";
			cin>>ch;
		}while(ch=='y' || ch=='Y');
		cout<<"Want to add more parent node(1/0):";
		cin>>ch1;
	}
	return root;
}
void display(node *root)
{
	struct node *temp,*temp1;
	temp=root;
	cout<<"The Graph is:"<<endl;
	while(temp!=NULL)
	{
		cout<<temp->data<<endl;
		temp1=temp->link;
		cout<<"connections:";
		while(temp1!=NULL)
		{
			cout<<temp1->data<<"->";
			temp1=temp1->link;
		}

		temp=temp->down;
		if(temp!=NULL)
		{
			cout<<
			cout<<endl;
		}
	}
}
int main(){
	struct node *temp=create();
	display(temp);
	return 0;
}
