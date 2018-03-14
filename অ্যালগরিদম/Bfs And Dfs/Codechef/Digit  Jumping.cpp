
ll ar[2000005],dp[10000005];
ll a=0,b=0,c=0,r=0,rr=0,res=0,n,m;
string s,s1;
vi v[1000001];
ll vis[100005];

 ///https://www.codechef.com/problems/DIGJUMP
 ll go(ll pos)
 {
     queue<ll>q;
     q.push(0);
     vis[0]=1;
     dp[0]=0;

     while(len(q))
     {
         ll aa=q.front();q.pop();


         if(aa==s.size()-1)break;

         ll val=s[aa]-'0';

        // if(vis[aa]==1)continue;
         //vis[aa]=1;

         rep(i,len(v[val]))
         {
             ll bb=v[val][i];
             if(vis[bb]==0)
             {
                 vis[bb]=1;
                 dp[bb]=dp[aa]+1;
                 q.push(bb);
             }
         }


         v[val].clear();
         if(aa>0 and vis[aa-1]==0)
         {
             vis[aa-1]=1;
             dp[aa-1]=dp[aa]+1;
             q.push(aa-1);
         }


          if(aa+1<s.size() and vis[aa+1]==0)
         {
             vis[aa+1]=1;
             dp[aa+1]=dp[aa]+1;
             q.push(aa+1);
         }

     }

     return dp[s.size()-1];
 }

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(false);

    cin>>s;
    reps(i,s)
    {
        ll aa=s[i]-'0';
        v[aa].pb(i);
        dp[i]=0;
    }


    cout<<go(0)<<endl;

   return 0;

}
