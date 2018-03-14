#include<stdio.h>
#include<cstring>
#define mod 10007
struct mat
{
    int m[3][3];
}e,d;
int an[3]={2,1,1};
mat Mul(mat a,mat b)
{
    mat ans;
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++){
        ans.m[i][j]=0;
        for(int k=0;k<3;k++)
            ans.m[i][j]+=a.m[i][k]*b.m[k][j];
        ans.m[i][j]%=mod;
    }
    return ans;
}
int Pow(int n)
{
    mat ans=e,a=d;
    while(n){
        if(n&1) ans=Mul(ans,a);
        n>>=1;
        a=Mul(a,a);
    }
    return ans.m[0][0];
}
int main()
{
    memset(e.m,0,sizeof(e.m));
    memset(d.m,0,sizeof(d.m));
    for(int i=0;i<3;i++) e.m[0][i]=an[i];
    d.m[0][1]=d.m[1][2]=d.m[2][0]=1;
    d.m[0][0]=2;
    int t,n,ca=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("Case %d: ",++ca);
        if(n==1) printf("1\n");
        else printf("%d\n",Pow(n-2));
    }
    return 0;
}
