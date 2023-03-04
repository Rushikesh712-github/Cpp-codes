#include<iostream>
#include<algorithm>
using namespace std ;

struct node 
{
   int rollno, examno ;
   char name[20], div ;
   node *next ;
};

node *create_node()
{
   node *temp ;
   temp = new node ;
   temp->next = NULL ;
   return temp ;
}

node *create_list()
{
   node *temp, *head = NULL, *ptr ;
   int roll_no, exam_no ;
   char Name[20], division, ans ;
   do{ 
        cout<<"\nEnter the name of student : " ;
        cin>>Name ;
        cout<<"Enter the division of student : " ;
        cin>>division ;
        cout<<"Enter the roll number of student : " ;
        cin>>roll_no ;
        cout<<"Enter the exam number student : " ;
        cin>>exam_no ;
        temp = create_node() ;
        copy(Name, Name+20, temp->name) ;
        temp->div = division ;
        temp->rollno = roll_no ;
        temp->examno = exam_no ;
        
        if(head==NULL)
        {
           head = temp ;
        }
        
        else
        {
           ptr = head ;
           while(ptr->next!=NULL)
           {
              ptr = ptr->next ;
           }
           ptr->next = temp ;
        }
        cout<<"\nDo you want to add more elements?(Y/N) : " ;
        cin>>ans ;
     }while(ans=='Y') ;  
     return head ;
}

node *insert_head(node *head)
{
   node *temp, *ptr ;
   temp = create_node() ;
   cout<<"\nEnter the name of student : " ;
   cin>>temp->name ;
   cout<<"Enter the division of student : " ;
   cin>>temp->div ;
   cout<<"Enter the roll number of student : " ;
   cin>>temp->rollno ;
   cout<<"Enter the exam number student : " ;
   cin>>temp->examno ;
   if(head==NULL)
   {
      head = temp ;
   }
   else
   {
      ptr = head ;
      temp->next = ptr ;
      head = temp ;
   }
   return head ;
}

node *insert_after(node *head)
{
   node *temp, *ptr ;
   int key ;
   temp = create_node() ;
   cout<<"\nEnter the name of student : " ;
   cin>>temp->name ;
   cout<<"Enter the division of student : " ;
   cin>>temp->div ;
   cout<<"Enter the roll number of student : " ;
   cin>>temp->rollno ;
   cout<<"Enter the exam number student : " ;
   cin>>temp->examno ;
   if(head==NULL)
   {
      head = temp ;
   }
   else
   {
      cout<<"\nEnter the roll number after which you want to enter the record : " ;
      cin>>key ;
      ptr = head ;
      while(ptr!=NULL && ptr->rollno!=key)
      {
         ptr= ptr->next ;
      }
      temp->next = ptr->next ;
      ptr->next = temp ;
   }
   return head ;
}

node *insert_last(node *head)
{
   node *temp, *ptr ;
   temp = create_node() ;
   cout<<"\nEnter the name of student : " ;
   cin>>temp->name ;
   cout<<"Enter the division of student : " ;
   cin>>temp->div ;
   cout<<"Enter the roll number of student : " ;
   cin>>temp->rollno ;
   cout<<"Enter the exam number student : " ;
   cin>>temp->examno ;
   ptr = head ;
   while(ptr->next!=NULL)
   {
      ptr = ptr->next ;
   }
   ptr->next = temp ;
   return head ;
}

node *del_beg(node *head)
{
   if(head==NULL)
   {
      cout<<"\nList is empty "<<endl ;
   }
   else
   {
      node *ptr ;
      ptr = head ;
      head = ptr->next ;
      ptr->next = NULL ;
      delete ptr ;
   }
   return head ;
}

node *del_mid(node *head)
{
   node *ptr, *prev ;
   int key ;
   if(head==NULL)
   {
      cout<<"List is empty "<<endl ;
   }
   else
   {
      cout<<"Enter the roll number of student to be deleted : " ;
      cin>>key ;
      ptr = head ;
      while(ptr->next!=NULL && ptr->rollno!=key)
      {
         prev = ptr ;
         ptr = ptr->next ;
      }
      prev->next = ptr->next ;
      ptr->next = NULL ;
      delete ptr ;
   }
   return head ;
}

node *del_last(node *head)
{
   node *ptr, *prev ;
   if(head==NULL)
   {
      cout<<"List is empty "<<endl ;
   }
   else
   {
      ptr = head ;
      while(ptr->next!=NULL)
      {
         prev = ptr ;
         ptr = ptr->next ;
      }
      prev->next = NULL ;
      delete ptr ;
   }
   return head ;
}

node *search(node *head)
{
   node *ptr ;
   int key ;
   if(head==NULL)
   {
      cout<<"List is empty "<<endl ;
   }
   else
   {
      cout<<"Enter the roll number of student you want to search : " ;
      cin>>key ;
      ptr = head ;
      int count = 0, found =0 ;
      while(ptr!=NULL)
      {
         if(ptr->rollno==key)
         {
            cout<<"\nStudent found at index : "<<count<<endl ;
            found++ ;
            break ;
         }
         else
         {
            count++ ;
            ptr = ptr->next ;
         }
      }
    if(found==0)
    {
       cout<<"Student record dosen't exist in list"<<endl ;
    }
   }
   return head ;
}       
      
void display(node *head)
{
   node *ptr ;
   ptr = head ;
   cout<<"\nThe linked list of student details :"<<endl ;
   while(ptr->next!=NULL)
   {
      cout<<"Name : "<<ptr->name<<endl ;
      cout<<"Division : "<<ptr->div<<endl ;
      cout<<"Roll number : "<<ptr->rollno<<endl ;
      cout<<"Exam number : "<<ptr->examno<<"\n\n" ;
      ptr = ptr->next ;
   }
   cout<<"Name : "<<ptr->name<<endl ;
   cout<<"Division : "<<ptr->div<<endl ;
   cout<<"Roll number : "<<ptr->rollno<<endl ;
   cout<<"Exam number : "<<ptr->examno<<"\n\n" ;
}

int main()
{
   int choice ;
   node *head ;
   do{
cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl ;
        cout<<"1. create list"<<endl ; 
        cout<<"2. insert head node"<<endl ; 
        cout<<"3. insert after a perticular node"<<endl ;
        cout<<"4. insert at last node"<<endl ; 
        cout<<"5. delete head node"<<endl ; 
        cout<<"6. delete intermediate node"<<endl ; 
        cout<<"7. delete last node"<<endl ; 
        cout<<"8. search an element in list"<<endl ; 
        cout<<"9. dispaly list"<<endl ;
        cout<<"10. exit"<<endl ;
        cout<<"\nEnter your choice : " ;
        cin>>choice ;
        switch(choice)
        {
           case 1 :  head = create_list() ;
                     display(head) ;
                     break ; 
                
           case 2 :  head = insert_head(head) ;
                     display(head) ;
                     break ; 
      
           case 3 :  head = insert_after(head) ;
                     display(head) ;
                     break ; 
      
           case 4 :  head = insert_last(head) ;
                     display(head) ;
                     break ; 
      
           case 5 :  head = del_beg(head) ;
                     display(head) ;
                     break ; 
      
           case 6 :  head = del_mid(head) ;
                     display(head) ;
                     break ; 
      
           case 7 :  head = del_last(head) ;
                     display(head) ;
                     break ; 
      
           case 8 :  search(head) ;
                     break ; 
      
           case 9 :  display(head) ;
                     break ; 
           
           case 10 : exit(0) ;
                     break ;
        }
     }while(1) ;
   return 0 ;
}
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
   











   
   
   
   
   
   
   
   
   
   
        
