vi v[100004];
ll vis[100005],ans[100005];
ll dp[505][105];
void dfs(ll pos,ll par)
{
   dp[pos][0]=1;
   rep(i,len(v[pos]))
   {
       ll aa=v[pos][i];
       if(aa==par)continue;
       dfs(aa,pos);
       for(int j=0;j<m;j++)
       {
           r+=(1LL*dp[pos][j]*dp[aa][m-j-1]);
       }
       for(int j=1;j<=m;j++)
       {
           dp[pos][j]+=dp[aa][j-1];
       }
   }
   return ;
}
int main()
{
       cin>>n>>m;
        rep(i,n-1)
        {
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        dfs(1,-1);
        cout<<r;
}
