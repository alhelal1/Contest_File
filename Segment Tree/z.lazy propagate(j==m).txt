#include <bits/stdc++.h>
using namespace std;

#define pi 2*acos(0.0)
#define all(v) v.begin(),v.end()
#define coff ios_base::sync_with_stdio(0);

#define ff first
#define se second
#define pb push_back
#define sz(a) ((int)a.size())
#define ST(v) sort(all(v))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define cover(a,d) memset(a,d,sizeof(a))
#define popcount(i) __builtin_popcount(i)      //count one. in long long use __builtin_popcountll(i)
#define parity(i)   __builtin_parity(i)       //evenparity 0 and odd parity 1
#define btz(a)   __builtin_ctz(a)            //count binary trailling zero
#define un(v) ST(v), (v).erase(unique(all(v)),v.end())
#define common(a,b) ST(a), ST(b), a.erase(set_intersection(all(a),all(b),a.begin()),a.end())
#define uncommon(a,b) ST(a), ST(b), a.erase(set_symmetric_difference(all(a),all(b),a.begin()),a.end())

typedef  long long ll;
typedef  unsigned long long ull;

template <typename T>string toString( T Number ){stringstream st;st << Number;return st.str();}
int stringconvert(string s){int p; istringstream st(s); st>>p ; return p;}

//upper bound and lower bound
#define LB(a,value) (lower_bound(all(a),value)-a.begin())
#define UB(a,value) (upper_bound(all(a),value)-a.begin())

//Debug
#define dbg(x) cout<<#x<<'='<<x<<endl;
#define dbgarr(i,a) cout<<#a<<"["<<i<<"] = "<<a[i]<<" "<<endl;
#define nl puts("")

//File input/output
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

ll bigmod(ll a,ll b, ll m) { ll res = 1; while(b) { if(b & 1) { res = ( (res % m) * (a % m) ) %m ; } a= ((a%m) * (a%m)) %m; b >>= 1; } return res; }
ll modInverse(ll a, ll m){return bigmod(a,m-2,m);}

////============ CONSTANT ===============////
#define inf   1<<30                                           //infinity value
#define eps   1e-9
#define mx    100009
#define mod   1000000007
////=====================================////

struct info
{
    ll lazy,sum;
}tree[4*mx];



void update(int node, int s, int e, int i, int j, int val)
{

   if(s==i && e==j)
   {
     tree[node].lazy += val;
     tree[node].sum += (en-st+1)*val;
       return;
   }
   tree[node].sum+=(en-st+1)*val;
   int left=node<<1;
   int mid=(s+e)>>1;

   if(j<=mid)
   {
        update(left,s,mid,i,j,val);
   }
   else if(mid<i)
   {
       update(left+1,mid+1,e,i,j,val);
   }
   else
   {
       update(left, s, mid, i, mid, val);
       update(left+1, mid+1, e, mid+1, j, val);
   }
   //marge(node,s,e);
}

ll query(int node, int s, int e, int i, int j)
{
    if(s==i && e==j)
    {
        return tree[node].sum;
    }

    ll val = (j-i+1)*tree[node].lazy;
    int left=node<<1;
    int mid=(s+e)>>1;

    int res=0;
    if(j<=mid)
    {
        return val+query(left, s, mid, i, j);
    }
    else if(i>mid)
    {
        return val+query(left+1, mid+1, e, i, j);
    }
    else
    {
        return val+(query(left, s, mid, i, mid)+ query(left+1, mid+1, e, mid+1, j));
    }
}

int main()
{
    int t,no=0;
    scanf("%d",&t);

    while(t--)
    {
        int n,q;
        cin>>n>>q;

        cover(tree,0);

        printf("Case %d:\n",++no);
        while(q--)
        {
            int type,l,r,val;
            scanf("%d",&type);
            if(type==0)
            {
                scanf("%d %d %d",&l,&r,&val);
                update(1,1,n,l+1,r+1,val);
            }
            else
            {
                scanf("%d %d",&l,&r);
                ll res= query(1,1,n,l+1,r+1);
                printf("%lld\n",res);
            }
        }
    }
    return 0;
}
