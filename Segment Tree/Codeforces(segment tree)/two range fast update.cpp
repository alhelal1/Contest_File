/**Bismillahir Rahmanir Rahim
   In the name of ALLAH, most gracious, most merciful */
#include <bits/stdc++.h>
using namespace std;
#define inf           100000000000000000LL
#define pb            push_back
#define mp            make_pair
#define eps           1e-9
#define nl            printf("\n")
#define spc           printf(" ")
#define sci(n)        scanf("%ld",&n)
#define sc64(n)       scanf("%I64d",&n)
#define scii(a,b)     scanf("%ld %ld",&a,&b)
#define sc6464(a,b)   scanf("%I64d %I64d",&a,&b)
#define scs(s)        scanf("%s",s)
#define scss(a,b)     scanf("%s %s",a,b)
#define scd(f)        scanf("%lf",&f)
#define scdd(a,b)     scanf("%lf %lf",&a,&b)
#define prc(k)        printf("Case %ld: ",k);
#define pri(a)        printf("%ld",a)
#define pr64(a)       printf("%I64d",a)
#define prii(a,b)     printf("%ld %ld",a,b)
#define pr6464(a,b)   printf("%I64d %I64d",a,b)
#define prs(a)        printf("%s",a)
#define prss(a,b)     printf("%s %s",a,b)
#define prd(a)        printf("%lf",a)
#define prdd(a,b)     printf("%lf %lf",a,b)
#define rep(i,n)      for(int i(0),_n(n);i<_n;++i)
#define repr(i,n)     for(int i=n;i>=0;i--)
#define repi(i,a,b)   for(int i(a),_b(b);i<=_b;++i)
#define repl(i,n)     for(int i(1),_n(n);i<=_n;++i)
#define repir(i,a,b)  for(int i=a;i>=b;i--)
#define chk(a,k) ((bool)(a&(1<<(k))))
#define off(a,k) (a&(~(1<<(k))))
#define on(a,k) (a|(1<<(k)))
int Set(int N,int pos) {return N |= (1LL<<pos);}
int Reset(int N,int pos) {return N&= ~(1LL<<pos);}
bool Check(int N,int pos) {return N&(1LL<<pos);}
#define ff            first
#define ss            second
#define all(a)        a.begin(),a.end()
#define mem(x,a)      memset(x,a,sizeof(x))
#define repe(it,c)    for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
int dx[]={0,0,1,-1,1,-1,1,-1},dy[]={1,-1,0,0,1,-1,-1,1};
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<long long> vll;
typedef vector<string> vs;
#define ll long long
typedef vector<vector<int> > vvi;
inline void cn( long &n )//fast input function
{
n=0;
long ch=getchar();int sign=1;
while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
while(ch >= '0' && ch <= '9')
n = (n<<3)+(n<<1) + ch-'0', ch=getchar();
n=n*sign;
}
template<class T> void cmin(T &a,T b){if(b<a) a=b;}
template<class T> void cmax(T &a,T b){if(b>a) a=b;}
template<class T> int len(const T&c){return (int)c.size();}
template<class T> int len(char c[]){return (int)strlen(c);}
string itos(long n){string s;while(n){s+=(n%10+48);n/=10;}reverse(all(s));return s;}
long stoi(string s){long n=0;rep(i,len(s))n=n*10+(s[i]-48);return n;}
#define lim 100005
int tree[3*lim],lajy[3*lim],ar[lim];


void update(int l,int r,int i,int j,int node,int val)
{
    if(lajy[node]!=-1)
    {
        tree[node]=(r-l+1)*lajy[node];
        if(l!=r)
        {
            lajy[2*node]=lajy[node];
            lajy[2*node+1]=lajy[node];
        }
        lajy[node]=-1;
    }
    if(r<i||l>j) return ;
    if(l>=i&&r<=j)
    {
        tree[node]=(r-l+1)*val;
        if(l!=r)
        {
            lajy[2*node]=val;
            lajy[2*node+1]=val;
        }
        lajy[node]=val;
        return;
    }
    update(l,(l+r)/2,i,j,2*node,val);
    update((l+r)/2+1,r,i,j,2*node+1,val);

    tree[node]=tree[2*node]+tree[2*node+1];
}
long query(int l,int r,int i,int j,int node)
{
    if(lajy[node]!=-1)
    {
        tree[node]=(r-l+1)*lajy[node];
        if(l!=r)
        {
            lajy[2*node]=lajy[node];
            lajy[2*node+1]=lajy[node];
        }
        //lajy[node]=0;
    }
    if(r<i||l>j) return 0;
    if(l>=i&&r<=j)
        return tree[node];
    return query(l,(l+r)/2,i,j,2*node)+query((l+r)/2+1,r,i,j,2*node+1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    long t,k;
    scanf("%ld",&t);
    for(long k=1;k<=t;k++){
    long N=1,n,m,f,l,r,val,x,y,gc;
    scanf("%ld %ld",&n,&m);
    while(N<n)
    {
        N=N*2;
    }
    mem(lajy,-1); mem(tree,0);
    printf("Case %ld:\n",k);
    rep(i,m)
    {
        scanf("%ld",&f);
        if(f==2)
        {
            scanf("%ld %ld",&l,&r);
            l++;r++;
            x=query(1,N,l,r,1);
            y=r-l+1;
            gc=__gcd(x,y);
            x/=gc; y/=gc;
            if(y==1) printf("%ld\n",x);
            else printf("%ld/%ld\n",x,y);
        }
        else
        {
            scanf("%ld %ld %ld",&l,&r,&val);
            l++;r++;
            update(1,N,l,r,1,val);

        }
    }
    }
    return 0;
}
