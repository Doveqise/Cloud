#include<bits/stdc++.h>
using namespace std;
int f[25][25];
int solve(int x,int y){
    if(f[x][y])return f[x][y];
    if(!x)return f[x][y]=1;
    if(x==1||y==1)return f[x][y]=1;
    if(x<y) return f[x][y]=solve(x,x);
    return f[x][y]=solve(x-y,y)+solve(x,y-1);
}
signed main(){
    int t;scanf("%d",&t);
    while(t--){
        int m,n;scanf("%d%d",&m,&n);
        printf("%d\n",solve(m,n));
    }
    return 0;
}