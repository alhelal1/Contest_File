
ll ar[100006]={0};

ll i=0;
char s[100005],ss[100006];
void prefix(char *ss)
{
    ar[0]=0;
    int l=strlen(ss);
    ll i=0;
    for(int j=1;j<l;j++)
    {
        while(i>0 && ss[i]!=ss[j])i=ar[i-1];
        if(ss[i]==ss[j])i++;
        ar[j]=i;
    }
}
ll j=0;
ll kmp(char *s)
{
    j=0;
   int l=strlen(s);
    for(int i=0;i<l;i++)
    {
        while(j>0 && s[i]!=ss[j])
            j=ar[j-1];
        if(s[i]==ss[j])j++;
        if(j==l)
        {
            j=ar[j-1];
        }
    }
    return j;
}


int main()
{
    //ios_base::sync_with_stdio(false);
    int t;
    int ks=1;
    while(scanf("%s",s)!=EOF)
    {
    int l=strlen(s);
    int l1=l;
    int f=0;
    int c=0;
    for(int i=0;i<l;i++)
    {
        ss[i]=s[--l1];
    }
    for(int i=0;i<l;i++)
    {
        if(s[i]==ss[i])
        {
            c++;
        }
    }
    if(c==l)
    {
        printf("%s\n",ss);
        f=1;
    }
    if(f==0)
    {
     prefix(ss);
     j =  kmp(s);
       printf("%s",s);
       for(int i=l-j-1;i>=0;i--)
       {
           printf("%c",s[i]);
       }
       printf("\n");
    }
    }
    return 0;
}
