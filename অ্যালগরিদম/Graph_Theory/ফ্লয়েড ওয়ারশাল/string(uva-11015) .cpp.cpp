#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

#define MAX 100

int adj[MAX][MAX];

void floydWarshall(int noOfNodes)
{
    for(int k=1;k<=noOfNodes;k++)
    for(int i=1;i<=noOfNodes;i++)
    for(int j=1;j<=noOfNodes;j++)
    adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
}

void initAdj(int N)
{
  for(int i=1;i<=N;i++)
    {
     for(int j=1;j<=N;j++)
       if(i==j)adj[i][j] = 0;
       else
        adj[i][j] = 999999999;
    }
}
int getMin(int N){
  int min = 2147483030;
  int minIndex = 1;

  for(int i=1;i<=N;i++)
    {
    int sum = 0;
    for(int j=1;j<=N;j++)
    sum += adj[i][j];
    if(sum<min)
    {
    min = sum;
    minIndex = i;
    }
  }
  return minIndex;
}

int main()
{
    int N,M;
    char allNames[30][20];
    int testCase = 1;

    while(scanf("%d %d ",&N,&M)==2 && N!=0)
        {
       initAdj(N);
       for(int i=0;i<N;i++)
       gets(allNames[i]);
       for(int i=0;i<M;i++)
       {
        int from,to,cost;
        ///scanf("%d %d %d",&from,&to,&cost);
        cin>>from>>to>>cost;
        adj[from][to]=adj[to][from] = cost;
       }
       printf("Case #%d : ",testCase++);
       if(M==0)
       printf(allNames[0]);
       else
       {
       floydWarshall(N);
       printf(allNames[getMin(N)-1]);
       }
       printf("\n");
    }

    return 0;
}
