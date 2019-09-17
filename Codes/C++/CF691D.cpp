#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
int a[maxn],fa[maxn],siz[maxn];
vector<int>num[maxn];
int findfa(int x)
{
    return fa[x]==x?x:fa[x]=findfa(fa[x]);
}
signed main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[fa[i]=i]);
    for(int i=1,x,y;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        fa[findfa(x)]=findfa(y);
    }
    for(int i=1;i<=n;i++)
        num[findfa(i)].push_back(a[i]);
    for(int i=1;i<=n;i++)
        sort(num[i].begin(),num[i].end());
    for(int i=1;i<=n;i++)
    {
        printf("%d ",num[findfa(i)][num[findfa(i)].size()-1]);
        num[findfa(i)].pop_back();
    }
}