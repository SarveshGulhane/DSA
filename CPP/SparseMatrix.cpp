#include<iostream>
using namespace std;
class sparse
{
     int mat[20][20],sp[20][20],i,j,row,col,ctr;

     public:
     void read()
     {
          ctr=0;
          cout<<"Enter the number of row and column: \n";
          cin>>row>>col;

          for(i=0;i<row;i++)
          {
               for(j=0;j<col;j++)
               {
                    cout<<"Enter "<<i<<", "<<j<<endl;
                    cin>>mat[i][j];

                    if(mat[i][j]>0)
                    {
                         ctr++;
                         sp[ctr][0]=i;
                         sp[ctr][1]=j;
                         sp[ctr][2]=mat[i][j];

                    }
               }
          }

          sp[0][0]=row;
          sp[0][1]=col;
          sp[0][2]=ctr;

     }

     void dispsp()
     {
          cout<<"Sparse matrix is: \n";
          for(i=0;i<=ctr;i++)
          {
               for(j=0;j<3;j++)
               {
                    cout<<sp[i][j]<<" ";
               }
               cout<<"\n";
          }
     }

     void strans()
     {
          int strans[ctr+1][3],q=1;

          strans[0][0]=sp[0][1];
          strans[0][1]=sp[0][0];
          strans[0][2]=sp[0][2];

          cout<<"Simple Transpose is: \n";

          for(i=0;i<col;i++)
          {
               for(int p=1;p<=ctr;p++)
               {
                    if(sp[p][1]==i)
                    {
                         strans[q][0]=sp[p][1];
                         strans[q][1]=sp[p][0];
                         strans[q][2]=sp[p][2];
                         q++;
                    }
               }
          }

          for(i=0;i<=ctr;i++)
               {
                    for(j=0;j<3;j++)
                    {
                         cout<<strans[i][j]<<" ";
                    }
                    cout<<"\n";
               }
     }

     void fasttran()
     {
          int b[ctr][3];
          int i,  j,  p;       

          int numTerms = sp[0][2];
          int numCols = sp[0][1];
          int row_terms[numCols],  start_pos[numCols];
          b[0][0] = numCols;
          b[0][1] = sp[0][0];
          b[0][2] = numTerms;
          if(numTerms>0)
          {
               for(i =0;i<numCols;i++)
               {
                    row_terms[i] = 0;
               }

               for(i=1; i<=numTerms; i++)
               {
                    row_terms[sp[i][1]]++;
               }

               start_pos[0]=1;

               for(i=1; i<numCols; i++)
               {
                    start_pos[i] = start_pos[i-1] + row_terms[i-1];
               }

               for(i=1; i<=numTerms; i++)
               {
                    j = start_pos[sp[i][1]]++;
                   	b[j][0] = sp[i][1];
                    b[j][1] = sp[i][0];
                    b[j][2] = sp[i][2];
               }
          }
          
          printf("\nThe Fast Transpose sparse matrix is:\n");

          for(p=0; p<=sp[0][2]; p++)
          {
               printf("%d ", b[p][0]);
               printf("%d ", b[p][1]);
               printf("%d ", b[p][2]);
               cout<<endl;
          }
     }    
};

int main()
{
     int op;
     sparse obj;
     obj.read();
     
     do
     {
		cout<<"\nEnter operation\n1.display 2.Simple Transpose 3.Fast Transpose 4.Exit\n";
	     cin>>op;
	     
	     switch(op)
	     {
	     	case 1:
	     		obj.dispsp();
	     	break;
	     	
	     	case 2:
	     		obj.strans();
	     	break;
	     	
	     	case 3:
	     		obj.fasttran();
	     	break;
	     }
	     	
     }while(op!=4);
     
     return 0;
}
