
using namespace std;
    /** int t;
    scanf("%d",&t);
	for(int ks=1;ks<=t;ks++)
    {
        printf("Case %d: ",ks);
        scanf("%lld",&n);

    }**/
#include<bits/stdc++.h>
typedef long long  ll;
struct node
{

};

#define READ freopen("in.txt","r",stdin)
#define WRITE freopen("ot.txt","w",stdout)

#define rep(x,n) for(__typeof(n) x=0;x<(n);x++)
#define rr(x,n) for(__typeof(n) x=0;x<(n);x++)
#define reps(i,x) for(int  i=0;i<(x.size());i++)
#define rrs(i,x)  for(int i=0;i<x.size();i++)
#define repp(x,n) for(__typeof(n) x=1;x<=(n);x++)
#define FOR(x,m,n) for(__typeof(n) x=(m);x<=(n);x++)
#define foreach(x,n) for(__typeof(n.begin()) x=n.begin();x!=n.end();x++)

#define mp make_pair
#define pb push_back
#define len(s) s.size()
#define sqr(x) ((x)*(x))
#define xx first
#define yy second
#define all(x) x.begin(),x.end()
#define mem(ar,value) memset(ar,value,sizeof(ar))


#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define min4(a,b,c,d) min(min(a,b),min(c,d))
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define maxall(v) *max_element(all(v))
#define minall(v) *min_element(all(v))



#define n1 cout<<"\n"
#define sf(a) scanf("%lld",&a)
#define pf(a) printf("%lld\n",a)


#define inf (1e15)
#define eps (1e-9)
#define PI acos(-1.0)
#define pi 3.14159265358979323846
#define isEq(a,b) (fabs((a)-(b))<eps)
#define LEADZERO(n) (__builtin_clz(n))
#define TRAILZERO(n) (__builtin_ctz(n))
#define ONBIT(n) (__builtin_popcount(n))
#define Dist(x1,y1,x2,y2) (sqrt(sqr((x1)-(x2))+sqr((y1)-(y2))))
#define spDist(lat1,long1,lat2,long2,r) ((r)*acos(sin(lat1)*sin(lat2)+cos(lat1)*cos(lat2)*cos((long1)-(long2))))


/**Define Bitwise operation**/
#define check(n, pos) (n & (1<<(pos)))
#define biton(n, pos) (n | (1<<(pos)))
#define bitoff(n, pos) (n & ~(1<<(pos)))


///upper bound and lower bound
#define LB(a,value) (lower_bound(all(a),value)-a.begin())
#define UB(a,value) (upper_bound(all(a),value)-a.begin())

///DEBUG
#define dbg(x) cout<<#x<<": "<<x<<endl
#define dbgar(i,a) cout<<#a<<"["<<i<<"] = "<<a[i]<<" "<<endl

const int mod= 1000000007;

template<class T>T gcd(T a,T b){return b == 0 ? a : gcd(b, a % b);}
template<typename T>T lcm(T a, T b) {return a / gcd(a,b) * b;}

template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}/// extract words or numbers from a line
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}/// convert a number to string
template<class T> inline T Mod(T n,T m) {return (n%m+m)%m;} ///For Positive Negative No.

template<class T>T my_pow(T n,T p){if(p==0)return 1;T x=my_pow(n,p/2);x=(x*x);if(p&1)x=(x*n);return x;} ///n to the power p
template<class T>T big_mod(T n,T p,T m){if(p==0)return (T)1;T x=big_mod(n,p/2,m);x=(x*x)%m;if(p&1)x=(x*n)%m;return x;}

template<class T>T multiplication(T n,T p,T m){if(p==0)return (T)0;T x=multiplication(n,p/2,m);x=(x+x)%m;if(p&1)x=(x+n)%m;return x;}
bool isVowel(char ch){ ch=toupper(ch); if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true; return false;}


//map<string,ll>MPS;

//map<ll,ll>MP,MPP,MPPP,MPPPP;

//pair<ll,ll>P[100100];
//ll a,b,n,m,res=0,c=0,t=0,ans=0,cc=0,f=0,ff=0,cnt=0;
ll ar[1000006]={0};
//ll mn=inf,mx=-inf;
//ll ar1[1001000]={0};
//ll dp[1005][1005];
//vector<ll>vv;
//vector<ll>v;
//ll vis[200100];
//string s,ss;//,ch[100010];
ll i=0;
char s[1000005],ss[1000006];
void prefix(char *ss)
{
    ar[0]=0;
    int l=strlen(ss);
    for(int j=1;j<l;j++)
    {
        while(i>0 && ss[i]!=ss[j])i=ar[i-1];
        if(ss[i]==ss[j])i++;
        ar[j]=i;
    }
}
ll j=0;
ll kmp(char *s)
{
    j=0;
   int l=strlen(s);
    for(int i=0;i<l;i++)
    {
        while(j>0 && s[i]!=ss[j])
            j=ar[j-1];
        if(s[i]==ss[j])j++;
        if(j==l)
        {
            j=ar[j-1];
        }
    }
    return j;
}


int main()
{
    //ios_base::sync_with_stdio(false);
    int t;
    //cin>>t;
    int ks=1;
    scanf("%d",&t);
    while(t--)
    {

    printf("Case %d: ",ks++);
    scanf("%s",s);
    int l=strlen(s);
    int l1=l;
    for(int i=0;i<l;i++)
    {
        ss[i]=s[--l1];
    }
    if(strcmp(s,ss)==0)
    {
        printf("%d\n",l);
        continue;
    }
     prefix(ss);
     j =  kmp(s);
     printf("%lld\n",2LL*l-j);
    }
    return 0;
}
