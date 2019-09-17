#include<bits/stdc++.h>
using namespace std;
int to[200005],id[200005],ans=0;
bool ned[200005],vis[200005];
int dfs(int x){
    if(ned[x])return 0;
    ned[x]=1;
    return dfs(to[x])+1;
}
void ddfs(int x){
    vis[x]=1;
    --id[to[x]];
    if(!id[to[x]])ddfs(to[x]);
}
signed main(){
	int n;scanf("%d",&n);
	for(int i=1,a;i<=n;++i){scanf("%d",&a);to[i]=a;++id[a];}
    for(int i=1;i<=n;++i)if(!id[i]&&!vis[i])ddfs(i);
    for(int i=1;i<=n;++i)if(!ned[i]&&!vis[i])ans+=dfs(i);
    printf("%d",ans);
    return 0;
}