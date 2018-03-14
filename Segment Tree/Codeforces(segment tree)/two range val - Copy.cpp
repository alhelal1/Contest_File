/**Bismillahir Rahmanir Rahim**/
#include <bits/stc++.h>

#define sci(n)        scanf("%ld",&n)
#define mem(x,a)      memset(x,a,sizeof(x))
using namespace std;
inline void cn( long &n )//fast input function
{
        n=0;
        long ch=getchar();int sign=1;
        while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
        while(ch >= '0' && ch <= '9')
                n = (n<<3)+(n<<1) + ch-'0', ch=getchar();
        n=n*sign;
}
struct st{
 long long sum,prop;
}tree[MX*3];
void update(int l,int r,int i,int j,long node,long value)
{
    if(r<i||l>j) return ;
    if(l>=i&&r<=j)
    {
        tree[node].sum+=value*(r-l+1);
        tree[node].prop+=value;
        return;
    }
    int mid=(l+r)>>1;
    int left=node<<1;
    int right=left+1;
    update(l,mid,i,j,left,value);
    update(mid+1,r,i,j,right,value);
    tree[node].sum=tree[left].sum+tree[right].sum+(r-l+1)*tree[node].prop;
}
long long query(int l,int r,int i,int j,long node,long carry)
{
    if(r<i||l>j) return 0;
    if(l>=i&&r<=j)
    {
        return tree[node].sum+carry*(r-l+1);
    }
    int mid=(l+r)>>1;
    int left=node<<1;
    int right=left+1;
    long long s1=query(l,mid,i,j,left,carry+tree[node].prop);
    long long s2=query(mid+1,r,i,j,right,carry+tree[node].prop);
    return s1+s2;
}
int main()
{
     long T,K;
     cn(T);
     for(K=1;K<=T;K++)
     {
         printf("Case %ld:\n",K);
         long f,l,r,v,n,q;
         cn(n);
         cn(q);
         mem(tree,0);
         for(int i=0;i<q;i++)
         {
         cn(f);
         if(f)
         {
             cn(l);cn(r);
             l++;r++;
             printf("%lld\n",query(1,n,l,r,1,0));
         }
         else
         {
            cn(l);cn(r);cn(v);
            l++;r++;
            update(1,n,l,r,1,v);
         }
         }
     }
    return 0;
}
