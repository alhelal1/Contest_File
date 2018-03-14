using namespace std;
#include<bits/stdc++.h>
typedef long long   LL;
typedef long long   ll;
typedef   pair<LL,LL>  PII;
typedef   vector< PII > VPII;
typedef   vector<long long>   VI;
typedef   map<string,LL>  MSI;
typedef   map<LL,LL>  MII;
///Print
#define R(n)       scanf("%lld", &n)
#define P(a)  printf("%lld\n",a)
#define NL printf("\n")
#define case(no) printf("Case %lld: ",++no)
#define casenl(no) printf("Case %lld:\n",++no)
///LOOP
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
///Min AND Max
#define MIN3(a,b,c) min(a,min(b,c))
#define MAX3(a,b,c) max(a,max(b,c))
#define EPS (1e-9)
#define PI acos(-1.0)
#define isEq(a,b) (fabs((a)-(b))<eps)
#define Fast ios_base::sync_with_stdio(false); cin.tie(false);
///DEBUG
#define D(x) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
#define DD(x,y) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<endl;
#define DDD(x,y,z) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" ="<<z<<endl;
///Gcd and Lcm
template<class T>T gcd(T a,T b){return b == 0 ? a : gcd(b, a % b);}
template<typename T>T lcm(T a, T b) {return a / gcd(a,b) * b;}
///Bigmod && Pow
template<class T>T my_pow(T n,T p){if(p==0)return 1;T x=my_pow(n,p/2);x=(x*x);if(p&1)x=(x*n);return x;} ///n to the power p
template<class T>T big_mod(T n,T p,T m){if(p==0)return (T)1;T x=big_mod(n,p/2,m);x=(x*x)%m;if(p&1)x=(x*n)%m;return x;}
///string to int
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}///
string itos(LL n){string s;while(n){s+=(n%10+48);n/=10;}reverse(all(s));return s;}
LL stoi(string s){LL n=0;rep(i,len(s))n=n*10+(s[i]-48);return n;}
//struct info{LL x,y;}arr[100005];bool com(info a,info b){return (a.x<b.x) or (a.x==b.x anda.y<b.y);}
LL ar[5000001],br[5000001];
LL a=0,b=0,c=0,r=0,rr=0,res=0,n,m,t=0,ks=0,w,k;
string  s;



void prime()
{


    ar[0]=1;
    ar[1]=1;


    ar[2]=0;
    for(int i=4;i<=1000000;i+=2)
    {
        ar[i]=1;
    }

    for(int i=3;i<=1000;i+=2)
    {
        for(int j=i*i;j<=1000000;j+=(2*i))  ar[j]=1;
    }

    br[0]=0;
    br[1]=0;
    br[2]=1;
    for(int i=3;i<=1000000;i++)
    {
        if(ar[i]==0)    br[i]=br[i-1]+1;
        else   br[i]=br[i-1];
    }
}

LL go(LL mid)
{


     LL f=0;
    for(int i=a;i<=b-mid+1;i++)
    {
        LL aa=lower_bound(br,br+1000001,br[i-1]+k)-br;
        if((aa-i)>=mid)
        {
            f=1;
            break;
        }
        if(aa>b)
        {
            f=1;
            break;
        }
    }

    if(f)  return false;
    else
    return true;
}
int main()
{
    //Fast;

    prime();


    cin>>a>>b>>k;
    LL ans=1e7;

    LL lo=1,hi=1e9;




    LL aa=lower_bound(br,br+1000001,br[a-1]+k)-br;

    if(aa>b)
    {
        cout<<-1;

        return 0;
    }

    while(lo<=hi)
    {
        LL mid=(lo+hi)>>1;
        LL dd=go(mid);


        if(mid>(b-a+1))  hi=mid-1;

       else if(dd)
        {
            ans=min(ans,mid);
            hi=mid-1;
        }
        else  lo=mid+1;
    }

    if(ans==1e7)cout<<-1;
    else

    cout<<ans;



   return 0;

}
