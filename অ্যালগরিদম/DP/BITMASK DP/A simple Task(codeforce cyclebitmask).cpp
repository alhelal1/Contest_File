vi v[1000005];


ll dp[1<<18][20],n,m,a,b;



ll rec(ll mask,ll end,ll st)
{
    ll &ret=dp[mask][end];if(ret!=-1)return ret;
    ret=0;
    rep(i,len(v[end]))
    {

        ll aa=v[end][i];
        if(aa==st)
        {
            if(__builtin_popcount(mask)!=2)
            {
                ret++;
            }
        }
        else if(!(mask&(1LL<<aa))  and aa>st)
        {
            ret+=rec(mask|(1LL<<aa),aa,st);
        }

    }

    return ret;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(false);

    cin>>n>>m;
    rep(i,m)
    {
        cin>>a>>b;
        a--,b--;
        v[a].pb(b);
        v[b].pb(a);
    }

    mem(dp,-1);

    ll ans=0;
    rep(i,n)
    {

        ans+=rec(1<<i,i,i);

    }
    cout<<(ans>>1)<<"\n";

   return 0;

}
