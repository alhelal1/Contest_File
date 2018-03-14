
struct info
{
    ll x,y,z;
}arr[654321];
string s,ss;
ll a,b,c,f=0,r=0,rr=0,res=0,n,m;
ll vis[6543210],ans[6543210];

vi v[123456];


ll dfs(ll st,ll end)
{
    queue<ll>q;

    q.push(st);

    ans[st]=0;


    vis[st]=1;



    while(!q.empty())
    {
        ll aa=q.front(); q.pop();

        rep(i,len(v[aa]))
        {
            ll bb=v[aa][i];
            if(bb<=0)continue;

            if(bb>=100000)continue;
            if(vis[bb]==0)
            {
                ans[bb]=ans[aa]+1;
                q.push(bb);
                vis[bb]=1;

            }
        }
    }
}

int main()
{
   // ios_base::sync_with_stdio(false);
   // cin.tie(false);
   ll ks=0;


   ll st,end;

   mem(vis,false);

   cin>>st>>end;

   for(int i=1;i<=10005;i++)
   {

        v[i].pb(i*2);
        v[i].pb(i-1);
   }
   if(st==end)
   {
       cout<<0;return 0;
   }
   dfs(st,end);

   cout<<ans[end];

   return 0;

}
