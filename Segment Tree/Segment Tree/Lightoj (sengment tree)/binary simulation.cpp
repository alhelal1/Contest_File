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
#define NL printf("\n")
#define CA(no) printf("Case %lld: ",++no)
#define casenl(no) printf("Case %lld:\n",++no)
#define CAH(no) printf("Case #%lld: ",++no)
#define CAHNL(no) printf("Case #%lld:\n",++no)
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


ll n,a,b,c,m,tree[400005];



ll ar[400005];

string s;

void insert(ll idx,ll st,ll end)
{
    if(st==end)
    {
        tree[idx]=ar[st];

        return ;
    }

    ll mid=(st+end)>>1,L=idx*2,R=L+1;


    insert(L,st,mid);
    insert(R,mid+1,end);
    tree[idx]=min(tree[L],tree[R]);
    return ;

}






ll read(ll idx,ll st,ll end,ll i,ll j)
{
    if(st==i and end==j)
    {

        return tree[idx];

    }

    ll mid=(st+end)>>1,L=idx*2,R=L+1;


    if(j<=mid)
    {
        return read(L,st,mid,i,j);
    }
    else if(i>mid)
    {
        return read(R,mid+1,end,i,j);
    }
    else
    {
        ll p=read(L,st,mid,i,mid);
        ll q=read(R,mid+1,end,mid+1,j);


        return  min(p,q);
    }

}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(false);

    ll t,ks=0;

    scanf("%lld",&t);

    while(t--)
    {

        mem(tree,false);

        scanf("%lld",&n);
       // scanf("%lld",&m);

        rep(i,n)scanf("%lld",&ar[i+1]);


        printf("Case %lld:\n",++ks);


        insert(1,1,n);


        for(int i=1;i<=n;i++)
        {
            ll lo=1,hi=i-1;

            ll aa=ar[i];

            while(lo<=hi)
            {
                ll mid=(lo+hi)>>1;


                ll bb=read(1,1,n,mid,i);

                if(bb>=aa)
                {


                    r+=()
                }





            }
        }



    }





   return 0;

}
