#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<cctype>
#include<cstdio>
#include<string>
#include<sstream>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<iterator>
#include<iostream>
#include<algorithm>

using namespace std;

#pragma comment(linker,"/STACK:16777216")
#pragma warning(disable:4786)

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define myabs(a) ((a)<0?(-(a)):(a))
#define pi acos(-1.0)
#define inf (1<<29)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define eps 1e-9
#define root 1
#define lft 2*idx
#define rgt 2*idx+1
#define cllft lft,st,mid
#define clrgt rgt,mid+1,ed
#define i64 long long
#define MX 250000

typedef pair<int,int> pii;

int qq[MX],bit[MX],val[MX];
pii seg[MX];

void insert(int x,int val){
    while(x<MX){
        bit[x]+=val;
        x+=(x&(-x));
    }
}

int query(int x){
    int ret=0;
    while(x){
        ret+=bit[x];
        x-=(x&(-x));
    }
    return ret;
}

int main(){
    //freopen("in.txt","r",stdin);
    int cs,t=1,n,q,vsz,res,i,x,y;
    scanf("%d",&cs);
    while(cs--){
        scanf("%d %d",&n,&q);
        vsz=0;
        val[vsz++]=-9;
        for(i=0;i<n;i++){
            scanf("%d %d",&seg[i].ff,&seg[i].ss);
            val[vsz++]=seg[i].ff;
            val[vsz++]=seg[i].ss+1;
        }
        printf("Case %d:\n",t++);
        for(i=0;i<q;i++){
            scanf("%d",&qq[i]);
            val[vsz++]=qq[i];
        }
        sort(val,val+vsz);
        CLR(bit);
        for(i=0;i<n;i++){
            x=lower_bound(val,val+vsz,seg[i].ff)-val;
            y=lower_bound(val,val+vsz,seg[i].ss+1)-val;
            insert(x,1);
            insert(y,-1);
        }
        for(i=0;i<q;i++){
            x=lower_bound(val,val+vsz,qq[i])-val;
            res=query(x);
            printf("%d\n",res);
        }
    }
    return 0;
}
