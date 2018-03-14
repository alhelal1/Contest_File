
ll ar[2000005],ar1[2000005];
ll a=0,b=0,c=0,r=0,rr=0,res=0,n,m;
string s,s1;
ll vis[10000007];
ll bfs(ll n)
{
    queue<ll>q;
    q.push(n);
    q.push(0);
    c++;
    vis[n]=c;


    while(len(q)>0)
    {
        ll aa=q.front();q.pop();
        ll bb=q.front();q.pop();
        ar[aa]+=bb;
        ar1[aa]++;
        ll cc=aa/2;
        if(cc>0 and vis[cc]!=c)
        {
            q.push(cc);
            q.push(bb+1);

            vis[cc]=c;
        }

        cc=aa*2;
        if(cc<2000002 and vis[cc]!=c)
        {
            q.push(cc);
            q.push(bb+1);
            vis[cc]=c;
        }
    }
}
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(false);
    cin>>n;
    rep(i,n)
    {
        cin>>a;
        bfs(a);
    }
    r=1000000000000LL;
    rep(i,1000001)
    {
        if(ar1[i]==n)
        {
            r=min(r,ar[i]);
        }
    }
    cout<<r;




   return 0;

}
