#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n,k,ans;
int dis[maxn],dep[maxn],nd[maxn];
vector<int>g[maxn];
void dfs(int o,int fa,int p)
{
    for(int i=0;i<g[o].size();i++)
    {
        int v=g[o][i];
        if(v==fa)
            continue;
        if(p==0)
        {
            dep[v]=dep[o]+1;
            dfs(v,o,0);
        }
        if(p==1)
        {
            dep[v]=dep[o]+1;
            if(g[v].size()==1)
            {
                nd[o]=min(nd[o],1);
                nd[v]=0;
            }
            else
            {
                dfs(v,o,1);
                nd[o]=min(nd[v]+1,nd[o]);
            }
        }
        if(p==2)
        {
            if(dep[v]>=nd[v])
                ans++;
            else
                dfs(v,o,2);
        }
    }
}
signed main()
{
    memset(dis,0x3f,sizeof(dis));
    memset(nd,0x3f,sizeof(nd));
    scanf("%d%d",&n,&k);
    for(int i=1,t1,t2;i<n;i++)
    {
        scanf("%d%d",&t1,&t2);
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    dfs(k,0,0);
    dis[k]=0;
    dfs(k,0,1);
    dfs(k,0,2);
    printf("%d\n",ans);
    return 0;
}