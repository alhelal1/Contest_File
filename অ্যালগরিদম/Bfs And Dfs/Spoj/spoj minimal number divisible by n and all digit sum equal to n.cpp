using namespace std;
#include<bits/stdc++.h>
typedef long long  ll;

struct info
{
    ll x,y,z;
}par[1005][1005];

short vis[1010][1010];
ll n;

void print(info dd)
{
    if(par[dd.x][dd.y].z==-1)return;

    print(par[dd.x][dd.y]);
    cout<<dd.z<<endl;

    return ;
}

ll kk=1;
ll dfs()
{
    queue<info>q;

    kk++;
    info aa;
    aa.x=0,aa.y=0,aa.z=0;
    q.push(aa);

    par[aa.x][aa.y].z=-1;

    vis[aa.x][aa.y]=kk;

    ll f=0;
    while(!q.empty())
    {
        info bb=q.front();
        q.pop();

        info cc;
        for(int i=0;i<10;i++)
        {
            //info cc;
            cc.x=bb.x+i;
            cc.y=(bb.y*10+i)%n;
            cc.z=i;
            if(cc.x>n)break;
            if(vis[cc.x][cc.y]!=kk)
            {
                vis[cc.x][cc.y]=kk;

                par[cc.x][cc.y]=bb;

                q.push(cc);


                if(cc.x==n and  cc.y==0)
                {
                    f=1;
                    break;
                }
            }
        }

        if(f==1)
        {
            print(cc);
            break;
        }

        kk++;
    }
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(false);
    ll t=0,ks=0;
    cin>>t;
    while(t--)
    {
        cin>>n;

        dfs();
    }


   return 0;

}
