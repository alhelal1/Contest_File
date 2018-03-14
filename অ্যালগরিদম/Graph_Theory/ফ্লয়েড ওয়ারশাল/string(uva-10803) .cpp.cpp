#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

#define INFINITY 2147483645
#define MAX 102

double adj[MAX][MAX];

void init(int noOfNodes)
{
  for(int i=1;i<=noOfNodes;i++)
    for(int j=1;j<=noOfNodes;j++)
     adj[i][j] = INFINITY;
}

void floydWarshall(int noOfNodes)
{
  for(int k=1;k<=noOfNodes;k++)
    for(int i=1;i<=noOfNodes;i++)
      for(int j=1;j<=noOfNodes;j++)
        adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
}

int main(){
    freopen("inMe.txt","r",stdin);
    freopen("outMe.txt","w",stdout);

    int testCase;
    cin>>testCase;
    for(int t=1;t<=testCase;t++){
      int N;
      cin>>N;
      init(N);
      int ar[N+1][2];
      for(int i=1;i<=N;i++)
        {
        cin>>ar[i][0];
        cin>>ar[i][1];
      }
      for(int i=1;i<=N;i++)
      {
        for(int j=1;j<=N;j++)
        {
            int h;
h=abs((ar[i][0]-ar[j][0])*(ar[i][0]-ar[j][0])+(ar[i][1]-ar[j][1])*(ar[i][1]-ar[j][1]));
         double dist = sqrt((double)h);
         if(dist<=10.0)
        adj[i][j] = dist;
        }
      }
      floydWarshall(N);
      double maxV = -1.0;
      for(int i=1;i<=N;i++)
       {
        for(int j=1;j<=N;j++)
        {
          maxV = max(maxV,adj[i][j]);
        }
       }
       printf("Case #%d:\n",t);
       if(maxV!=INFINITY)
       printf("%0.4lf\n\n",(double)maxV);
       else printf("Send Kurdy\n\n");
    }
   return 0;
}
