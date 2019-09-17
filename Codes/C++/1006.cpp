#include<bits/stdc++.h>
using namespace std;
int dp[55][55][55][55],ditu[55][55];
signed main(){
    int m,n;scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) scanf("%d",&ditu[i][j]);
    for(int x=1;x<=m;x++) for(int y=1;y<=n;y++)
    for(int z=1;z<=m;z++) for(int v=1;v<=n;v++){
    dp[x][y][z][v]=max(max(dp[x-1][y][z-1][v],dp[x-1][y][z][v-1]),max(dp[x][y-1][z-1][v],dp[x][y-1][z][v-1]))+ditu[x][y]+ditu[z][v];
    if(x==z&&y==v)dp[x][y][z][v]-=ditu[x][y];}
    printf("%d",dp[m][n][m][n]);
    return 0;
    
}