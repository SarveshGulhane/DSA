#include<iostream>
using namespace std;

void dfs(int** edges, int n, int sv, bool*vis)
{
     cout<<sv<<endl;
     vis[sv]=true;

     for(int i=0;i<n;i++)
     {
          if(i==sv)
               continue;

          if(edges[sv][i]==1)
          {
               if(vis[i])
                    continue;
               
               dfs(edges,n,i,vis);
          }
     }
}

int main()
{
     int v,e,i,j,n,sv;
     cout<<"Enter no. of vertices and Edges:\n";
     cin>>v>>e;

     cout<<"Enter Edges:\n";
     int** edges=new int*[n];
     for(i=0;i<n;i++)
     {
          edges[i]=new int[n];
          for(j=0;j<n;j++)
          {
               edges[i][j]=0;
          }
     }

     for(i=0;i<e;i++)
     {
          int f,s;
          cin>>f>>s;
          edges[f][s]=1;
          edges[s][f]=1;
     }

     bool* vis=new bool[n];
     for(i=0;i<n;i++)
          vis[i]=false;

     cout<<"Enter starting vertex:\n";
     cin>>sv;

     cout<<"DFS:\n";
     dfs(edges,n,sv,vis);

     return 0;
}
