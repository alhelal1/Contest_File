LL ar[N],br[N];LL a=0,b=0,c=0,r=0,rr=0,res=0,n,m,t=0,ks=0;
string  s;




struct trie{
  LL nxt[3],has;
  trie()
  {
      mem(nxt,-1);
       has=0;
  }
}arr[2000005];


void insert(LL id,LL idx)
{

    //D(idx);
    if(id>=len(s))
    {
        arr[idx].has=1;
        return ;
    }
    LL x=s[id]-'a';
    if(arr[idx].nxt[x]==-1)
    {
        c++;
        arr[c]=trie();
        arr[idx].nxt[x]=c;
    }
    insert(id+1,arr[idx].nxt[x]);
}
LL read(LL id,LL idx,LL f)
{
    if(f>1)  return 0LL;
     if(id>=len(s))
    {
       if( arr[idx].has==1  &&  f==1)  return 1LL;
        return 0LL;
    }
    LL ret=0;
    LL x=s[id]-'a';
       rep(i,3)
       {
           if( arr[idx].nxt[i]!=-1)
           {
               ret|=read(id+1,arr[idx].nxt[i],f+(i!=x));
           }
       }
       return ret;
}
int main()
{
  // fastinput;
  cin>>n>>m;
  arr[0]=trie();
  rep(i,n)
  {
      cin>>s;

      insert(0,0);
  }
  rep(i,m)
  {
      cin>>s;
      if(read(0,0,0)==1)
      {
          puts("YES");
      }
      else puts("NO");
  }





   return 0;

}
