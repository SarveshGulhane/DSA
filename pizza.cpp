#include<iostream>

using namespace std;

class pizza
{
        int front,rear,q[5];
        public:
                pizza()
                {
  	                front=-1;
  	                rear=-1;
                }
 
                int isfull()
                {
                        if((front==0&&rear==4)||front==rear+1)
                        {
  		                return 1;
                        }
                        else
                        {
   		                return 0;
                        }
                }      
 
                int isempty()
                {
                        if(front==-1&&rear==-1)
                        {
   	                        return 1;
                        }
                        else
                        {
   	                        return 0;
                        }
                }
 
                void add()
                {
  	                if(isfull()==0)
  	                {
  	 	                cout<<"\n Enter the Pizza ID: ";
  	 	                if(front==-1&&rear==-1)
  	 	                {
  	  		                front=0;
  	  		                rear=0;
  	  		                cin>>q[rear];
  	 	                }
  	 	                else
  	 	                {
  	   		                rear=(rear+1)%5;
  	   		                cin>>q[rear];
  	 	                }
   		                char c;
 		                cout<<" Do you want to add another order ? ";
   		                cin>>c;
   		                if(c=='y'||c=='Y')
  	 	                add();
  	                }
  	                else
  	                {
  	 	                cout<<"\n Orders are full ";
  	                }
  	
                }
 
                void serve()
                {
  	                if(isempty()==0)
  	                {
  	 	                if(front==rear)
  	 	                {
  	 	 	                cout<<"\n Order served is : "<<q[front];
  	 	 	                front=-1;
  	 	 	                rear=-1;
  	 	                }
  	 	                else
  	 	                {
  	 	 	                cout<<"\n Order served is : "<<q[front];
  	 	 	                front=(front+1)%5;
  	 	                }
  	                }
  	                else
  	                {
  	 	                cout<<"\n Orders are empty ";
  	                }
                }
 
                void display()
                {
  	                if(isempty()==0)
  	                {
  	                        for(int i=front;i!=rear;i=(i+1)%5)
  	                        {
  	  	                        cout<<q[i]<<" <- ";
  	                        }
  	 	                cout<<q[rear];
  	                }
  	                else
  	                {
 	 	                cout<<"\n Orders are empty";
 	                }
                }
 
               
};
 
 int main()
 {
        pizza pi;
        int ch;
          cout<<"PIZZA PARLOUR !\n";
          do
          {              
                        
               cout<<"\n 1.Add a Pizza in Queue 2.Display the Orders 3.Serve a pizza 4.Exit\n";
               cin>>ch;
                    switch(ch)
                    {             
                                case 1:
                                        pi.add();
                                        break;
   
                                case 2:
                                        pi.display();
                                        break;
   
                                case 3:
                                        pi.serve();
                                        break;
   
                                        
                        }
          }while(ch!=4);
        return 0;
 }
