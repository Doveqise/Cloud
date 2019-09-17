#include<bits/stdc++.h>
using namespace std;
int n,m,r,c;
int lc[20],hc[20][20],num[20][20],ch[20],gs=1;
int f[20][20];
void pre(){
    for(int i=1;i<=m;i++){
        lc[i]=0;
        for(int j=1;j<r;j++) lc[i]+=abs(num[ch[j]][i]-num[ch[j+1]][i]);
    }
    for(int i=2;i<=m;i++) for(int j=1;j<i;j++){
        hc[i][j]=0;
        for(int k=1;k<=r;k++) hc[i][j]+=abs(num[ch[k]][i]-num[ch[k]][j]);
    }
}
int minn=1e9+7,tmp=0;
void solve(){
    for(int i=1;i<=m;i++){
        tmp=min(i,c);
        for(int j=1;j<=tmp;j++){
            if(j==1) f[i][j]=lc[i];
            else if(i==j) f[i][j]=f[i-1][j-1]+lc[i]+hc[i][j-1];
            else{
                f[i][j]=1e9+7;
                for(int k=j-1;k<i;k++) f[i][j]=min(f[i][j],f[k][j-1]+lc[i]+hc[i][k]);
            }
            if(j==c) minn=min(minn,f[i][c]);
        }
    }
}
void dfs(int numb){
    if(numb>n){pre();solve();return;}
    if(r+numb==n+gs){
        ch[gs++]=numb;
        dfs(numb+1);
        ch[gs--]=0;
        return;
    }
    dfs(numb+1);
    if(gs<=r){
        ch[gs++]=numb;
        dfs(numb+1);
        ch[gs--]=0;
    }
}
int main(){
    scanf("%d%d%d%d",&n,&m,&r,&c);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&num[i][j]);
    dfs(1);
    printf("%d",minn);
    return 0;
}
