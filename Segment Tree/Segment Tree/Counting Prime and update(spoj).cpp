#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define lson rt<<1,L,mid
#define rson rt<<1|1,mid+1,R
/*

      0 x y v：
      1 x y ：

*/
using namespace std;
const int maxn=1000005;
int t,n,q;
bool isprime[maxn];

struct Node{
    int sum;
    int lazy;
    int len;
}tree[maxn<<2];

void init(){
    memset(isprime,true,sizeof(isprime));
    for(int i=2;i<maxn;i++){
        if(isprime[i]){
            for(int j=i*2;j<maxn;j+=i){
                isprime[j]=false;
            }
        }
    }
}
void pushUp(int rt){
    tree[rt].sum=tree[rt<<1].sum+tree[rt<<1|1].sum;
}
void pushDown(int rt){
    if(tree[rt].lazy!=-1){
        tree[rt<<1].lazy=tree[rt<<1|1].lazy=tree[rt].lazy;
        tree[rt<<1].sum=tree[rt].lazy?tree[rt<<1].len:0;
        tree[rt<<1|1].sum=tree[rt].lazy?tree[rt<<1|1].len:0;
        tree[rt].lazy=-1;
    }
}
void build(int rt,int L,int R){
    tree[rt].lazy=-1;
    tree[rt].len=R-L+1;
    if(L==R){
        int v;
        scanf("%d",&v);
        if(isprime[v])
            tree[rt].sum=1;
        else
            tree[rt].sum=0;
        return;
    }
    int mid=(L+R)>>1;
    build(lson);
    build(rson);
    pushUp(rt);
}
void update(int rt,int L,int R,int l,int r,int v){
    if(l<=L&&R<=r){
        if(isprime[v]){
            tree[rt].sum=R-L+1;
            tree[rt].lazy=1;
        }
        else{
            tree[rt].sum=0;
            tree[rt].lazy=0;
        }
        return;
    }
    pushDown(rt);
    int mid=(L+R)>>1;
    if(l<=mid)
        update(lson,l,r,v);
    if(r>mid)
        update(rson,l,r,v);
    pushUp(rt);
}
int query(int rt,int L,int R,int l,int r){
    if(l<=L&&R<=r){
        return tree[rt].sum;
    }
    int mid=(R+L)>>1;
    int ret=0;
    pushDown(rt);
    if(l<=mid)
        ret+=query(lson,l,r);
    if(r>mid)
        ret+=query(rson,l,r);
    return ret;
}
int main()
{
    init();
    int op,x,y,v;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        printf("Case %d:\n",i);
        scanf("%d%d",&n,&q);
        build(1,1,n);
        for(int j=1;j<=q;j++){
            scanf("%d",&op);
            if(op==0){
                scanf("%d%d%d",&x,&y,&v);
                update(1,1,n,x,y,v);
            }
            else{
                scanf("%d%d",&x,&y);
                printf("%d\n",query(1,1,n,x,y));
            }
        }
    }
    return 0;
}
