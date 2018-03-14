#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define MAX 105

int adj[MAX][MAX];

void init(int noOfNodes)
{
  for(int i=1;i<=noOfNodes;i++)
     for(int j=1;j<=noOfNodes;j++)
        adj[i][j] = -1;
}

void floydWarshall(int noOfNodes)
{
          //init(noOfNodes);
    for(int k=1;k<=noOfNodes;k++)
        for(int i=1;i<=noOfNodes;i++)
            for(int j=1;j<=noOfNodes;j++)
            {
                   if(!(adj[i][k]==-1 || adj[k][j]==-1) && (i!=j))
                    {
                         if(adj[i][k]+adj[k][j]<adj[i][j] || adj[i][j]==-1)
                         {
                            adj[i][j] = adj[i][k]+adj[k][j];
                         }
                    }
            }
}


int main()
{
    int from,to;
    int testCase=1;
    while(scanf("%d %d",&from,&to)==2 && !(from==0&&to==0))
        {
      init(100);
      adj[from][to] = 1;
      adj[from][from] = adj[to][to] = 0;
      while(scanf("%d %d",&from,&to)==2 &&!(from==0&&to==0))
      {
        adj[from][to] = 1;
        adj[from][from] = adj[to][to] = 0;
      }

      floydWarshall(100);
      int nodes = 0,sum=0;
      for(int i = 1;i<=100;i++){
              for(int j=1;j<=100;j++)
                {
                 if(i==j&&adj[i][j]==0)
                 nodes++;
                 if(adj[i][j]!=-1)
                 sum += adj[i][j];
             }
      }
      float res = nodes*(nodes-1);
      printf("Case %d: average length between pages = %.3f clicks\n",testCase++,(float)((float)sum/res));
    }


  return 0;

}
