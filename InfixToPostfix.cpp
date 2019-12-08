#include<iostream>
using namespace std;

char stk[20];
int top=-1;

char pop()
{
     char data;
     if(top==-1)
     {
          return -1;
     }
     else
     {
          data=stk[top];
          top--;
          return data;
     }
     
}

void push(char x)
{
     top++;
     stk[top]=x;
}

int priority(char x)
{
     if(x=='(')
          return 0;
     else if(x=='+'||x=='-')
          return 1;
     else if(x=='*'||x=='/')
          return 2;
     else
          return -1;
     
}

int main()
{
     char x, xep[20],*e;
     cout<<"Enter Infix Expression\n";
     cin>>xep;
     e=xep;

     cout<<"Postfix:\n";
     while(*e!='\0')
     {
          if(isalnum(*e))
               cout<<*e;
          else if(*e=='(')
               push(*e);
          else if(*e==')')
          {
               while((x=pop())!='(')
                    cout<<x;
          }
          else
          {
               while(priority(stk[top])>=priority(*e))
                    cout<<pop();
                    push(*e);
          }
          e++;
     }
     while(top!=-1)
          cout<<pop();

     return 0;

}
