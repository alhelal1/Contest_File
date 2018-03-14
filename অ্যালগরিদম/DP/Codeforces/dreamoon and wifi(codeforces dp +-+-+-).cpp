ll ar[204][204],ar1[2000005];
ll a=0,b=0,c=0,r=0,rr=0,res=0,n,m;
string s,s1;
ll dp[505][505];
ll go(ll i,ll pos)
{
    if(i>=len(s1))
    {
        if(c==pos)return 1;
        return 0;
    }

    ll &ret=dp[i][pos];
    if(ret!=-1)return ret;

    ret=0;
    if(s1[i]=='+')
    {
        ret+=go(i+1,pos+1);
    }
    else if(s1[i]=='-')  ret+=go(i+1,pos-1);
    else
    {
        ret+=go(i+1,pos+1);
        ret+=go(i+1,pos-1);
    }
    return ret;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(false);



   return 0;



}
