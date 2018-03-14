#include <iostream>
#include <stdio.h>
#include <string.h>
#include <set>
#include <queue>
#include <algorithm>
#define z1 12005
#define sz 105
#define inf 1000000000
using namespace std;
struct edge{
    int u,v,w;
};

int p[sz],costmin, costmax;
inline bool cmp(edge a,edge b)
{
    return a.w<b.w;
}
edge e[z1];
int n;
int g[sz][sz];
bool vis[sz];

inline int findparent (int a)
{
    if(p[a]==a)
        return a;

    p[a]= findparent(p[a]);

    return p[a];

}

inline bool BFS()
{
int i,rec,cur;

    memset(vis,false,sizeof(vis));
    queue<int>q;

    vis[0]=true;
    rec =1;
    q.push(0);

    while(!q.empty())
    {
        cur= q.front();
             q.pop();

        for(i=0;i<n;i++)
        {
            if(g[cur][i]==0)  continue;
            if(vis[i]== true)   continue;

            vis[i]= true;
            rec++;
            q.push(i);
        }
    }

    if(rec==n)
        return true;
    return false;

}
int main()
{
    int t,tc,cnt,i,j,now,px,py,tot;
    bool a1;

     scanf("%d",&t);
     tc = 0;

     while(tc<t)
     {
         tc++;
         scanf("%d",&n);

         tot = 0;
         memset(g,0,sizeof(g));
         for(i=0;i<n;i++)
         {
             for(j=0;j<n;j++)
            {
                now= i*n+j;
                e[now].u = i;
                e[now].v = j;
                 scanf("%d",&e[now].w);
                 g[i][j]+= e[now].w;
                 g[j][i]+=e[now].w;
                 tot += e[now].w;
             }
         }

        a1 = BFS();
        if(a1 == false)
        {
            printf("Case %d: -1\n",tc);
            continue;
        }

          cnt = n*n;

         sort(e,e+cnt,cmp);
        for(i=0;i<n;i++)
            p[i]= i;

         costmin = 0;
        for(i=0;i<cnt;i++)
         {
             if(e[i].w == 0)
                continue;

             px = findparent (e[i].u);
             py = findparent (e[i].v);

             if(px==py)
                continue;
             p[px] = py;
                 costmin+= e[i].w;
         }


         tot = tot- costmin;
         printf("Case %d: %d\n",tc,tot);

     }

     return 0;
}

