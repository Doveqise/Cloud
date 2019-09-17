#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f,N=200+5;
int f[N][N],t[N*N],n,m,k,x,y,w;
int main(){
    scanf("%d%d",&n,&m);memset(f,0x3f,sizeof(f));
    for(int i=0;i<n;i++) scanf("%d",&t[i]),f[i][i]=0;
    for(int i=0;i<m;i++){scanf("%d%d%d",&x,&y,&w);f[x][y]=f[y][x]=w;}
    int Q;scanf("%d",&Q);
    while(Q--){
        scanf("%d%d%d",&x,&y,&w);
        while(t[k]<=w&&k<=n){
            for(int i=0;i<n;i++)  for(int j=0;j<n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            k++;
            }
        if(f[x][y]==INF||t[x]>w||t[y]>w)puts("-1");
        else printf("%d\n",f[x][y]);}
    return 0;
}
