#include<iostream>
#include<fstream>
#include<cstring>
using namespace std ;
class addressbook
{
        public:
        char name[10] ;
        long telephone ;
        char names[20][10] ;
        long telephones[20] ;
        int noo=1 ;
	
	void getdetails(int n)
	{
	        ofstream out("phonebook.txt", ios::out) ;
		out<<"    Name                          Telephone No."<<endl ;
		out<<"--------------------------------------------------------------------------"<<endl ;
		for(int i=0; i<n; i++)
		{
		        cout<<"Enter name of "<<i+1<<" person"<<endl ;
			cin>>name ;
			for(int k=0; k<10; k++)
			{
				names[i][k] = name[k] ;
			}
			cout<<"Enter telephone number of "<<i+1<<" person"<<endl ;
			cin>>telephone ;
			telephones[i] = telephone ;
			out<<i+1<<"."<<" "<<name<<"                          "<<telephone<<endl ;
		}
		out.close() ;
	}
	
	void findnumber(int o)
	{
		char person[10] ;
		int num, u = 0 ;
		cout<<"\nEnter the name of person whose telephone number you want : " ;
		cin>>person ;
		for(int j=0; j<o; j++)
		{
			int str = strcmp(person, names[j]) ;
			if(str==0)
			{  num = j ;
			   u = 1 ;
			   break ;  }
		}
		if(u==1)
		{  cout<<"Telephone number of the "<<person<<" is : "<<telephones[num]<<endl ;  }
		else
		{  cout<<"no such person in the contactbook"<<endl ;  }
	}
	
	void findperson(int y)
	{
		long contactnumber ;
		char found[10] ;
		int py, use=0 ;
		cout<<"\nEnter the contactnumber you want to search : "<<endl ;
		cin>>contactnumber ;
		for(int l=0; l<y; l++)
		{
			if(contactnumber==telephones[l])
			{  py = l ;
			   use = 1 ; 
			   break ;  }
		}
			 if(use==0)
			 {  cout<<"Your entered number is not in the list"<<endl ; }
			 
			 else
			 {  cout<<"the contact number belongs to : "<<names[py]<<endl ;  }
	}
	
	void update(int h)
	{
		char person1[10] ;
		long newnumber ;
		int numc=0 , uc=0 ;
		cout<<"\nEnter the person whose telephone number you want to change : "<<endl ;
		cin>>person1 ;
		for(int zz=0; zz<h; zz++)
		{
			int strc = strcmp(person1, names[zz]) ;
			if(strc==0)
			{  numc = zz ;
			   uc = 1 ;  }
		}
		
		if(uc==1)
		{       
		        cout<<"Enter the new telephone number : "<<endl ;
		        cin>>newnumber ;
			telephones[numc] = newnumber ;
			ofstream out1 ("phonebook.txt", ios::out) ;
			out1<<"  Name                            Telephone No."<<endl ;
			out1<<"--------------------------------------------------------------------------"<<endl ;
			for(int fo=0; fo<h; fo++)
			{
				out1<<fo+1<<". "<<names[fo]<<"                          "<<telephones[fo]<<endl ;
				noo+=1 ;
			}
		}
		
		else
		{
			cout<<"Entered name dosent match with entries in contactbook" ;
		}
		
	}
	
	void append()
	{
	   char appname[10] ;
	   long appnum ;
	   cout<<"\nEnter the details of person whose contact-information you want to append" << endl ;
	   cout<<"Enter the name of person : " << endl ;
	   cin>>appname ;
	   cout<<"Enter his number : " << endl ;
	   cin>>appnum ;
	   fstream out2 ("phonebook.txt", ios::app) ;
	   out2<<noo<<". "<< appname << "                          "<< appnum << endl ;
	   out2.close() ;
        }   

};

int main()
{
	int m, choice ;
	cout<<"Enter number of contacts you want to enter : "<<endl ;
	cin>>m ;
	addressbook A ;
        A.getdetails(m) ;
	A.findnumber(m) ;
	A.findperson(m) ;
	A.update(m) ;
	A.append() ;
	return 0 ;
}

	
		
			
