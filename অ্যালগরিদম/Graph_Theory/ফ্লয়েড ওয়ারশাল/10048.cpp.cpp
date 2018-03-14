#include <iostream>
#include <cstdio>
using namespace std;

#define MAX 105
int adj[MAX][MAX];

void initAdj(int C){
 for(int i=1;i<=C;i++)
     for(int j=1;j<=C;j++)adj[i][j] = -1;
}
void loadAdj(int s){
  int from,to,decibel;
  for(int i=1;i<=s;i++){
      scanf("%d %d %d",&from,&to,&decibel);
      adj[from][to] = decibel;
      adj[to][from] = decibel;
  }
}
int getMax(int x1, int x2){
  if(x1>x2)return x1;
  else return x2;
}

void floydWarshall(int noOfNodes){
    int from,via,to;
    for(via=1;via<=noOfNodes;via++){
     for(from=1;from<=noOfNodes;from++){
      for(to=1;to<=noOfNodes;to++){
       if(adj[from][via]!=-1&&adj[via][to]!=-1&&from!=to){
         if((adj[from][via]<adj[from][to]&&adj[via][to]<adj[from][to])||adj[from][to]==-1){
           adj[from][to] = getMax(adj[from][via],adj[via][to]);
         }
       }
      }
     }

    }

}

void executeResults(int Q){
    int from,to;
  for(int i=1;i<=Q;i++){
   scanf("%d %d",&from,&to);
   if(adj[from][to]==-1)printf("no path\n");
   else printf("%d\n",adj[from][to]);
  }
}

int main(){
    int C,S,Q;
    int testCase = 1;

    while(scanf("%d %d %d",&C,&S,&Q)==3&&!(C==0&&S==0&&Q==0)){
       if(testCase!=1)
        printf("\n");
        initAdj(C);
        loadAdj(S);
        floydWarshall(C);
        printf("Case #%d\n",testCase++);
        executeResults(Q);
    }
    return 0;
}
