#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e3+5;
const int inf = 9876543210;
struct edge
{
    int u,v,dis;
    bool operator < (const edge &b)const
    {
        return dis<b.dis;
    }
}
ed[maxn*maxn];
int px[maxn],py[maxn],fa[maxn];
int n,c,tot=0;
int findfa(int x)
{
    return fa[x]==x?x:fa[x]=findfa(fa[x]);
}
void kruskal()
{
    int u,v,cnt=0,dis=0,ans=0;
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=tot;i++)
    {
        u=ed[i].u,v=ed[i].v;
        u=findfa(u);
        v=findfa(v);
        if(u!=v)
        {
            fa[u]=v;
            ans+=ed[i].dis;
            cnt++;
        }
        if(cnt+1==n)
            break;
    }
    if(cnt+1==n)
        printf("%d\n",ans);
    else
        puts("-1");
    return;
}
signed main()
{
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&px[i],&py[i]);
        for(int j=1;j<i;j++)
        {
            int ds=(px[i]-px[j])*(px[i]-px[j])+(py[i]-py[j])*(py[i]-py[j]);
            if(ds>=c)
            {
                ed[++tot].u=i;
                ed[tot].v=j;
                ed[tot].dis=ds;
            }
        }
    }
    sort(ed+1,ed+1+tot);
    kruskal();
    return 0;
}