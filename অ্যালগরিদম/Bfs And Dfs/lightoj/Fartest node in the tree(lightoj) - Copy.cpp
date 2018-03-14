#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <list>
#include <deque>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
#define memo(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mx 10000000
vector <long long> prime ;
char status[mx+10];
void sieve()
{
    prime.push_back(2);
    for(long long i=3;i<=mx;i+=2)
    {
        if(status[i]==NULL)
        {
            prime.push_back(i);
            for(long long j=i*i;j<=mx;j+=i*2) status[j]='1';
        }
    }
}
long long number_Of_Odd_Divisors(long long number)
{
    long long ans = 1 ;
    for(int i = 0 ;i<prime.size();i++)
    {
        if(prime[i]*prime[i]>number) break;
        if(number%prime[i]==0)
        {
            long long cnt = 0 ;
            while(number%prime[i]==0)
            {
                number/=prime[i];
                cnt++;
            }
            if(prime[i]%2==1)ans*=(cnt+1);
        }
    }
    if(number!=1&&number%2==1) ans*=2;
    return ans-1;
}
int main()
{
    //freopen("input.txt","r",stdin);
    sieve();
    int test ;
    scanf("%d",&test);
    for(int cas=1;cas<=test;cas++)
    {
        long long X ;
       // cin >> X ;
        //cout <<   << endl ;

        scanf("%lld",&X);

        printf("%lld\n",number_Of_Odd_Divisors(X));
    }
    return 0;
}
