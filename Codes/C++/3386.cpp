#include<bits/stdc++.h>
#define MAXN 1005
using namespace std;
int nx,ny,m,x,y,ans;
int cx[MAXN],cy[MAXN],e[MAXN][MAXN],vis[MAXN];
int find(int u){
    for(int v=1;v<=ny;v++){
        if(e[u][v]&&!vis[v]){
            vis[v]=1;
            if(cy[v]==-1||find(cy[v])){cx[u]=v;cy[v]=u;return 1;}
        }
    }
    return 0;
}
int main(){
    scanf("%d%d%d",&nx,&ny,&m);
    memset(cx,-1,sizeof(cx));
    memset(cy,-1,sizeof(cy));
    while (m--){
        cin>>x>>y;
        if(x>nx||y>ny)continue;
        e[x][y]=1;
    }
    for(int i=1;i<=nx;i++){
        if(cx[i]==-1){
            memset(vis,0,sizeof(vis));
            ans+=find(i);
        }
    }
    printf("%d",ans);
    return 0;
}
