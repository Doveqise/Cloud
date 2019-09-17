#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
const int maxm = 1e5+5;
int n,id,now;
struct edge
{
    int val,nxt;
}
ed[maxn<<2];
int hd[maxn],chk[maxn],mat[maxn];
void add(int u,int v)
{
    id++;
    ed[id].val=v;
    ed[id].nxt=hd[u];
    hd[u]=id;
}
bool dfs(int u)
{
    int v;
    for(int k=hd[u];k>0;k=ed[k].nxt)
    {
        v=ed[k].val;
        if(chk[v]!=now)
        {
            chk[v]=now;
            if((mat[v]==-1)||dfs(mat[v]))
            {
                mat[v]=u;
                return 1;
            }
        }
    }
    return 0;
}
signed main()
{
    memset(mat,-1,sizeof(mat));
    scanf("%d",&n);
    for (int i = 1, a, b; i <= n; i++)
    {
        scanf("%d%d", &a, &b);
        add(a, i);
        add(b, i);
    }
        int ans = 0;
        for(int i=1;i<=10000;i++)
        {
            now++;
            if(dfs(i))
                ans++;
            else
                break;
        }
    printf("%d",ans);
    return 0;
}