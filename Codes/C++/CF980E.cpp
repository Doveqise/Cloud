#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
int n,k,tot,now;
int hd[maxn],cnt;
int siz[maxn],dfn[maxn],vis[maxn];
int fa[maxn],g[maxn],dep[maxn];
struct edge
{
    int nxt,to;
}
e[maxn<<1];
int lowbit(int x)
{
    return x&(-x);
}
void ins(int x,int t)
{
    for(;x<=n;x+=lowbit(x)) 
        g[x]+=t;
}
int query(int x,int ans=0)
{
    for(;x;x-=lowbit(x))
        ans+=g[x];
    return ans;
}
void add(int x,int y)
{
    e[++cnt]=(edge){hd[x],y};
    hd[x]=cnt;
    e[++cnt]=(edge){hd[y],x};
    hd[y]=cnt;
}
void dfs(int x,int ff=0)
{
    fa[x]=ff;
    dfn[x]=++tot;
    dep[x]=dep[ff]+1;
    siz[x]=1;
    for(int i=hd[x],y;y=e[i].to;i=e[i].nxt)
        if(y!=ff)
        {
            dfs(y,x);
            siz[x]+=siz[y];
        }
}
void solve(int x)
{
    if(dep[x]-query(dfn[x])+now>k)
        return;
    for(;x!=n;x=fa[x])
    {
        if(vis[x])
            break;
        vis[x]=1;
        ins(dfn[x],1);
        ins(dfn[x]+siz[x],-1);
        now++;
    }
}
signed main()
{
    scanf("%d%d",&n,&k);
    k=n-k;
    for(int i=1,x,y;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        add(x,y);
    }
    vis[n]=1;
    dfs(n);
    for(int i=n-1;i;i--)
        if(!vis[i])
            solve(i);
    for(int i=1;i<=n;i++)
        if(!vis[i])
            printf("%d ",i);
    puts("");
    return 0;
}