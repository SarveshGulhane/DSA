#include<iostream>
using namespace std;

void length()
{
     char* str1=new char[100];

     cout<<"Enter String: ";
     cin>>str1;
     char *ptr1;
     int len=0;
     ptr1=str1;

     while(*ptr1!='\0')
     {
          len++;
          ptr1++;
     }
    
     cout<<"Len= "<<len<<endl;
}

void reverse()
{
     char* str1=new char[100];

     cout<<"Enter String: ";
     cin>>str1;
     char *ptr1, *ptr2, temp, i=0;
	int len=0;

     while(str1[i]!='\0')
	{
		len++;
          i++;
	}

	ptr1=str1;
     ptr2=str1;

     for(int i=0;i<len-1;i++)
     {
          ptr2++;
     }

	for(i=0;i<len/2;i++)
	{
		temp=*ptr2;
		*ptr2=*ptr1;
		*ptr1=temp;
		ptr1++;ptr2--;
	}
	cout<<"reversed: "<<str1<<endl;
}

void copy()
{
     char* str1=new char[100];

     cout<<"Enter String: ";
     cin>>str1;
     char* str2=new char[100];
     char *ptr1, *ptr2;
     int len=0;
     ptr1=str1;

     while(*ptr1!='\0')
     {
          len++;
          ptr1++;
     }

     int i=0;
     ptr1=str1;
     ptr2=str2;

     while(*ptr1!='\0')
     {
          *ptr2=*ptr1;
          ptr1++;
          ptr2++;
     }
     
     *ptr2='\0';
     cout<<"copied str: "<<str2<<endl;
}

void concat()
{
     	char* str1=new char[100];

     cout<<"Enter String: ";
     cin>>str1;
          char *ptr1,*ptr2;
          char* str2=new char[100];

          cout<<"Enter 2nd String: ";
          cin>>str2;

          int len=0;
          ptr1=str1;
          ptr2=str2;

          while(*ptr1!='\0')
          {
               len++;
               ptr1++;
          }
		 
		while(*ptr2!='\0')
		{
		     *ptr1=*ptr2;
		 	ptr1++;ptr2++;
		}
		 
		*ptr1='\0';
		cout<<"concat: "<<str1<<endl;
}

void comp()
{
	char* str1=new char[100];

     cout<<"Enter String: ";
     cin>>str1;
     int len1=0,len2=0;
	char *ptr1,*ptr2;
	char* str2=new char[100];

     cout<<"Enter 2nd String: ";
     cin>>str2;
     
     ptr1=str1;
     ptr2=str2;
     
     
     	while(*ptr1!='\0')
     	{
     		if(*ptr1==*ptr2)
     		{
     			ptr1++;ptr2++;
                    len1++;len2++;
     		}
     		else
               {
     			len1++;
                    cout<<"Not Equal\n";
                    break;
               }
     	}
     if(len1==len2)
          cout<<"Equal\n";
}

int main()
{
     int op=1;

     while(op!=6)
     {
          cout<<"Enter the operation: \n1.Lenght 2.Reverse 3.Copy 4.Concatinate 5.Compare 6.Exit\n";
          cin>>op;

          switch (op)
          {
          case 1:
     	 	length();
          break;
     
          case 2:
               reverse();
          break;

          case 3:
               copy();
          break;

          case 4:
               concat();
	  	break;
          
          case 5:
          	comp();
          break;
		}
		
          cout<<"\n";  
     };

     return 0;
}
