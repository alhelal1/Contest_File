ll pos=0;
ll dfs(ll ii,ll jj)
{
    if(ii<0 or jj<0)return 0;
    if(ii>=n or jj>=m)return 0;
    if(vis[ii][jj]>0  or s[ii][jj]!='.')return 0;

    ar[pos]++;
    vis[ii][jj]=pos;
    rep(i,4)
    {
        ll x=row[i]+ii,y=col[i]+jj;
        dfs(x,y);
    }
}


ll go(ll ii,ll jj)
{
   vi v;

   //v.clear();


   //set<ll>v;
    rep(i,4)
    {
         ll x=row[i]+ii,y=col[i]+jj;
         if(x<0 or y<0)continue;
         if(x>=n or y>=m)continue;
         v.pb(vis[x][y]);
    }
    ll r=0;

    sort(all(v));

    v.resize(unique(all(v))-v.begin());

    rep(i,len(v))r+=ar[v[i]];


    //rep(i,len(v))r+=ar[v[i]];
    r++;
    return r%10;
}


int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(false);

    cin>>n>>m;

    rep(i,n)cin>>s[i];

    rep(i,n)
    {
        rep(j,m)
        {
            if(s[i][j]=='.'  and vis[i][j]==0)
            {
                pos++,dfs(i,j);
            }

        }
    }

    rep(i,n)
    {
        rep(j,m)
        {
            if(s[i][j]=='*')
            {
                cout<<go(i,j);
            }
            else cout<<s[i][j];
        }
        cout<<endl;
    }
   return 0;

}
