#include<iostream>
using namespace std;

struct node{
int coef,exp;
struct node *nxt;
};

struct node* create(){
int i,n;
cout<<"Enter number of terms: \n";
cin>>n;
struct node *nn,*temp,*head;
nn=new node;
head=nn;
temp=head;
for(i=1;i<n;i++){
cout<<"coef: ";
cin>>temp->coef;
cout<<"exp: ";
cin>>temp->exp;
nn=new node;
temp->nxt=nn;
temp=nn;
}
cout<<"coef: ";
cin>>temp->coef;
cout<<"exp: ";
cin>>temp->exp;
temp->nxt=head;
return head;
}


void display(struct node *head){
struct node *temp;
temp=head;
do{
cout<<temp->coef<<"x^"<<temp->exp;
if(temp->coef>=0&&temp->nxt!=head)
cout<<" + ";
temp=temp->nxt;
}while(temp!=head);
cout<<endl;
}


struct node* add(struct node *head1,struct node *head2){
struct node *temp1,*temp2,*nn,*head3,*temp3;
temp1=head1;
temp2=head2;
nn=new node;
head3=nn;
temp3=head3;
bool headrepeated=false;
do{
	if(temp1->exp==temp2->exp){
		temp3->exp=temp1->exp;
		temp3->coef=temp1->coef+temp2->coef;
		if(temp1->nxt==head1&&temp2->nxt==head2){
			temp3->nxt=head3;
			headrepeated=true;
			temp1=NULL;
			temp2=NULL;
		}
		else{
			nn=new node;
			temp3->nxt=nn;
			temp3=temp3->nxt;

			if(temp1->nxt==head1&&temp2->nxt!=head2){
				temp1=NULL;
				temp2=temp2->nxt;
				headrepeated=true;
			}
			else if(temp1->nxt!=head1&&temp2->nxt==head2){
				temp2=NULL;
				temp1=temp1->nxt;
				headrepeated=true;
			}
			else if(temp1->nxt!=head1&&temp2->nxt!=head2){
				temp1=temp1->nxt;
				temp2=temp2->nxt;
				headrepeated=false;
			}
		}

	}
	else if(temp1->exp<temp2->exp){
		temp3->exp=temp2->exp;
		temp3->coef=temp2->coef;
		nn=new node;
		temp3->nxt=nn;
		temp3=temp3->nxt;
		if(temp1->nxt==head1&&temp2->nxt==head2){
			temp3->exp=temp1->exp;
			temp3->coef=temp1->coef;
			temp3->nxt=head3;
			headrepeated=true;
			temp1=NULL;
			temp2=NULL;
		}
		else if(temp1->nxt==head1&&temp2->nxt!=head2){
				headrepeated=false;
				temp2=temp2->nxt;
        }
        else if(temp1->nxt!=head1&&temp2->nxt==head2){
                headrepeated=true;
                temp2=NULL;
        }
        else if(temp1->nxt!=head1&&temp2->nxt!=head2){
                headrepeated=false;
                temp2=temp2->nxt;
        }

	}
	else if(temp1->exp>temp2->exp){
		temp3->exp=temp1->exp;
		temp3->coef=temp1->coef;
		nn=new node;
		temp3->nxt=nn;
		temp3=temp3->nxt;
		if(temp1->nxt==head1&&temp2->nxt==head2){
			temp3->exp=temp2->exp;
			temp3->coef=temp2->coef;
			temp3->nxt=head3;
			headrepeated=true;
			temp1=NULL;
			temp2=NULL;
		}
		else if(temp1->nxt==head1&&temp2->nxt!=head2){
				headrepeated=true;
				temp1=NULL;
        }
        else if(temp1->nxt!=head1&&temp2->nxt==head2){
                headrepeated=false;
                temp1=temp1->nxt;
        }
        else if(temp1->nxt!=head1&&temp2->nxt!=head2){
                headrepeated=false;
                temp1=temp1->nxt;
        }
	}
}while(headrepeated!=true);
if(temp1==NULL&&temp2!=NULL){
    while(temp2->nxt!=head2){
        temp3->exp=temp2->exp;
        temp3->coef=temp2->coef;
        nn=new node;
        temp3->nxt=nn;
        temp3=temp3->nxt;
    }
    temp3->exp=temp2->exp;
    temp3->coef=temp2->coef;
    temp3->nxt=head3;
    temp2=NULL;
}
else if(temp1!=NULL&&temp2==NULL){
    while(temp1->nxt!=head1){
        temp3->exp=temp1->exp;
        temp3->coef=temp1->coef;
        nn=new node;
        temp3->nxt=nn;
        temp3=temp3->nxt;
    }
    temp3->exp=temp1->exp;
    temp3->coef=temp1->coef;
    temp3->nxt=head3;
    temp1=NULL;
}


return head3;
}

int power(int x,int exp){
    if(exp==-1)
        return 1;
    int i=0,val=1;
    for(i;i<=exp;i++)
        val=x*val;
    return val;
}

int evaluate(int x,struct node *head){
int val=0;
struct node *temp;
temp=head;
do{
    val=val+temp->coef*power(x,temp->exp);
    temp=temp->nxt;
}while(temp!=head);

return val;
}





int main(){
struct node *head1,*head2,*head3;
head3=NULL;
int op1,op2,x;
cout<<"First polynomial\n";
head1=create();
cout<<"\nSecond polynomial\n";
head2=create();
cout<<endl;
display(head1);
display(head2);
do{
cout<<"\nEnter option\n1.Display polynomial\n2.Add polynomials\n3.Evaluate polynomial\n4.Exit\n";
cin>>op1;
switch(op1){
case 1: cout<<"Which polynomial?\n1.First\n2.Second\n3.Addition of polynomial\n";
        cin>>op2;
        if(op2==1)
            display(head1);
        else if(op2==2)
            display(head2);
        else if(op2==3){
            if(head3==NULL)
                cout<<"Addition is not yet performed,Please add\n";
            else
                display(head3);
        }
        break;
case 2: head3=add(head1,head2);
        cout<<"Addition of the two polynomial is:\n";
        display(head3);
        break;
case 3: cout<<"Which polynomial?\n1.First\n2.Second\n3.Addition of polynomial\n";
        cin>>op2;
        cout<<"Enter value of x: ";
        cin>>x;
        cout<<"Value of polynomial is ";
        if(op2==1)
            cout<<evaluate(x,head1)<<endl;
        else if(op2==2)
            cout<<evaluate(x,head2)<<endl;
        else if(op2==3){
            if(head3==NULL)
                cout<<"Addition is not yet performed,Please add\n";
            else
                cout<<evaluate(x,head3)<<endl;
        }
        break;
case 4: break;
}
}while(op1!=4);
return 0;
}
