#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define fr(i,n) for(__typeof(n) i=0; i<(n); i++)
#define fre(i,n) for(__typeof(n) i=1; i<=(n); i++)
#define frt(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define inf 1061109567000LL
#define PI 3.14159265358979323846264338327950
#define PB(x) push_back(x)
#define ALL(x) x.begin(),x.end()
#define SZ size()
#define eps 1e-9
#define VI vector<int>
#define VS vector<string>
#define LL long long
#define MII map<int,int>
#define MSI map<string,int>
#define MIS map<int,string>
#define CLEAR(x) memset(x,0,sizeof(x));
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
using namespace std;

long long dp[205][105];
long r,c,ar[205][105],n;
long long rec(long i, long j)
{
    if(i>=r||j<0||j>c) return 0;
   // cout<<i<<" "<<j<<" "<<r<<" "<<c<<" "<<n<<" "<<"\n ";
    if(dp[i][j]!=-1) return dp[i][j];
    if(i<n)
    return dp[i][j]=ar[i][j]+max(rec(i+1,j),rec(i+1,j+1));
    else  return dp[i][j]=ar[i][j]+max(rec(i+1,j-1),rec(i+1,j));
}
int main()
{
ios_base::sync_with_stdio(false);
//freopen("input.txt","r",stdin);
long t,k;
cin>>t;
for(k=1;k<=t;k++){
long i,j;
cin>>n;
n--;
memset(dp,-1,sizeof(dp));
memset(ar,0,sizeof(ar));
r=n*2+1;
c=n;
for(i=0;i<=n;i++)
for(j=0;j<=i;j++)
cin>>ar[i][j];

long p=c-1;
for(i=n+1;i<r;i++,p--)
for(j=0;j<=p;j++)
cin>>ar[i][j];

cout<<"Case "<<k<<": ";
cout<<rec(0,0)<<endl;
}
return 0;
}
