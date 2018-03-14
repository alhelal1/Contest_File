#include <iostream>
#include <stdio.h>
#include <string.h>
#include <set>
#include <queue>
#include <algorithm>
#include <map>
#define z1 12005
#define sz 105
#define inf 1000000000
using namespace std;
struct edge{
    int u,v,w;
};
map<string,int>mm;
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
    vis[1]=true;
    rec =1;
    q.push(1);
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
    if(rec==(n-1))
        return true;
    return false;

}
int main()
{
    int t,tc,cnt,m,i,j,now,px,py,tot;
    bool a1;

     scanf("%d",&t);
     tc = 0;
     while(tc<t)
     {
         tc++;
         scanf("%d",&m);
         tot = 0;
         memset(g,0,sizeof(g));
         n = 1;

         char str1[100],str2[100];
         string s1,s2;
         mm.clear();
        int k1,k2;
         for(i=0;i<m;i++)
         {
             scanf("%s %s %d",&str1,&str2,&e[i].w);
             s1= str1;
             s2= str2;
             if(mm.find(s1)==mm.end())
             {
                 mm[s1]= n;
                 n++;
             }
             if(mm.find(s2)==mm.end())
             {
                 mm[s2]= n;
                 n++;
             }
             k1= mm[s1];
             k2=mm[s2];
             g[k1][k2] = 1;
             g[k2][k1] = 1;
             e[i].u = k1;
             e[i].v= k2;

         }
        a1 = BFS();
        if(a1 == false)
        {
            printf("Case %d: Impossible\n",tc);
            continue;
        }
         sort(e,e+m,cmp);
        for(i=1;i<n;i++)
            p[i]= i;

         costmin = 0;
        for(i=0;i<m;i++)
         {

             px = findparent (e[i].u);
             py = findparent (e[i].v);

             if(px==py)
                continue;
             p[px] = py;
                 costmin+= e[i].w;
         }


         tot = costmin;
         printf("Case %d: %d\n",tc,tot);

     }

     return 0;
}
