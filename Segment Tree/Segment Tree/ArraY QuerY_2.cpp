#include <stdio.h>
#include <string.h>
#include <stack>
#include <stdlib.h>
#include <deque>
#include <math.h>
#include <queue>
#include <limits.h>
#include <time.h>
#include <utility>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <list>
#include <iostream>
using namespace std;
template <class R> string R__MonthName(R name){string mon[15];mon[1]="January";mon[2]="February";mon[3]="March";mon[4]="April";mon[5]="May";mon[6]="June";mon[7]="July";mon[8]="August";mon[9]="September";mon[10]="October";mon[11]="November";mon[12]="December";return mon[name];}
template <class R> R R__MonthDay(R num){R month[13];month[1]=31;month[2]=28;month[3]=31;month[4]=30;month[5]=31;month[6]=30;month[7]=31;month[8]=31;month[9]=30;month[10]=31;month[11]=30;month[12]=31;return month[num];}
template <class R> R R__GCD(R a,R b){if(b==0) return a;else return R__GCD(b,a%b);}
template <class R> R R__LCM(R a,R b){return (a*b)/R__GCD(a,b);}
template <class R> R R__POW( R a, R b){if(b==0) return 1; R x=a;for(R i=2;i<=b;i++) a=a*x;return a;}
template <class R> R R__BigMod(R a,R b,R c){if(a==0) return 0;if(b==0) return 1;if(b%2==0){R x=R__BigMod(a,b/2,c)%c;return (x*x)%c;}else return  ((a%c)*R__BigMod(a,b-1,c)%c)%c;}
template <class R> R R__Factorial(R a){R b=1;for(R i=1;i<=a;i++)b=b*i;return b;}
template <class R> R R__BinarySearch(R a[],R l,R h,R n){while(l<=h){R m=(l+h)/2;if(n<a[m])h=m-1;else if(n>a[m])l=m+1;else return m;} return -1;}
struct{
    long long sum=0,prop=0;
}tree[1000005];
void refresh()
{
    for(int i=1;i<=1000000;i++)
    {
        tree[i].sum=0;
        tree[i].prop=0;
        }
}
void update(long long node,long long low,long long high,long long a,long long b,long long V)
{
    if(a>high||b<low) return;

    if(low>=a&&high<=b)
    {
        tree[node].sum=tree[node].sum+(high-low+1)*V;
        tree[node].prop+=V;
        return;
    }

    long long left=node*2;
    long long right=node*2+1;
    long long mid=(low+high)/2;
    update(left,low,mid,a,b,V);
    update(right,mid+1,high,a,b,V);

    tree[node].sum=tree[left].sum+tree[right].sum+(high-low+1)*tree[node].prop;
}
long long query(long long node,long long low,long long high,long long a,long long b,long long carry)
{
    if(a>high||b<low) return 0;
    if(low>=a&&high<=b)
        return tree[node].sum+carry*(high-low+1);

        long long left=node*2;
        long long right=(node*2)+1;
        long long mid=(low+high)/2;
        long long p1 = query(left,low,mid,a,b,carry+tree[node].prop);
        long long p2 = query(right,mid+1,high,a,b,carry+tree[node].prop);
        return  p1+p2;
}
int main()
{
    //time_t t1=clock();
    //freopen("input.txt","r",stdin);//freopen("output.txt","w",stdout);
    long long  test;
    scanf("%lld",&test);
    int cas=1;
    while(test--)
    {
        long long node,Q;
        cout<<"Case "<<cas++<<":\n";
        scanf("%lld%lld",&node,&Q);
        while(Q--)
        {
            int swit;
            scanf("%d",&swit);
            if(swit==0)
            {
                long long in1,in2,V;

                scanf("%lld%lld%lld",&in1,&in2,&V);
                in1++;in2++;
                update(1,1,node,in1,in2,V);
            }
            else
            {
                long long in1,in2;

                scanf("%lld%lld",&in1,&in2);
                in1++;in2++;
                printf("%lld\n",query(1,1,node,in1,in2,0));
            }
        }
        refresh();
    }
    //time_t t2=clock();
    //cout<<(t2-t1);
    return 0;
}
