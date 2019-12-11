#include<iostream>
using namespace std;

struct database
{
    int rollno,grno;
    string name;
};

void read(struct database student[],int n)
{
     int i;
     cout<<"Enter students detils\n";
     for(i=0;i<n;i++)
     {
          cout<<"Student "<<i+1<<"\nRoll no.: ";
          cin>>student[i].rollno;
          cout<<"GR no.: ";
          cin>>student[i].grno;
          cout<<"Name: ";
          cin>>student[i].name;
     }
     cout<<"\n";
}

void display(struct database student[],int n)
{
     int i;
     cout<<"Rollno. GR no.  Name\n";
     for(i=0;i<n;i++)
          cout<<student[i].rollno<<"\t"<<student[i].grno<<"\t"<<student[i].name<<endl;
}

void add(struct database student[],int n)
{
    cout<<"Enter details\nRoll no.: ";
    cin>>student[n].rollno;
    cout<<"GR no.: ";
    cin>>student[n].grno;
    cout<<"Name: ";
    cin>>student[n].name;
    n++;
    cout<<"\nSuccessfully added record\n\n";
}

void binary(struct database student[],int n)
{
     int first=0,last=n-1,mid,key;

     cout<<"Enter Roll no. to be searched: ";
     cin>>key;

     while(first<=last)
     {
          mid=(first+last)/2;
          if(student[mid].rollno==key)
          {
               cout<<"Rollno. GR no.  Name\n";
               cout<<student[mid].rollno<<"\t"<<student[mid].grno<<"\t"<<student[mid].name<<endl<<endl;
               break;
          }
          else
          {
               if(key>student[mid].rollno)
                    first=mid+1;
               else
                    last=mid-1;
          }
     }
     if(last<first)
     cout<<"Sorry, no record found\n\n";
}

void modify(struct database student[])
{
     int key;
     cout<<"Enter roll no. of the record to be modified: ";
     cin>>key;

     cout<<"Enter details\nRoll no.: ";
     cin>>student[key-1].rollno;
     cout<<"GR no.: ";
     cin>>student[key-1].grno;
     cout<<"Name: ";
     cin>>student[key-1].name;
     cout<<"\nRecord modified successfully\n\n";
}

int delrec(database student[20],int n)
{
     int del,no;

     cout<<"Enter roll no. to be deleted\n";
     cin>>del;
    
     for(int i=0;i<n-1;i++)
     {
          if(del==student[i].rollno)
          {
               for(int j=i;j<n-1;j++)
               {
                    student[j]=student[j+1]; 
               }
               n--;
               break;
          }
     }
    return n;
}



void bubble(struct database student[],int n)
{
    int i,j,sorted=0,op;
    database k;

    for(i=0;i<n-1&&sorted==0;i++)
     {
          sorted=1;
          for(j=0;j<=n-2-i;j++)
          {
               if(student[j].rollno>student[j+1].rollno)
               {
                    sorted=0;
                    k=student[j];       
                    student[j]=student[j+1];
                    student[j+1]=k;
               }
          }
     }
     cout<<"Successfully Sorted\n\n";
}

int main()
{
    database student[30];
    int n,op,key;
    cout<<"Enter number of students: ";
    cin>>n;
    cout<<"\n";

    read(student,n);

    display(student,n);

    do
    {
          cout<<"1.Add record\n2.Display record\n3.Search record\n4.Modify record\n5.Delete record\n6.Sort record\n7.Exit\n";
          cout<<"Enter operation number: ";
          cin>>op;
          cout<<endl;
          switch(op)
          {
               case 1: add(student,n);
                    break;
               case 2: display(student,n);
                    break;
               case 3: binary(student,n);
                    break;
               case 4: modify(student);
                    break;
               case 5: n=delrec(student,n);
                    break;
               case 6: bubble(student,n);
                    break;
               case 7: break;
          }
     }while(op!=7);

    return 0;
}
