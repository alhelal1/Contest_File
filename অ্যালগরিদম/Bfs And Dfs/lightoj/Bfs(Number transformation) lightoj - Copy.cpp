using namespace std;
#include<bits/stdc++.h>
typedef long long  ll;

///Input
#define pf printf
#define sf(n)       scanf("%lld", &n)
#define sff(a,b)    scanf("%lld %lld", &a, &b)
#define sfff(a,b,c) scanf("%lld %lld %lld", &a, &b, &c)
#define Case(no) printf("Case %d: ",++no)

///LOOP
#define rep(x,n) for(__typeof(n) x=0;x<(n);x++)
#define reps(i,x) for(int  i=0;i<(x.size());i++)
#define repp(x,n) for(__typeof(n) x=1;x<=(n);x++)
#define FOR(x,m,n) for(__typeof(n) x=(m);x<=(n);x++)
#define foreach(x,n) for(__typeof(n.begin()) x=n.begin();x!=n.end();x++)

///Shortcut
#define mem(ar,value) memset(ar,value,sizeof(ar))
#define all(x) x.begin(),x.end()
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define sqr(x) ((x)*(x))
#define len(s) s.size()
#define mp make_pair
#define pb push_back
#define xx first
#define yy second

///Min AND Max
#define min4(a,b,c,d) min(min(a,b),min(c,d))
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))

#define maxall(v) *max_element(all(v))
#define minall(v) *min_element(all(v))

#define inf (1e15)
#define eps (1e-9)
#define PI acos(-1.0)
#define pi 3.14159265358979323846
#define isEq(a,b) (fabs((a)-(b))<eps)
#define Dist(x1,y1,x2,y2) (sqrt(sqr((x1)-(x2))+sqr((y1)-(y2))))
#define spDist(lat1,long1,lat2,long2,r) ((r)*acos(sin(lat1)*sin(lat2)+cos(lat1)*cos(lat2)*cos((long1)-(long2))))
#define area(x1,y1,x2,y2,x3,y3) ( x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2) )
#define sqr(x) ((x)*(x))
#define distSqr(x1,y1,x2,y2) ( sqr(x1-x2) + sqr(y1-y2) )
#define dist4adj(x1,y1,x2,y2) ( abs(x1-x2) + abs(y1-y2) )
#define dist8adj(x1,y1,x2,y2) max( abs(x1-x2) , abs(y1-y2) )


///File
#define READ freopen("input.txt","r",stdin)
#define WRITE freopen("output.txt","w",stdout)


/**Define Bitwise operation**/

template<class T> inline T lowbit(T n){return (n^(n-1))&n;}//NOTES:lowbit(
template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}
#define check(n, pos) (n & (1<<(pos)))
#define biton(n, pos) (n | (1<<(pos)))
#define bitoff(n, pos) (n & ~(1<<(pos)))

#define ledzero(n) (__builtin_clz(n))
#define trailzero(n) (__builtin_ctz(n))
#define onbit(n) (__builtin_popcount(n))

///upper bound and lower bound
#define LB(a,value) (lower_bound(all(a),value)-a.begin())
#define UB(a,value) (upper_bound(all(a),value)-a.begin())

///DEBUG
#define dbg(x) cout<<#x<<": "<<x<<endl
#define dbgar(i,a) cout<<#a<<"["<<i<<"] = "<<a[i]<<" "<<endl


#define trace(x) cerr<<x<<endl;
#define d1(x) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
#define d2(x,y) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<endl;
#define d3(x,y,z) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
#define d4(a,b,c,d) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<endl;
#define d5(a,b,c,d,e) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<endl;
#define d6(a,b,c,d,e,f) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<" | "#f" = "<<f<<endl;



///Gcd and Lcm
template<class T>T gcd(T a,T b){return b == 0 ? a : gcd(b, a % b);}
template<typename T>T lcm(T a, T b) {return a / gcd(a,b) * b;}

///Bigmod && Pow
template<class T>T my_pow(T n,T p){if(p==0)return 1;T x=my_pow(n,p/2);x=(x*x);if(p&1)x=(x*n);return x;} ///n to the power p
template<class T>T big_mod(T n,T p,T m){if(p==0)return (T)1;T x=big_mod(n,p/2,m);x=(x*x)%m;if(p&1)x=(x*n)%m;return x;}
template<class T> inline T Mod(T n,T m) {return (n%m+m)%m;} ///For Positive Negative No.


template<class T>T multiplication(T n,T p,T m){if(p==0)return (T)0;T x=multiplication(n,p/2,m);x=(x+x)%m;if(p&1)x=(x+n)%m;return x;}
bool isVowel(char ch){ ch=toupper(ch); if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true; return false;}

///string to int
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}/// extract words or numbers from a line

template<class T> string itos(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}///NOTES:toString(
ll stoi(string s){ll r=0;istringstream sin(s);sin>>r;return r;}///NOTES:toInt(
double toDouble(string s){double r=0;istringstream sin(s);sin>>r;return r;}


/**Direction**/
///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};int row[8] = {1, 1, 0, -1, -1, -1, 0, 1}; ///8 Direction
int col[4] = {1, 0, -1, 0};int row[4] = {0, 1, 0, -1}; ///4 Direction
///int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};///Knight Direction
///int dx[]={-1,-1,+0,+1,+1,+0};int dy[]={-1,+1,+2,+1,-1,-2}; ///Hexagonal Direction

//const int mod= 1e9+7;



typedef queue <int> qi;
typedef   pair<ll,ll>  pii;
typedef   vector< pii > vpii;
typedef   vector<long long>   vi;
typedef   vector<string>   vs;
typedef   map<string,ll>  msi;
typedef   map<ll,ll>  mii;
typedef   map<char,ll>  mci;


struct node
{
    ll x,y;
    double z;
}arr[200005];


bool com(node a, node b)
{
   return a.x<b.x;
}



#define N 200007


ll a=0,b=0,c=0,cc=0,n=0,m=0,res=0,t=0,f=0,ff=0,cnt=0,cost=0,ks=0,k;
ll mn=inf,mx=-inf;

ll ar[1005],ar1[200002];
ll tot;
string ch[100005];
ll vis[100006];
vi v;vi vv[100009];
void seive()
{
    vis[0]=vis[1]=true;
    v.pb(2);
    for(int i=3;i<=10005;i+=2)
    {
        if(vis[i]==false)
        {
            v.pb(i);
            for(int j=2*i;j<=100005;j+=i)
            {
                vis[j]=true;
            }
        }
    }
}
void  factor()
{
    for(int i=2;i<=1005;i++)
    {
        ll aa=i;
        for(int j=0;aa>=v[j];j++)
        {
            if(aa%v[j]==0)
            {
                vv[i].pb(v[j]);
                while(aa%v[j]==0)
                {
                    aa/=v[j];
                }
            }
        }
        if(aa!=1)vv[i].pb(aa);
    }
}
ll ans[100005];
ll call(ll sou,ll des)
{
    qi q;
    while(!q.empty())q.pop();
    vis[sou]=true;
    ans[sou]=0;
    q.push(sou);
    ll res=sou;

    while(!q.empty())
    {
        ll bb=q.front();q.pop();
        rep(i,len(vv[bb]))
        {
            ll cc=vv[bb][i];
            res=bb+cc;
          //  d3(res,cc,des);
            if(res<=des     && vis[res]==false && cc!=1 && cc!=bb)
            {
                vis[res]=true;
                ans[res]=ans[bb]+1;
                q.push(res);
            }
        }
    }
    return 0;
}
int main()
{
   // ios_base::sync_with_stdio(false);

   seive();
   factor();



   sf(t);
   while(t--)
   {
       mem(ans,-1);
       mem(vis,false);
       sff(a,b);
       call(a,b);
      call(a,b);
      ll dd=ans[b];
      Case(ks);
      pf("%lld\n",dd);


   }


}
