#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <string.h>
//freopen ("in.txt" , "r" , stdin);
using namespace std;

#define eps 1e-8
const double pi=acos(-1.0);
typedef long long LL;
const int Max=500100;
const int INF=1000000007;
int n,x;
LL dp[Max][30];
int mm[Max];
void RMQ(int n,LL b[])
{
    mm[0] = -1;
    for(int i = 1; i <= n; i++)
    {
        mm[i] = ((i&(i-1)) == 0)?mm[i-1]+1:mm[i-1];
        dp[i][0] = b[i];
    }
    for(int j = 1; j <= mm[n]; j++)
        for(int i = 1; i + (1<<j) -1 <= n; i++)
            dp[i][j] = max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}
LL query(int x,int y)
{
    int k = mm[y-x+1];
    return max(dp[x][k],dp[y-(1<<k)+1][k]);
}
LL num[Max];
LL sum[Max];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%d%d",&n,&x);
        for(int i=1; i<=n; i++)
            scanf("%lld",num+i),sum[i]=sum[i-1]+num[i];
        RMQ(n,sum);
        int ans=n+3;
        for(int i=0; i<n; i++)
        {
            int l=i+1,r=n;
            while(l<r)
            {
                int mid=(l+r)/2;
                if(query(i+1,mid)-sum[i]>=x)
                    r=mid;
                else
                    l=mid+1;
            }
            if(sum[r]-sum[i]==x)
                ans=min(ans,r-i);
            if(sum[l]-sum[i]==x)
                ans=min(ans,l-i);
        }
        if(ans==n+3)
            ans=-1;
        cout<<ans<<endl;
    }
    return 0;
}
///https://icpcarchive.ecs.baylor.edu/external/66/6609.pdf
///6609 Minimal Subarray Length

