#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 1000050 ;
const int sigma_size = 52 ;

int ID[1010] , tot ;
char text[100050] , word[2111] ;
bool flag[1010] ;
int son[maxn][sigma_size] , val[maxn] , f[maxn] , last[maxn] , q[maxn], sz ;

inline int idx(char c) {
    if(c<='Z') return c - 'A' ;
    else return c - 'a' + 26 ;
}

int Insert(char *s){
    int u = 0 ;
    for(int i=0 ; s[i] ; i++) {
        int v = idx(s[i]) ;
        if(!son[u][v]) son[u][v] = ++sz ;
        u = son[u][v] ;
    }
    if(!val[u]) val[u] = ++tot ;
    return val[u];
}

void get_fail() {
    int rear = 0 ;
    f[0] = 0 ;
    for(int c=0; c<sigma_size ; c++) {
        int u = son[0][c] ;
        if(u) f[u] = last[u] = 0 , q[rear++] = u ;
    }
    for(int _i=0; _i<rear ; _i++) {
        int u = q[_i] ;
        for(int c=0; c<sigma_size; c++){
            int v = son[u][c] ;
            if(!v) { son[u][c] = son[f[u]][c] ; continue ; }
            q[rear++] = v;
            int x = f[u] ;
            while(x && !son[x][c]) x = f[x] ;
            f[v] = son[x][c] ;
            last[v] = val[f[v]] ? f[v] : last[f[v]] ;
        }
    }
}

void print(int u){
    while(u) {
        flag[val[u]] = true ;
        u = last[u] ;
    }
}

void Find(char *s){
    int j = 0;
    for(int i=0; s[i] ; i++) {
        int c=idx(s[i]);
        while(j && !son[j][c]) j = f[j] ;
        j = son[j][c] ;
        print(j) ;
    }
}

int main()
{
    gets(text) ;
    int n ;
    scanf("%d", &n) ; getchar() ;
    for(int i=1; i<=n; i++) {
        scanf("%s" , word) ;
        ID[i] = Insert(word);
    }
    Find(text) ;
    for(int i=1; i<=n; i++) {
        if(flag[ ID[i] ]) puts("Y") ;
        else puts("N") ;
    }
    return 0 ;
}
