#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e2+5;
const double inf = 1e9+7;
double dis[maxn][maxn],px[maxn],py[maxn];
int vis[maxn];
int n;
double ans=inf;
void dfs(int pos,int dep,double res)
{
    if(dep==n)
    {
        ans=min(ans,res);
        return;
    }
    if(res>=ans)
        return;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            dfs(i,dep+1,res+dis[pos][i]);
            vis[i]=0;
        }
    }
}
signed main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lf%lf",&px[i],&py[i]);
    }
    px[0] = py[0] = 0;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            dis[i][j]=hypot(px[i]-px[j],py[i]-py[j]);
    dfs(0, 0, 0);
    printf("%.2f\n",ans);
    return 0;
}