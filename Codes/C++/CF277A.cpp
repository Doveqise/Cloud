#include <bits/stdc++.h>
using namespace std;
const int maxn=1e2+5;
int n,res;
int vis[maxn],fa[maxn];
bool Flag;
void init()
{
    for(int i=1;i<=n;i++)
        fa[i]=i;
    return;
}
int findfa(int x)
{   
    return fa[x]==x?x:fa[x]=findfa(fa[x]);
}
void zip(int x,int y)
{
    int fx=findfa(x),fy=findfa(y);
    if(fx!=fy)
    {
        fa[fx]=fy;
        --res;
    }
    return;
}
int main()
{
    scanf("%d%*d", &n);
    init();
    res=n-1;
    for(int i=1;i<=n;i++)
    {
        int cnt,x;
        scanf("%d",&cnt);
        if(cnt&&!Flag)
            Flag=1;
        while(cnt--)
        {
            scanf("%d", &x);
            if(vis[x])
                zip(vis[x], i);
            else vis[x]=i;
        }
    }
    printf("%d",Flag?res:n);
    return 0;
}