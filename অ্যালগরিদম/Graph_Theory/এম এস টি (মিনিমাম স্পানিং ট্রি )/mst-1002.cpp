#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <numeric>

#include <cmath>
#include <cstdio>

#define IP(n) for(i=0;i<n;i++)
#define JP(n) for(j=0;j<n;j++)
#define KP(n) for(k=0;k<n;k++)

#define vi vector<int>
#define vi2 vector<vector<int>>
#define vs vector<string>

#define pb push_back
#define TC int t,check=1;cin>>t;while(check<=t)
#define FORIT(i,m) for(__typeof((m).begin()) i=(m).begin();i!=(m).end();i++)


using namespace std;

#define inf 10000000

int cst[505];
int ans[505];

void reset()
{
    for(int i=0;i<505; i++)
    cst[i]=inf,ans[i]=-1;
}

int main()
{

    int t,check=1;
    scanf("%d",&t);
    while(t--)
    {
        reset();
        char ch[5];
        gets(ch);
        int n,m;
        scanf("%d %d",&n,&m);

        vector<int >edge[n+2];
        vector<int >cost[n+2];
        int u,v,w;
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            edge[u].pb(v);
            edge[v].pb(u);
            cost[u].pb(w);
            cost[v].pb(w);
        }
        int src;
        scanf("%d",&src);
        cst[src]=0;
        ans[src]=0;
        priority_queue< pair <int,int> > q;
        q.push(make_pair(0,src));
        while(!q.empty())
        {
            pair<int,int> p;
            p=q.top();
            q.pop();
            int nw=p.second,to=0;
            for(int i=0;i<edge[nw].size();i++)
            {
                to=edge[nw][i];
                int tmpcost=max(cst[nw],cost[nw][i]);
                if(cst[to]>tmpcost)
                {
                    cst[to]=tmpcost;
                    ans[to]=max(ans[nw],cost[nw][i]);
                    q.push(make_pair(-tmpcost,to));
                    //cout<<nw<<" "<<to<<" "<<tmpcost<<" "<<ans[to]<<endl;
                }
            }
        }
        printf("Case %d:\n",check++);
        for(int i=0;i<n;i++)
        {
            if(ans[i]!=-1)
            printf("%d\n",ans[i]);
            else
            printf("Impossible\n");
        }
    }

    return 0;
}

