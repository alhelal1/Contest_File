

ll ar[100005],n=9,m,a,b,aa,bb;

ll tot,dp[10][1000006];

ll go(ll i,ll sum)
{
    if(i>=n)return 0;

    ll &ret=dp[i][sum];
    if(ret!=-1)  return  ret;


    ret=0;

    if(ar[i]+sum<=tot)
    {
        ret=max(ret,1+go(i,sum+ar[i]));
    }
    ret=max(ret,go(i+1,sum));

    return ret;
}
ll ff=1;
void print(ll j,ll sum )
{
    if(sum>tot)return;
    ll r1=0,r2=0,pos=-1;
    for(int i=0;i<=8;i++)
    {
        r1=1+go(0,sum+ar[i]);

        if(r1>=r2)
        {
            r2=r1;
            pos=i;
        }
    }

    if(pos==-1)return ;
    cout<<pos+1;

    print(j,sum+ar[pos]);
}




int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(false);


    cin>>tot;

    rep(i,n)
    {
        cin>>ar[i];
    }

    mem(dp,-1);

    if(go(0,0)==0)
    {
        cout<<-1;

        return 0;
    }
    else
    {
        print(0,0);
    }





   return 0;

}
