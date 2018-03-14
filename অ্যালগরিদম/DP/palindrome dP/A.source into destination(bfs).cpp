

ll ar[2000005],vis[2000005];
ll a=0,b=0,c=0,r=0,rr=0,res=0,n,m;
string s,s1;
vi v[100005];

ll bfs(ll st,ll end)
{
    queue<ll>q;
    q.push(st);
    q.push(0);
    vis[st]=1;
    ll dis=0;
    while(q.size())
    {
        ll aa=q.front();q.pop();
        dis=q.front();q.pop();
        if(aa==end)
        {
            r=dis;
            break;
        }
        rep(i,len(v[aa]))
        {
            ll bb=v[aa][i];
            if(vis[bb]==0)
            {
                q.push(bb);
                q.push(dis+1);
                vis[bb]=1;
            }
        }
    }

    return r;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(false);


    ll t=0,ks=0;
    in(t);
    while(t--)
    {
        rep(i,100001)v[i].clear();

        in(n);
        rep(i,n)
        {
        in2(a,b);
        v[a].pb(b);
        v[b].pb(a);
        }


        //ll S,D;
        //in2(S,D);

        //case(ks);
        //out(r);

    }







   return 0;

}
