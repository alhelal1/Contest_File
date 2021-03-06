using namespace std;
#include<bits/stdc++.h>
typedef long long  ll;
typedef   pair<ll,ll>  pii;
typedef   vector< pii > vpii;
typedef   vector<long long>   vi;
typedef   map<string,ll>  msi;
typedef   map<ll,ll>  mii;
///Print
#define out(a)  printf("%lld\n",a)
#define out2(a,b)  printf("%lld %lld\n",a,b)
#define out3(a,b,c)  printf("%lld %lld %lld\n",a,b,c)
#define nl printf("\n")
///Case
#define case(no) printf("Case %lld: ",++no)
#define casenl(no) printf("Case %lld:\n",++no)
#define caseh(no) printf("Case #%lld: ",++no)
#define casehnl(no) printf("Case #%lld:\n",++no)
///Scanf
#define in(n)       scanf("%lld", &n)
#define in2(a,b)    scanf("%lld %lld", &a, &b)
#define in3(a,b,c) scanf("%lld %lld %lld", &a, &b, &c)
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
///DEBUG
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

ll ar[2000005],ar1[2000005];
ll a=0,b=0,c=0,r=0,rr=0,res=0,n,m;
string s,s1;
ll par[100005];
vi v[100005];

ll vis[100005];

ll dfs(ll st,ll end)
{
    queue<ll>q;;
    vis[st]=1;
    q.push(st);
    par[st]=-1;
    while(q.size())
    {
        ll aa=q.front();q.pop();
        rep(i,len(v[aa]))
        {
            ll bb=v[aa][i];
            if(vis[bb]==0)
            {
                q.push(bb);
                par[bb]=aa;
                vis[bb]=1;
            }
        }
    }
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(false);

    ll ks=0;


    while(in(n)==1)
    {

        rep(i,100001)v[i].clear();

        msi MP;
        map<ll,string>id;

        MP.clear();
        id.clear();
        mem(vis,false);
        c=1;

        rep(i,n)
        {
            cin>>s>>s1;
            if(MP.find(s)==MP.end())
            {
                id[c]=s;
                MP[s]=c++;
            }
            if(MP.find(s1)==MP.end())
            {
                id[c]=s1;
                MP[s1]=c++;
            }

            ll aa=MP[s],bb=MP[s1];
            v[aa].pb(bb);
            v[bb].pb(aa);
        }

        cin>>s>>s1;


        dfs(MP[s],MP[s1]);

        ll cc=MP[s],dd=MP[s1];

        if(ks>0)cout<<endl;
        ks++;


        if(cc==0 or dd==0 or vis[dd]==0)
        {
            cout<<"No route\n";
            continue;
        }

        vector<string>vv;

        vv.clear();

        while(1)
        {

            vv.pb(id[dd]);
            dd=par[dd];
            if(par[dd]==-1)
            {
                vv.pb(id[dd]);
                break;
            }
        }

        reverse(all(vv));
        rep(i,len(vv)-1)
        {
            cout<<vv[i]<<" "<<vv[i+1]<<endl;
        }


    }




   return 0;

}
