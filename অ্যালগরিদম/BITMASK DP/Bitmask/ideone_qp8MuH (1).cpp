#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <queue>
#include <list>
#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;
ll a[22],v;
int s[8][2097160],n,k,flag;

int dp(int indx,int mask,ll take)
{
	if(indx==k) return flag=take==0;
	if(flag) return flag;
	int p=0,q=0;
	if(take==v) return dp(indx+1,mask,0);
	if(take>v)return false;
	if(s[indx][mask]!=-1)return s[indx][mask];
	for(int i=n-1;i>=0;i--)
	{
		if(((1<<i)&mask)==0)
		{
			q|=dp(indx,mask|(1<<i),take+a[i]);
		}
	}
	return s[indx][mask]=p|q;
}
int main ()
{
    int t,i,c;
    ll sum;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            sum+=a[i];
        }
		if(k==1)
        {
            printf("yes\n");
            continue;
        }
        if(sum==0)
		{
			if(k<=n)
				printf("yes\n");
			else
				printf("no\n");
			continue;
		}

        sort(a,a+n);
        vector <int> vec;
        if(sum%k==0)
        {
            v=sum/k;
            if(a[n-1]<=v)
            {
				memset(s,-1,sizeof(s));
				flag=false;
				flag=dp(0,0,0);
				if(flag)
					printf("yes\n");
				else
					printf("no\n");
			}
			else
				printf("no\n");
        }
        else
        {
            printf("no\n");
        }
    }
    return 0;
}
