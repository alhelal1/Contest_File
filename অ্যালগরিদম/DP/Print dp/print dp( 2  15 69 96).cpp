using namespace std;
#include<bits/stdc++.h>
typedef long long  ll;


typedef vector<ll>  vi;

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

ll a=0,b=0,c=0,r=0,rr=0,res=0,n,m;
//string s,s1;

//vi v;

ll ar[105][909],ar1[105][905],ar2[100005];

vi v[100005];

ll tot;

ll Max(ll idx,ll sum)
{
    if(idx>=n)
    {
        if(sum==tot)return true;
        else
        return false;
    }

    ll &ret=ar[idx][sum];
    if(ret!=-1)return ret;

    //if(sum>tot)return false;

    ll st=(idx==0)?1:0;
     ret=0;

    for(int i=9;i>=st;i--)
    {
        if(sum+i<=tot)
        ret=ret| Max(idx+1,sum+i);
    }

    return ret;
}




ll Min(ll idx,ll sum)
{
    if(idx>=n)
    {
        if(sum==tot)return true;
        else
        return false;
    }
    //if(sum>tot)return false;

   ll &ret=ar1[idx][sum];

   if(ret!=-1)return ret;
    ll st=(idx==0)?1:0;
     ret=0;
    for(int i=st;i<=9;i++)
    {
        if(sum+i<=tot)
        ret=ret| Min(idx+1,sum+i);
    }
    return ret;
}



void printM(ll idx,ll sum)
{
    if(idx>=n)
    {
        return ;
    }

   // if(sum>tot)return false;

    ll st=(idx==0)?1:0;
    ll ret=0;

    for(int i=9;i>=st;i--)
    {
       // ret=ret| Max(idx+1,sum+i);

       if(Max(idx+1,sum+i)==1)
       {
           cout<<i;
           printM(idx+1,sum+i);
           break;
       }
    }

    //return ret;
}



void printS(ll idx,ll sum)
{
    if(idx>=n)
    {
        return ;
    }

   // if(sum>tot)return false;

    ll st=(idx==0)?1:0;
    ll ret=0;

    for(int i=st;i<=9;i++)
    {
       // ret=ret| Max(idx+1,sum+i);

       if(Min(idx+1,sum+i)==1)
       {
           cout<<i;
           printS(idx+1,sum+i);
           break;
       }
    }

    //return ret;
}




int main()
{

    ll t=0,ks=0;

    cin>>n>>tot;

    mem(ar,-1);
    mem(ar1,-1);

    if(n==1 and tot==0)
    {
        cout<<0<<" "<<0;
        return 0;
    }

    //cout<<Max(0,0);


    if(Min(0,0)  and Max(0,0))
    {
        printS(0,0);
        cout<<" ";

        printM(0,0);
    }

    else cout<<-1<<" "<<-1;

    //printM(0,0);

   return 0;

}
