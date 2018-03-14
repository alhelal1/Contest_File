#include<bits/stdc++.h>
using namespace std;
char s[100005];
long long tree[400005];

long long MAX=1000000;

long long insert(long long node,long long left,long long right)
{
    if(left==right)
    {
        tree[left]=ar[left];

        return ;
    }

    long long mid=(left+right)/2;

    insert(node*2,left,mid);

    insert(node*2+1,mid+1,right);
}





long long update(long long node,long long left,long long right,long long i,long long j,long long value)
{
    if(left==i and j==right)
    {
        tree[node]=value;
        return;
    }

    long long mid=(left+right)/2;
    if(j<=mid)
    {
        update(node*2,left,mid,i,j,val);
    }
    else if(i>mid)
    {

    }
}




long long  total(long long pos)
{

    long long sum=0;
    while(pos>0)
    {
       sum+=tree[pos];

       pos=pos-(pos&-pos);
    }
    return sum;
}



int main()
{
    int t;


    int ks=0;


    scanf("%d",&t);

    while(t--)
    {


        memset(tree,false,sizeof(tree));
        scanf("%s",s);

        MAX=strlen(s);
        int n;
        scanf("%d",&n);



        char ch[2];


        int a,b;


        printf("Case %d:\n",++ks);
        for(int i=0;i<n;i++)
        {

            scanf("%s",ch);


            if(ch[0]=='I')
            {
                scanf("%d%d",&a,&b);

                update(a,1LL);
                update(b+1,-1LL);
            }

            else
            {
                int aa;


                scanf("%d",&a);
                aa=total(a);


                aa+=s[a-1]-'0';

                if(aa%2==1)
                {
                    printf("1\n");
                }
                else printf("0\n");
            }


        }
    }
}
