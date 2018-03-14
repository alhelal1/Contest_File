const  int N=5e5+5,MOD=1e9+7;

//struct info{LL x,y;}arr[N];bool com(info a,info b){return (a.x<b.x) or (a.x==b.x and a.y<b.y);}
LL ar[N];LL a=0,b=0,c=0,r=0,rr=0,res=0,n,m;
//string  s;


struct info
{
    LL x,y;
}T[3*N];

void insert(LL idx,LL st,LL end)
{
    if(st==end)
    {
        T[idx].x=ar[st];
        T[idx].y=st;
        return ;
    }

    LL mid=(st+end)>>1,lf=idx*2,rg=lf+1;
    insert(lf,st,mid);
    insert(rg,mid+1,end);

    if(T[lf].x<T[rg].x)  T[idx]=T[lf];
    else  T[idx]=T[rg];
    return ;
}



void up(LL idx,LL st,LL end,LL pos,LL val)
{
    if(st==pos  and end==pos)
    {
        T[idx].x=val;
       // T[idx].y=st;
        return ;
    }
    LL mid=(st+end)>>1,lf=idx*2,rg=lf+1;


    if(pos<=mid)
    up(lf,st,mid,pos,val);
    else
    up(rg,mid+1,end,pos,val);
    if(T[lf].x<T[rg].x)  T[idx]=T[lf];
    else  T[idx]=T[rg];
    return ;
}





info read(LL idx,LL st,LL end,LL i,LL j)
{
    if(st==i  and end==j)
    {
        return T[idx];
    }
    LL mid=(st+end)>>1,lf=idx*2,rg=lf+1;
    if(j<=mid)
    return read(lf,st,mid,i,j);
    else if(i>mid)  return read(rg,mid+1,end,i,j);

    else
    {
        info aa=read(lf,st,mid,i,mid);
        info bb= read(rg,mid+1,end,mid+1,j);
        if(aa.x<bb.x)  return aa;
        else  return bb;
    }

}



LL par[N][2];
LL find(LL idx,LL f)
{
    if(idx==par[idx][f])  return idx;
    else    return par[idx][f]=find(par[idx][f],f);
}



int main()
{
   fastinput;

    cin>>n;  repp(i,n)  cin>>ar[i];

    insert(1,1,n);


   // D(read(1,1,n,1,n).y);


    repp(i,n+2)  par[i][0]=i;
    repp(i,n+2)  par[i][1]=i;



    long long int r=0;


    repp(i,n-2)
    {

        LL aa=read(1,1,n,1,n).y;
        LL bb=find(aa,0);
        LL cc=find(aa,1);
        LL dd=find(bb-1,0);
        LL ee=find(cc+1,1);


        par[bb][0]=dd;
        par[cc][1]=ee;


       if(min(ar[dd],ar[ee])==0)  r+=ar[aa];
       else  r+=min(ar[dd],ar[ee]);
        up(1,1,n,aa,10000000);






    }


    cout<<r<<"\n";



   return 0;

}
