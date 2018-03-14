using namespace std;
#include<bits/stdc++.h>
typedef long long  ll;
typedef   pair<ll,ll>  pii;
typedef   vector< pii > vpii;
typedef   vector<long long>   vi;
typedef   map<string,ll>  msi;
typedef   map<ll,ll>  mii;

#define rep(x,n) for(__typeof(n) x=0;x<(n);x++)
#define reps(i,x) for(int  i=0;i<(x.size());i++)
#define repp(x,n) for(__typeof(n) x=1;x<=(n);x++)
#define foreach(x,n) for(__typeof(n.begin()) x=n.begin();x!=n.end();x++)
///Shortcut
#define mem(ar,value) memset(ar,value,sizeof(ar))
#define all(x) x.begin(),x.end()
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define len(s) s.size()
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
///Min AND Max
#define min4(a,b,c,d) min(min(a,b),min(c,d))
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define maxall(v) *max_element(all(v))
#define minall(v) *min_element(all(v))
#define eps (1e-9)
#define PI acos(-1.0)
#define mod 1e9+7
#define isEq(a,b) (fabs((a)-(b))<eps)
#define Dist(x1,y1,x2,y2) (sqrt(sqr((x1)-(x2))+sqr((y1)-(y2))))
///File
#define READ freopen("input.txt","r",stdin)
#define WRITE freopen("output.txt","w",stdout)
/**Define Bitwise operation**/
#define check(n, pos) (n & (1<<(pos)))
#define biton(n, pos) (n | (1<<(pos)))
#define bitoff(n, pos) (n & ~(1<<(pos)))
#define ledzero(n) (__builtin_clz(n))
#define trailzero(n) (__builtin_ctz(n))
#define onbit(n) (__builtin_popcount(n))

///Gcd and Lcm
template<class T>T gcd(T a,T b){return b == 0 ? a : gcd(b, a % b);}
template<typename T>T lcm(T a, T b) {return a / gcd(a,b) * b;}
///Bigmod && Pow
template<class T>T my_pow(T n,T p){if(p==0)return 1;T x=my_pow(n,p/2);x=(x*x);if(p&1)x=(x*n);return x;} ///n to the power p
template<class T>T big_mod(T n,T p,T m){if(p==0)return (T)1;T x=big_mod(n,p/2,m);x=(x*x)%m;if(p&1)x=(x*n)%m;return x;}
template<class T> inline T Mod(T n,T m) {return (n%m+m)%m;} ///For Positive Negative No.
///string to int
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}/// extract words or numbers from a line
template<class T> string itos(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}///NOTES:toString(
ll stoi(string s){ll r=0;istringstream sin(s);sin>>r;return r;}///NOTES:toInt(
double toDouble(string s){double r=0;istringstream sin(s);sin>>r;return r;}
//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};///8 Direction
int col[4] = {1, 0, -1, 0};int row[4] = {0, 1, 0, -1};///4 Directionint
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};///Knight Direction
//int dx[]={-1,-1,+0,+1,+1,+0};int dy[]={-1,+1,+2,+1,-1,-2};///Hexagonal Direction
//struct info{ll x,y;}arr[100005];bool com(info a,info b){return (a.x<b.x) or (a.x==b.x and a.y<b.y);}


//ll ar[2000005],ar1[2000005];
int  ar[1000][1000];
int  dp[1000][1000];
int  a=0,b=0,c=0,r=0,rr=0,res=0,n,m;

void init()
{
   rep(i,1000)rep(j,1000)dp[i][j]=1000000000;
    dp[0][0]=ar[0][0];
}

struct info
{
    ll x,y,cost;

    bool operator  <( const  info& p)const
    {

        return cost>p.cost;

    }

};

int   go(int  i,int  j)
{
    priority_queue<info>pq;
    info u,v;
    u.x=i,u.y=j,u.cost=ar[0][0];

    pq.push(u);

    while(pq.size()>0)
    {
        v=pq.top();

        pq.pop();

        int  aa=v.x,bb=v.y,cc=v.cost;

        if(aa==n-1 and bb==m-1)   return dp[n-1][m-1];
        rep(k,4)
        {
            int  xx=aa+row[k];
            int  yy=bb+col[k];
            if(xx>=0 and yy>=0 and xx<n and yy<m)
            {
                if(dp[xx][yy]>(dp[aa][bb]+ar[xx][yy]))
                {
                    dp[xx][yy]=dp[aa][bb]+ar[xx][yy];
                    info w;
                    w.x=xx,w.y=yy,w.cost=dp[xx][yy];
                    pq.push(w);

                }
            }
        }
    }

    return dp[n-1][m-1];
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(false);

    int  t=0,ks=0;


    scanf("%d",&t);
    while(t--)
    {
       scanf("%d%d",&n,&m);
        rep(i,n)
        {
            rep(j,m)
            {
                scanf("%d",&ar[i][j]);
            }
        }

        init();

        int  ret=go(0,0);

        printf("%d\n",ret);

    }








   return 0;

}
