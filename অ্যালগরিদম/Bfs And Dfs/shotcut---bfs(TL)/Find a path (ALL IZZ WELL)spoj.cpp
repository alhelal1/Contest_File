
ll ar[2000005],ar1[2000005];
ll a=0,b=0,c=0,r=0,rr=0,res=0,n,m;
string s[1004],s1="ALLIZZWELL";


ll vis[101][101];

ll dfs(ll i,ll j,ll c)
{

    if(c>=9)return 1;

   ll ret=0;
    rep(k,8)
    {
        ll x=row[k]+i;
        ll y=col[k]+j;
        if(x>=0 and y>=0 and x<n and y<m)
        {
            if( s[x][y]==s1[c+1]  and vis[x][y]==0)
            {

                vis[x][y]=1;
                ret|=dfs(x,y,c+1);
                vis[x][y]=0;
            }
        }

        if(ret)break;
    }

    return ret;
}
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(false);


    ll ks=0,t=0;

    in(t);
    while(t--)
    {

        mem(vis,0);
        in(n);in(m);
        rep(i,n)cin>>s[i];
        r=0;
        rep(i,n)
        {
            rep(j,m)
            {
                if(s[i][j]=='A')
                {
                    r=dfs(i,j,0);

                    if(r)i=n,j=m;
                }
            }
        }

        mem(vis,0);
        if(r)printf("YES\n");
        else printf("NO\n");

        r=0;
    }




   return 0;

}
