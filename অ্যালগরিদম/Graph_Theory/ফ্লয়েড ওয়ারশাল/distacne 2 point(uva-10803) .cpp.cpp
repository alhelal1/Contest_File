#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
#define INFINITY 2147483645
#define MAX 102
double arr[MAX][MAX];
void init(int n)
{
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
     adj[i][j] = INFINITY;
}
void floydWarshall(int n)
{
    for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
        }
    }
}
int main()
{
    int kase;
    int ar[100][10];
    cin>>kase;
    for(int kase=1;kase<=n;kase++)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            ar[i][0]=a;
            ar[i][1]=b;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)continue;
              double  res=hypot(ar[i][0]-ar[j][0],ar[i][1]-ar[j][i]);
            }
        }
    }
   return 0;
}
