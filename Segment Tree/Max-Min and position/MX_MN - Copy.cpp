#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <string.h>
#include <iostream>

#define mx 100001
#define INF 10000000

using namespace std;

int arr[mx];
int Tree[mx*3];

void makeTree(int node,int b,int e)
{
    if(b==e)
    {
        Tree[node] = arr[b];
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    makeTree(left,b,mid);
    makeTree(right,mid+1,e);

    Tree[node] = (Tree[left] ^ Tree[right]);
}

int query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
    {
        return Tree[node];
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;

    int p1 = query(left,b,mid,i,j);
    int p2 = query(right,mid+1,e,i,j);

    return p1^p2;
}

int main()
{
    int test,N,q,cas=0;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&N);
        for(int i=1; i<=N; i++)
            scanf("%d",&arr[i]);

        makeTree(1,1,N);

        int i,j;

      //  printf("Case %d:\n",++cas);

        //cin>>q;

        scanf("%d",&q);

        while(q--)
        {
            scanf("%d %d",&i,&j);

            //cout<<123<<endl;
            printf("%d\n",query(1,1,N,i,j));
        }

        memset(arr,0,sizeof arr);
        memset(Tree,0,sizeof Tree);
    }
    return 0;
}
