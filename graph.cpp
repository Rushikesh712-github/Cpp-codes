#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int vertex[20][20];
string cities[20];   //Adjancency matrix initially 

void display(int v)
{
	int i,j;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
			cout<<vertex[i][j]<<"\t";
		cout<<endl;
	}
}
	
	
	

void create_graph()
{
	int u,v,dis;
	char ch;
	do{
		cout<<"ENTER THE CITIES INDEX WHICH ARE HAVING EDGE BETWEEN THEM:";
		cin>>u>>v;
		cout<<"ENTER THE DISTANCE BETWEEN TWO CITIES:";
		cin>>dis;
		vertex[u][v]=dis;
		vertex[v][u]=dis;
		cout<<"WANT TO CONTINUE(y/n):";
		cin>>ch;
	}while(ch=='y' || ch=='Y');
	
}
int main()
{
	int size,i,j,ch,k,m;
	int v[20];
	char c;
	cout<<"\n\t\t..MENU..\n\t1.Create Graph \n\t2.Display Graph\n\t3.Exit\n";
	
	do{
		cout<<"\nEnter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter the total no. of nodes in graph:";
				cin>>size;
				cout<<"Enter the cities in graph:\n";
				for(m=0;m<size;m++)
				{
					cin>>cities[m];
				}
				cout<<"The cities with their index are:\n";
				for(k=0;k<size;k++)
				{
					cout<<k<<"->"<<cities[k]<<endl;
				}
				create_graph();
				cout<<"\nSuccessfully, Graph is created\n\n";
				break;
			case 2:
				cout<<"\nGraph:\n";
				display(size);
				break;
			case 3:
				exit(1);
				break;
				
		}
		cout<<"\nWant to continue(y/n):";
		cin>>c;
		cout<<endl;
	}while(c=='y' || c=='Y');
	
	return 0;
}
