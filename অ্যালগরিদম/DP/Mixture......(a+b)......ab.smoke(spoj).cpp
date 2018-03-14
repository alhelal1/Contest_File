#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

#define SIZE 105

LL dp[SIZE][SIZE];

int sum[SIZE];
int arr[SIZE];

int mod = 100;

LL get_col(int low,int high){
    LL ret = sum[high]-sum[low-1];
    ret %= mod;
    if ( ret < 0 )ret += mod;

    return ret;
}

LL func(int low,int high){

    if ( low>=high )return 0;

    LL &ret = dp[low][high];
    if ( ret != -1 )return ret;

    ret = LLONG_MAX;

    for (int i=low;i<high;++i){
        ret = min( ret , get_col(low,i)*get_col(i+1,high) + func( low,i )+func(i+1,high) );
    }

    return ret;
}

int main(){

    int n;
    while ( scanf("%d",&n)==1 ){
        for (int i=1;i<=n;++i){
            scanf("%d",&arr[i]);
            sum[i] = ( sum[i-1]+arr[i] )%mod;
        }

        for (int i=1;i<=n;++i){
            for (int j=1;j<=n;++j){
                dp[i][j] = -1;
            }
        }

        printf("%lld\n",func(1,n));

    }


    return 0;
}
