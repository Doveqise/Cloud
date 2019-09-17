#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e2+5;
const int inf = 1e9+7;
int n,K;
int a[maxn],f[maxn][maxn][maxn];
int dfs(int l,int r,int k){
    if(l>r)
		return 0;
    if(f[l][r][k])
		return f[l][r][k];
    int res=f[l][r][k]=inf;
    if(k<K-1)
		res=min(res,dfs(l,r,k+1)+1);
    if(k==K-1)
		res=dfs(l+1,r,0);
    for(int i=l+1;i<=r;i++)
        if(a[i]==a[l])
            res=min(res,dfs(l+1,i-1,0)+dfs(i,r,min(K-1,k+1)));
    return f[l][r][k]=res;
}
signed main(){
    scanf("%d%d",&n,&K);
    for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
    dfs(1,n,0);
    printf("%d\n",f[1][n][0]);
    return 0;
}
