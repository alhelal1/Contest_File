#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#define sz 200005
using namespace std;
struct edge{
    int u,v,c,typ;
};
edge e[sz];
int p[sz];

inline bool cmp(edge a, edge b)
{
    if(a.c!=b.c)
        return a.c<b.c;
    return a.typ>b.typ;
}
int findparent (int a)
{
    if(p[a]==a)
        return a;

    p[a] = findparent(p[a]);
    return p[a];

}
int main()
{
    int t,tc,N,M,A,i,cnt,cost,airports;

    scanf("%d",&t);
    tc = 0;
    while(tc<t)
    {
        tc++;
        scanf("%d %d %d",&N,&M,&A);

        for(i=0;i<M;i++)
        {
            scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].c);
            e[i].typ = 0;
        }

        cnt = M;
        for(i=2;i<=N;i++)
        {
            e[cnt].u = 1;
            e[cnt].v = i;
            e[cnt].c = A;
            e[cnt].typ = 1;
            cnt++;
        }
        int ccc=1;

        cost = A;
        airports = 1;
        int px,py;

        sort(e,e+cnt,cmp);

        for(i=1;i<=N;i++)
            p[i]=i;

       for(i=0 ;i < cnt;i++)
       {
           px=findparent(e[i].u);
           py = findparent(e[i].v );

           if(px==py)
                continue;
           airports+= e[i].typ;
           cost += e[i].c;

            p[px] = py;
       }
        printf("Case %d: %d %d\n",tc,cost,airports);
    }

    return 0;
}
