#include<iostream>
using namespace std;
struct node
{
     int data;
     struct node*next;
};

struct node* create(struct node* h)
{
     struct node*temp,*nn;
     nn=new node;
     cout<<"enter the data"<<endl;
     cin>>nn->data;
     nn->next=NULL;
     if(h==NULL)
          h=nn;
     else
     {
          temp=h;
          while(temp->next!=NULL)
          {
               temp=temp->next;
          }
          temp->next=nn;
     }
     return h;
}

void display(struct node* h) 
{
     struct node*temp;
     temp=h;
     while(temp!=NULL)
     {
          cout<<temp->data<<"\t";
          temp=temp->next;
     }
}

struct node* insert_begin(struct node* h) 
{
     struct node*nn;
     nn=new node;
     cout<<"enter the data"<<endl;
     cin>>nn->data;
     nn->next=NULL;
     nn->next=h;
     h=nn;
     return h;
}

struct node* insert_pos(struct node* h)
{
     struct node*nn,*temp;
     int pos,i;
     nn=new node;
     cout<<"enter the data"<<endl;
     cin>>nn->data;
     nn->next=NULL;
     cout<<"enter the position"<<endl;
     cin>>pos;
     temp=h;
     i=0;
     while(i<pos)
     {
          temp=temp->next;
          i++;
     }
     nn->next=temp->next;
     temp->next=nn;
     return h;
}

struct node* insert_end(struct node* h) 
{
     struct node*nn,*temp;
     nn=new node;
     cout<<"enter the data"<<endl;
     cin>>nn->data;
     nn->next=NULL;
     temp=h;
     while(temp->next!=NULL)
     {
          temp=temp->next;
     }
     temp->next=nn;
     return h;
}

struct node* delete_begin(struct node* h) 
{
     struct node*temp;
     temp=h;
     h=h->next;
     temp->next=NULL;
     delete(temp);
}

struct node* delete_pos(struct node* h) 
{
     struct node*temp,*t;
     int pos;
     cout<<"enter the position"<<endl;
     cin>>pos;
     temp=h;
     int i=0;
     while(i<pos-1)
     {
          t=temp;
          temp=temp->next;
          i++;
     }
     t->next=temp->next;
     temp->next=NULL;
     delete(temp);
}

struct node* delete_end(struct node* h)
{
     struct node*temp,*t;
     temp=h;
     while(temp->next!=NULL)
     {
          t=temp;
          temp=temp->next;
     }
     t->next=NULL;
     delete(temp);
}

void search(struct node* h)
{
     struct node*temp;
     int num,i=0;
     cout<<"enter the number to be searched"<<endl;
     cin>>num;
     temp=h;
     while(temp->data!=NULL)
     {
          i++;
          if(temp->data == num)
          {
               cout<<"the pos of number is:"<<i<<endl;
               break;
          }
          temp=temp->next;
     }
     if(temp->next=NULL)
     {
          cout<<"Data not found"<<endl;
     }
}

struct node* modify(struct node* h)     //MODIFY
{
     struct node*temp;
     int pos,i=1,num;
     temp=h;
     cout<<"enter the pos of node to be modified"<<endl;
     cin>>pos;
     cout<<"enter the modified number:"<<endl;
     cin>>num;
     while(i<=pos)
     { 
          temp=temp->next;
          i++;
     }
     temp->data=num;
     return h;
}

int main()
{
     struct node*head=NULL;
     int n;
     do
     {
     cout<<"Enter\n1.create 2.insert_begin 3.insert_pos 4.insert_end 5.delete_ begin 6.delete_pos 7.delete_end\ 8.search 9.modify 10.Exit\n";
     cin>>n;
     switch(n)
     {
          case 1:
          {
               int no,i;
               cout<<"enter the no of elements in linked list"<<endl;
               cin>>no;
               for(i=0;i<no;i++)
               {
                    head=create(head);
               }
               display(head);
          }
          break;

          case 2:
          {
               int no,i;
               cout<<"enter the no of elements in linked list"<<endl;
               cin>>no;
               for(i=0;i<no;i++)
               {
                    head=create(head);
               }
               head=insert_begin(head);
               display(head);
          }
          break;

          case 3:
          {
               int i,no;
               cout<<"enter the no of elements in linked list"<<endl;
               cin>>no;
               for(i=0;i<no;i++)
               {
                    head=create(head);
               }
               head=insert_pos(head);
               display(head);
          }
          break;

          case 4:
          {
               int i,no;
               cout<<"enter the no of elements in linked list"<<endl;
               cin>>no;
               for(i=0;i<no;i++)
               {
                    head=create(head);
               }
               head=insert_end(head);
               display(head);
          }
          break;

          case 5:
          {
               int i,no;
               cout<<"enter the no of elements in linked list"<<endl;
               cin>>no;
               for(i=0;i<no;i++)
               {
                    head=create(head);
               }
               head=delete_begin(head);
               display(head);
          }
          break;    

          case 6:
          {
               int i,no;
               cout<<"enter the no of elements in linked list"<<endl;
               cin>>no;
               for(i=0;i<no;i++)
               {
                    head=create(head);
               }
               head=delete_pos(head);
               display(head);
          }
          break;
     
          case 7:
          {
               int i,no;
               cout<<"enter the no of elements in linked list"<<endl;
               cin>>no;
               for(i=0;i<no;i++)
               {
                    head=create(head);
               }
               head=delete_end(head);
               display(head);
          }
          break;

          case 8:
          {
               int i,no;
               cout<<"enter the no of elements in linked list"<<endl;
               cin>>no;
               for(i=0;i<no;i++)
               {
                    head=create(head);
               }
          }
          break;
          
          case 9:
          {
               int i,no;
               cout<<"enter the no of elements in linked list"<<endl;
               cin>>no;
               for(i=0;i<no;i++)
               {
                    head=create(head);
               }
               head=modify(head);
               cout<<"modified linked list is"<<endl;
               display(head);
          }
          break;
     }
     }while(n!=10);
     

     return 0;
}
