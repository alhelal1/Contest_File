#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cstdio>
#include <math.h>
#include <cctype>
#include <string>
#include <vector>
#include <limits>
#include <bitset>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <cstring>
#include <utility>
#include <iomanip>
#include <iterator>
#include <iostream>
#include <algorithm>
using namespace std;

#define LL long long
#define LD long double
#define eps 1e-10
#define INF 1000000000
#define pb push_back
#define ppb pop_back
#define pii pair<int,int>
#define Clear(t) memset((t),0,sizeof(t))
#define alTrue(t) memset((t),1,sizeof(t))
#define alNeg(t) memset((t),-1,sizeof(t))
#define REP(i,n) for(__typeof(n) i=0; i<(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=a; i<=(b); i++)
#define RFOR(i,a,b) for(__typeof(b) i=a; i>=(b); i--)
#define Iterator(it, l) for (typeof(l.begin()) it = l.begin(); it != l.end(); it++)
#define PI 3.1415926535897932384626433832795028841971693993751
#define Floyd(G,p,n) FOR(k,p,n) FOR(i,p,n) FOR(j,p,n) G[i][j] = min( G[i][j], G[i][k] + G[k][j] );

template<class T> T sq(T n){return n*n;}
template<class T> T getabs(T n){return n<0 ? -n : n;}
template<class T> T getmax(T a, T b){return ( a>b ? a : b);}
template<class T> T getmin(T a, T b){return ( a<b ? a : b);}
template<class T> void setmax(T &a, T b){if(a<b) a=b;}
template<class T> void setmin(T &a, T b){if(a>b) a=b;}
template<class T> T gcd(T a, T b){return (b!=0?gcd<T>(b,a%b):a);}
template<class T> T lcm(T a, T b){return ((a*b)/gcd(a,b));}
template<class T> T power(T n, T p){if(p==0) return 1; return ((p==1)?n:(n*power(n,p-1)));}

int tst, cases=0,n, m, u, v, w, t, p;

vector< pii > ct[502];

int vis[502], d[502];

void dijkstra(int s){
    priority_queue< pair<int ,int >, vector< pair<int ,int > >, greater< pii > > q;

    q.push(make_pair(0,s));

    d[s] = 0;

    while(!q.empty()){
        w = q.top().first;
        u = q.top().second;

        q.pop();

        if(d[u] < w) continue;

        REP(i,ct[u].size()){
            v = ct[u][i].second;
            p = ct[u][i].first;

            if(d[v] > max(p,w)){
                d[v] = max(p,w);
                q.push(make_pair(d[v],v));
            }
        }
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&tst);
    while(tst--){
        scanf("%d %d",&n,&m);

        REP(i,n) ct[i].clear();

        REP(i,n) d[i] = INF;

        REP(i,m){
            scanf("%d %d %d",&u,&v,&w);
            ct[u].pb(make_pair(w,v));
            ct[v].pb(make_pair(w,u));
        }

        scanf("%d",&t);

        dijkstra(t);

        printf("Case %d:\n",++cases);

        REP(i,n){
            if(d[i]<INF) printf("%d\n",d[i]);
            else printf("Impossible\n");
        }
    }
    return 0;
}
