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
#define case(no) printf("Case %lld: ",++no)
#define casenl(no) printf("Case %lld:\n",++no)
#define caseh(no) printf("Case #%lld: ",++no)
#define casehnl(no) printf("Case #%lld:\n",++no)
///Scanf
#define in(n)       scanf("%lld", &n)
#define iin(a,b)    scanf("%lld %lld", &a, &b)
#define iiin(a,b,c) scanf("%lld %lld %lld", &a, &b, &c)
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



struct info
{
    ll sum,lsum,rsum,ans;
}tree[200005];


ll ar[50005];
ll a=0,b=0,c=0,r=0,rr=0,res=0,n,m;
void insert(ll idx,ll  st,ll end)
{
    if(st==end)
    {
        tree[idx].sum=ar[st];
        tree[idx].lsum=ar[st];
        tree[idx].rsum=ar[st];
        tree[idx].ans=ar[st];
        return ;
    }
    ll mid=(st+end)>>1;
    ll L=idx*2,R=L+1;
    insert(L,st,mid);
    insert(R,mid+1,end);
    tree[idx].sum=tree[L].sum+tree[R].sum;

    tree[idx].lsum=max(tree[L].lsum,tree[L].sum+tree[R].lsum);
    tree[idx].rsum=max(tree[R].rsum,tree[R].sum+tree[L].rsum);
    tree[idx].ans=max(max(tree[L].ans,tree[R].ans),tree[L].rsum+tree[R].lsum);
    return ;
}

void update(ll idx,ll  st,ll end,ll pos,ll val)
{
    if(st==end)
    {
        tree[idx].sum=val;
        tree[idx].lsum=val;
        tree[idx].rsum=val;
        tree[idx].ans=val;
        return ;
    }
    ll mid=(st+end)>>1;
    ll L=idx*2,R=L+1;
    if(pos<=mid)      update(L,st,mid,pos,val);
    else              update(R,mid+1,end,pos,val);

    tree[idx].sum=tree[L].sum+tree[R].sum;

    tree[idx].lsum=max(tree[L].lsum,tree[L].sum+tree[R].lsum);
    tree[idx].rsum=max(tree[R].rsum,tree[R].sum+tree[L].rsum);

     tree[idx].ans=max(max(tree[L].ans,tree[R].ans),tree[L].rsum+tree[R].lsum);

    return ;
}

info Q(ll idx,ll  st,ll end,ll i,ll j)
{
    if(st==i and end==j)
    {
        return tree[idx];
    }

    ll mid=(st+end)>>1;
    ll L=idx*2,R=L+1;

    if(j<=mid)      return Q(L,st,mid,i,j);

    else if(i>mid)  return Q(R,mid+1,end,i,j);

    else
    {
        info aa,bb,cc;
        aa=Q(L,st,mid,i,mid);
        bb=Q(R,mid+1,end,mid+1,j);
        cc.sum=(aa.sum)+(bb.sum);
        cc.lsum=max(aa.lsum,aa.sum+bb.lsum);
        cc.rsum=max(bb.rsum,bb.sum+aa.rsum);
         cc.ans=max(max(aa.ans,bb.ans),aa.rsum+bb.lsum);
        return cc;
    }

}



int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(false);

    ll t,ks=0;
    in(n);
    rep(i,n)
    {
        in(ar[i+1]);
    }
    insert(1,1,n);
    ll q;
    ll a,b,c;
    in(q);
    while(q--)
    {
        iiin(a,b,c);
        if(a==1)
        {
            info dd=Q(1,1,n,b,c);
            printf("%lld\n",dd.ans);
        }
        else
        {
            update(1,1,n,b,c);
        }
    }


   return 0;

}
