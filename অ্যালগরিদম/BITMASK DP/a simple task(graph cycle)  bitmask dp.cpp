using namespace std;
#include<bits/stdc++.h>
typedef long long  LL;
typedef   pair<LL,LL>  PII;
typedef   vector< PII > VPII;
typedef   vector<long long>   VI;
typedef   map<string,LL>  MSI;
typedef   map<LL,LL>  MII;
///Print
#define R(n)       scanf("%lld", &n)
#define P(a)  printf("%lld\n",a)
#define NL printf("\n")
///Case
#define CASE(no) printf("Case %lld: ",++no)
#define CASENL(no) printf("Case %lld:\n",++no)
///LOOP
#define FOR(x,n) for(__typeof(n) x=0;x<(n);x++)
#define rep(x,n) for(__typeof(n) x=0;x<(n);x++)
#define reps(i,x) for(int  i=0;i<(x.size());i++)
#define repp(x,n) for(__typeof(n) x=1;x<=(n);x++)
#define FORSTL(x,n) for(__typeof(n.begin()) x=n.begin();x!=n.end();x++)
///Shortcut
#define mem(ar,value) memset(ar,value,sizeof(ar))
#define all(x) x.begin(),x.end()
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define len(s) s.size()
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define MIN3(a,b,c) min(a,min(b,c))
#define MAX3(a,b,c) max(a,max(b,c))
#define EPS (1e-9)
#define PI acos(-1.0)
#define isEq(a,b) (fabs((a)-(b))<eps)
#define FAST ios_base::sync_with_stdio(false); cin.tie(false);
///DEBUG
#define D(x) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
#define DD(x,y) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<endl;
#define DDD(x,y,z) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
template<class T>T gcd(T a,T b){return b == 0 ? a : gcd(b, a % b);}
template<typename T>T lcm(T a, T b) {return a / gcd(a,b) * b;}
template<class T>T my_pow(T n,T p){if(p==0)return 1;T x=my_pow(n,p/2);x=(x*x);if(p&1)x=(x*n);return x;} ///n to the power p
template<class T>T big_mod(T n,T p,T m){if(p==0)return (T)1;T x=big_mod(n,p/2,m);x=(x*x)%m;if(p&1)x=(x*n)%m;return x;}
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}/// extract words or numbers from a line
string itos(LL n){string s;while(n){s+=(n%10+48);n/=10;}reverse(all(s));return s;}
LL stoi(string s){LL n=0;FOR(i,len(s))n=n*10+(s[i]-48);return n;}
//struct info{LL x,y;}arr[100005];bool com(info a,info b){return (a.x<b.x) or (a.x==b.x and a.y<b.y);}
LL  ar[18];//,vis[1000005];
//LL a=0,b=0,c=0,r=0,rr=0,res=0,n,m,t=0,ks=0;
//string  s,ss;


LL a,b,c,n,m,t;

LL dp[1<<19][19];

VI v[100005];


LL rec(LL mask,LL st,LL end)
{

    D(s);


    LL &ret=dp[mask][st];
    if(ret!=-1)  return ret;
    ret=0;

    rep(i,len(v[st]))
    {
        LL aa=v[st][i];
        LL bb=1LL<<aa   & mask;
        LL cc=1LL<<aa | mask;

        if(aa==end)
        {
            if(__builtin_popcount(mask)>2)
            {
                ret++;
            }
        }
            else
            {

                if(bb==0   and   aa>  end )
                {

                    s+=char(aa+'0');

                    ret+=rec(cc,aa,end);

                }

            }
        }



    return   ret;

}

int main()
{
    //FAST;


    cin>>n>>m;

    rep(i,m)
    {
        cin>>a>>b;
        a--,b--;

        v[a].PB(b);
        v[b].PB(a);
    }


    LL rr=0;


    mem(dp,-1);



    rep(i,n)
    {
        rr+=rec(1LL<<i,i,i);


        D(rr);
    }

    printf("%lld\n",rr/2);

}




