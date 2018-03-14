
ll a,b,n,m,res=0,c=0,t=0,ans=0,cc=0,f=0,ff=0,cnt=0;
ll ar[100005]={0};
ll mn=inf,mx=-inf;

char s1[100005],ss1[100006];

string s,ss1;
/*
void failure(int next[])
{
    int p=0,ln=strlen(s);
    next[0]=0;

    for(int i=1; i<ln; i++)
    {
        while(p>0 && s[i]!=s[p]) p=next[p-1];

        if(s[p]==s[i]) p++;

        next[i]=p;
    }
}*/
int l1,l2;
void prefix()
{
    ar[0]=0;
    ll i=0;
    for(int j=1;j<l1;j++)
    {
        while(i>0 && s[i]!=s[j])
        {
            i=ar[i-1];
        }
        if(s[i]==s[j])
        {
            i++;
        }
        ar[j]=i;
        //cout<<ar[j]<<" ";
        //dbg(ar,j);
    }
  //  rr(i,len(ss))cout<<ar[i]<<" ";
}
ll kmp()
{
    ll j=0;
   // prefix(ss);
   int ret=0;
    for(int i=0;i<l2;i++)
    {
        while(j>0 && ss[j]!=s[j])
        {
            j=ar[j-1];
        }
        if(s[i]==ss[j])
        {
            j++;

        }
        if(l1==j)
        {
            //v.pb(i-j+1);
            j=ar[j-1];
            ret++;
            //break;
        }
        //if(ret)break;
    }
    return ret;
}

int main()
{
   // ios_base::sync_with_stdio(false);
    //cin>>t;
    c=0;
    scanf("%lld",&t);
     gets(s1);
    while(t--)
    {
       //cin>>s;
       //cin>>n;
           gets(s1);
           gets(ss1);

           for(int i=0;i<strlen(s1);i++)
           {
               if(s1[i]!=' ')
               {
                   s+=s1[i];
               }
           }


            for(int i=0;i<strlen(ss1);i++)
           {
               if(ss1[i]!=' ')
               {
                   ss+=s1[i];
               }
           }

           l1=len(ss);
           l2=len(s);
          // mem(ar,false);
           prefix();
           ll aa=kmp();
           cout<<aa<<endl;



    }
    return 0;
}
