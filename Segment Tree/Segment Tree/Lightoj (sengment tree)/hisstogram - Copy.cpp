using namespace std;
#include<bits/stdc++.h>
typedef long long  ll;
typedef   pair<ll,ll>  pii;
typedef   vector< pii > vpii;
typedef   vector<long long>   vi;
typedef   map<string,ll>  msi;
typedef   map<ll,ll>  mii;
///Print
#define P(a)  printf("%lld",a)
#define PP(a,b)  printf("%lld %lld",a,b)
#define PPP  (a,b,c)  printf("%lld %lld %lld",a,b,c)
#define nl printf("\n")
#define Ca(no) printf("Case %lld: ",++no)
#define Canl(no) printf("Case %lld:\n",++no)
#define Cah(no) printf("Case #%lld: ",++no)
#define Cahnl(no) printf("Case #%lld:\n",++no)
///Scanf
#define I(n)       scanf("%lld", &n)
#define II(a,b)    scanf("%lld %lld", &a, &b)
#define III(a,b,c) scanf("%lld %lld %lld", &a, &b, &c)
///LOOP
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
#define distSqr(x1,y1,x2,y2) ( sqr(x1-x2) + sqr(y1-y2) )
#define dist4adj(x1,y1,x2,y2) ( abs(x1-x2) + abs(y1-y2) )
#define dist8adj(x1,y1,x2,y2) max( abs(x1-x2) , abs(y1-y2) )
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
///DEBUG
#define dbg(x) cout<<#x<<": "<<x<<endl
#define dbgar(i,a) cout<<#a<<"["<<i<<"] = "<<a[i]<<" "<<endl
#define trace(x) cerr<<x<<endl;
#define d1(x) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
#define d2(x,y) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<endl;
#define d3(x,y,z) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
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
//int col[4] = {1, 0, -1, 0};int row[4] = {0, 1, 0, -1};///4 Directionint
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};///Knight Direction
//int dx[]={-1,-1,+0,+1,+1,+0};int dy[]={-1,+1,+2,+1,-1,-2};///Hexagonal Direction
struct info
{
    ll x,y,z;
}arr[400005];
ll ar[100004];
void insert(ll idx,ll s,ll e)
{

    if(s==e)
    {
        arr[idx].x=ar[s];
        arr[idx].y=ar[s];
        return ;
    }
    ll mid=(s+e)/2;
    ll lf=idx*2;
    ll rt=lf+1;
    insert(lf,s,mid);
    insert(rt,mid+1,e);
    arr[idx].x=max(arr[lf].x,arr[rt].x);
    arr[idx].y=min(arr[lf].y,arr[rt].y);
}


info query(ll idx,ll s,ll e ,ll i,ll j)
{
    if(s==i and e==j)
    {
        return  arr[idx];
    }
    ll mid=(s+e)>>1;
    ll lf=idx*2;
    ll rt=lf+1;
     if(j<=mid)
     {
         return query(lf,s,mid,i,j);
     }
     else if(i>mid)
     {
         return query(rt,mid+1,e,i,j);
     }
     else
     {
         info aa,bb;
         aa=query(lf,s,mid,i,mid);
         bb=query(rt,mid+1,e,mid+1,j);
         info cc;
         cc.x=max(aa.x,bb.x);
         cc.y=min(aa.y,bb.y);
         return cc;
     }
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(false);


    ll t;ll n,m;

    I(t);

    ll ks=0;

    while(t--)
    {
        II(n,m);

        mem(arr,false);

        rep(i,n)
        {
            I(ar[i+1]);
        }
        insert(1,1,n);


        ll ans=0;

        for(int i=1;i<=n;i++)
        {
            ll a1=i,b1=i+m-1;
            if(b1>n)break;
            info dd;
            dd=query(1,1,n,a1,b1);

            ans=max(ans,dd.x-dd.y);
        }

        Ca(ks);

        P(ans);nl;
    }


   return 0;

}