#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9+7;
const int maxn = 1e5+5;
struct edge
{
    int to,val,nxt;
}
ed[maxn<<1];
int hd[maxn],maxp[maxn],siz[maxn],dis[maxn],cnt;
int vis[maxn],tst[maxn],jud[maxn],q[maxn],re[maxn];
int query[maxn];
int sum,root,n,m;
void add(int x,int y,int z)
{
    ed[++cnt].val=z;
    ed[cnt].to=y;
    ed[cnt].nxt=hd[x];
    hd[x]=cnt;
}
void findroot(int id,int fa)
{
    siz[id]=1;
    maxp[id]=0;
    for(int i=hd[id];i;i=ed[i].nxt)
    {
        if(ed[i].to==fa||vis[ed[i].to])
            continue;
        findroot(ed[i].to,id);
        siz[id]+=siz[ed[i].to];
        maxp[id]=max(siz[ed[i].to],maxp[id]);
    }
    maxp[id]=max(maxp[id],sum-siz[id]);
    if(maxp[id]<maxp[root])
        root=id;
}
void findis(int id,int fa)
{
    re[++re[0]]=dis[id];
    for(int i=hd[id];i;i=ed[i].nxt)
    {
        if(ed[i].to==fa||vis[ed[i].to])
            continue;
        dis[ed[i].to]=dis[id]+ed[i].val;
        findis(ed[i].to,id);
    }
}
void cal(int id)
{
    int now=0;
    for(int i=hd[id];i;i=ed[i].nxt)
    {
        if(vis[ed[i].to])
            continue;
        re[0]=0;
        dis[ed[i].to]=ed[i].val;
        findis(ed[i].to,id);
        for(int j=re[0];j;j--)
            for(int k=1;k<=m;k++)
                if(query[k]>=re[j])
                    tst[k]|=jud[query[k]-re[j]];
        for(int j=re[0];j;j--)
        {
            q[++now]=re[j];
            jud[re[j]]=1;
        }
    }
    for(int i=1;i<=now;i++)
        jud[q[i]]=0;
}
void solve(int id)
{
    vis[id]=jud[0]=1;
    cal(id);
    for(int i=hd[id];i;i=ed[i].nxt)
    {
        if(vis[ed[i].to])
            continue;
        sum=siz[ed[i].to];
        root=0;
        maxp[id]=inf;
        findroot(ed[i].to,0);
        solve(root);
    }
}
signed main()
{
    scanf("%d%d",&n,&m);
    for(int i=1,x,y,z;i<=n-1;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
    }
    for(int i=1;i<=m;i++)
        scanf("%d",&query[i]);
    maxp[root]=sum=n;
    findroot(1,0);
    solve(root);
    for(int i=1;i<=m;i++)
        puts(tst[i]?"AYE":"NAY");
    return 0;
}