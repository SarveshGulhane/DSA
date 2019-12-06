#include<iostream>
using namespace std;

struct database{
	int roll;
	string name;
	int marks;
};



int main()
{
	database stud[100];
	int n,i,m,con=0,srch,cond=0,mod=0;
	cout<<"Enter the No. of entries: ";
	cin>>n;
	
	for(i=0;i<n;i++)
	{
		cout<<"Enter the roll no. of Student No."<<i+1<<": ";
		cin>>stud[i].roll;
		cout<<"Enter the name of the student of Roll No."<<i+1<<": ";
		cin>>stud[i].name;
		cout<<"Enter marks of the student: ";
		cin>>stud[i].marks;
	}
	
	int hold1,hold2,j,pass;
	string hold3;
	int switched=1;
	
	for(pass=0;(pass<n-1)&&(switched=1);pass++)
   {
   	switched=0;
    for(j=0;j<n-pass-1;j++)
     {
      if(stud[j].roll>stud[j+1].roll)
       {
         hold1=stud[j].roll;
         hold2=stud[j].marks;
         hold3=stud[j].name;
         stud[j].roll=stud[j+1].roll;
         stud[j].marks=stud[j+1].marks;
         stud[j].name=stud[j+1].name;
         stud[j+1].roll=hold1;
         stud[j+1].marks=hold2;
         stud[j+1].name=hold2;
       }

     }
   }

	
	
	
	int ctr=0;
	do
   { int x;
	cout<<"Enter you choice.\n 1 for Add Record.\n 2 for Display Database.\n 3 for Search Record by Roll No.\n 4 for Modify.\n 5 for Delete.\n 6 for Exit.\n";
	cin>>x;
	switch(x)
	{
		case 1: cout<<"How many u want to add: ";
				cin>>m;
				for(i=n;i<n+m;i++)
				{
					cout<<"Enter the roll no. of Student No."<<i+1<<": ";
					cin>>stud[i].roll;
					cout<<"Enter the name of the student of Roll No."<<i+1<<": ";
					cin>>stud[i].name;
					cout<<"Enter marks of the student: ";
					cin>>stud[i].marks;
				}
				n=n+m;
				m=0;
				break;
		case 2:for(i=0;i<n;i++)
				 {
					cout<<"Roll no. of Student No."<<i+1<<": ";
					cout<<stud[i].roll<<endl;
					cout<<"Name of Student No."<<i+1<<": ";
					cout<<stud[i].name<<endl;
					cout<<"Marks of the student: ";
					cout<<stud[i].marks<<endl<<endl;
				 } 
				break; 
		case 3:	cout<<"Enter the Roll No. you want to search: ";
				cin>>srch;
				for(i=0;i<n;i++)
				 {
				   if(stud[i].roll==srch)
					{
						cout<<"Name of the student: ";
						cout<<stud[i].name<<endl;
						cout<<"Marks of the student: ";
						cout<<stud[i].marks<<endl;
						break;
					} 
				 }
				 cout<<"Search not found.\n";
				break;
		case 4:cout<<"Enter the Roll No. of the student whose record you have to modify:";
				cin>>mod;
				for(i=0;i<n;i++)
				 {
				   if(stud[i].roll==mod)
					{
						cout<<"Enter Name of the student:";
						cin>>stud[i].name;
						cout<<"Enter new marks of the student:";
						cin>>stud[i].marks;
						mod=0;
						break;
					} 
				 }
				 break;
		case 5: cout<<"Enter the Roll No. of the student whose record you want to delete:";
				cin>>mod;
				for(i=0;i<n;i++)
        		{
         			if(mod==stud[i].roll)
         			{break;}
         		}
         		int j;
         		for(j=i;j<n;j++)
        		{
         			stud[j].roll=stud[j+1].roll;
         			stud[j].name=stud[j+1].name;
         			stud[j].marks=stud[j+1].marks;
        		}
        		n=n-1;
        		cout<<"record deleted succesfully";
        		break;		
		case 6: ctr=1;
				break;	
		default: cout<<"Enter appropriate choice.\n";
		         break;	
	}
 } while(ctr!=1);	



return 0;
}



