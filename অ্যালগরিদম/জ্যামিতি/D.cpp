#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<fstream>
#include<sstream>
#include<stack>
#include<list>
#include<deque>
#include<bitset>
#include<utility>
#include<climits>
#include<iomanip>
#include<ctime>
#include<complex>
#include<set>
using namespace std;


#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

#define inf INT_MAX/3
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define SET(a,c) memset(a,c,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define pii pair<int,int>
#define pcc pair<char,char>
#define pic pair<int,char>
#define pci pair<char,int>
#define VS vector<string>
#define VI vector<int>
#define debug(x) cout<<#x<<": "<<x<<endl
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define pi 2*acos(0.0)
#define INFILE() freopen("in0.txt","r",stdin)
#define OUTFILE()freopen("out0.txt","w",stdout)
#define in scanf
#define out printf
#define ll long long
#define ull unsigned long long
#define eps 1e-9


//TYO conversion
template<typename T>inline string toString(T a)
{
    ostringstream os("");
    os<<a;
    return os.str();
}
template<typename T>inline ll toLong(T a)
{
    ll res;
    istringstream os(a);
    os>>res;
    return res;
}
//MATHEMATICS
template<typename T>inline T  S(T a)
{
    return a*a;
}
template<typename T>inline T gcd(T a, T b)
{
    if (b == 0)return a;
    else return gcd(b, a % b);
}
template<typename T>inline ull bigmod(T a, T b, T m)
{
    if (b == 0)return 1;
    else if (b % 2 == 0)return S(bigmod(a, b / 2, m)) % m;
    else return (a % m*bigmod(a, b - 1, m)) % m;
}
template<typename T>inline VS parse(T str)
{
    VS res;
    string s;
    istringstream os(str);
    while(os>>s)res.pb(s);
    return res;
}
template<typename T>inline ull  dist(T A,T B)
{
    ull res=(A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
    return res;
}
template<typename T>inline double cosAngle(T a,T b,T c)
{
    double res=a*a+b*b-c*c;
    res=res/(2*a*b);
    res=acos(res);
    return res;
}
template<typename T>inline T power(T base,int po)
{
    T res=1;
    if(base==0)return 0;
    FOR(i,0,po)res*=base;
    return res;
}
//BIT
template<typename T>inline bool isOn(T mask,T pos)
{
    return mask&(1<<pos);
}
template<typename T>inline int Off(T mask,T pos)
{
    return mask^(1<<pos);
}
template<typename T>inline int On(T mask,T pos)
{
    return mask|(1<<pos);
}

#define Mx 20
char g[Mx][Mx];
int w[Mx][Mx];

int r,c;
struct Z
{
    int x,y;
};

vector<Z>v;
Z z;
int dp[16][(1<<16)+3];
int N;
int solve(int pos , int bit)
{

    if(bit==(1<<N)-1)
    {
        return w[pos][0];
    }

    int &ret=dp[pos][bit];
    if(ret!=-1)return ret;
    ret=inf;
    for(int i=1; i<N; i++)
    {
        if((bit&(1<<i))==0)
        {
            ret=MIN(ret,solve(i,bit|(1<<i) )+w[pos][i] );
        }
    }
    return ret;
}


int main()
{
    int i,j,k;
    int ks,cas,r,b;
    cin>>ks;
    FOR(cas,1,ks+1)
    {
        scanf("%d%d",&r,&c);
        FOR(i,0,r)
        {
            scanf("%s",g[i]);
        }
        v.clear();
        FOR(i,0,r)
        {
            FOR(j,0,c)
            if(g[i][j]=='x')
            {
                z.x=i;
                z.y=j;
                v.pb(z);

            }
        }

        FOR(i,0,r)
        {
            FOR(j,0,c)
            if(g[i][j]=='g')
            {
                z.x=i;
                z.y=j;
                v.pb(z);
            }
        }

        N=v.size();

        FOR(i,0,N)
        {
            FOR(j,0,N)
            {
                w[i][j]=max(abs(v[i].x-v[j].x),abs(v[i].y-v[j].y ) );
            }
        }
        SET(dp,-1);
        int res=solve(0,1);
        printf("Case %d: %d\n",cas,res);

    }

    return 0;
}
