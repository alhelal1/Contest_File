#include<bits/stdc++.h>
#define ll long long
#define pb push_back

#define N 200005
#define A 1000005
#define BLOCK 512 // ~sqrt(N)

using namespace std;

int i,j,k,l,m,n,p,r,t,cs,currentL,currentR;
int a[N],cnt[A];
ll ans[N],res;

struct node
{
    int L,R,idx;
}q[N];

inline bool cmp(node x, node y)
{
    if(x.L/BLOCK == y.L/BLOCK)
    return x.R < y.R;

    return x.L/BLOCK < y.L/BLOCK;
}

inline void add(int position,int sign)
{
    //res+=((2LL * cnt[a[position]] * sign + 1) * a[position]);

    int aa=a[position];
    res-=(cnt[aa]*cnt[aa]*aa);
    cnt[a[position]]+=sign;
   res+=(cnt[aa]*cnt[aa]*aa);
}

int main()
{
    scanf("%d%d",&n,&m);

    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    for(i=0;i<m;i++)
    {
        scanf("%d%d",&q[i].L,&q[i].R);
        q[i].L--;
        q[i].idx=i;
    }

    sort(q,q+m,cmp);

    currentL=currentR=0;

    for(i=0;i<m;i++)
    {
        int L=q[i].L;
        int R=q[i].R;

        while(currentL < L) add(currentL++ , -1);
        while(currentL > L) add(--currentL , 1);
        while(currentR > R) add(--currentR , -1);
        while(currentR < R) add(currentR++ , 1);

        ans[q[i].idx]=res;
    }

    for(i=0;i<m;i++)
    printf("%I64d\n",ans[i]);
}
