#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9+7;
struct node
{
    int x,y;
}
a[51];
struct matrix
{
    int l,r,u,d;
    bool flg;
}
p[5];
int ans=inf;
int n,m;
bool judge(matrix a,matrix b)
{
    return (b.l>=a.l&&b.l<=a.r&&b.u>=a.d&&b.u<=a.u)||(b.l>=a.l&&b.l<=a.r&&b.d>=a.d&&b.u<=a.u)||(b.r>=a.l&&b.r<=a.r&&b.u>=a.d&&b.u<=a.u)||(b.r>=a.l&&b.r<=a.r&&b.d>=a.d&&b.d<=a.u);
}
void dfs(int now)
{
    int val=0;
    for(int i=1;i<=m;i++)
    {
        if(p[i].flg)
            for(int j=i+1;j<=m;j++)
                if(p[i].flg&&judge(p[i],p[j])) 
                    return;
        val+=(p[i].r-p[i].l)*(p[i].u-p[i].d);
    }
    if(val>=ans)
        return;
    if(now>n)
    {
        ans=val;
        return;
    }
    for(int i=1;i<=m;i++)
    {
        matrix tmp=p[i];
        if(!p[i].flg)
        {
            p[i].flg^=1;
            p[i].l=p[i].r=a[now].x;
            p[i].u=p[i].d=a[now].y;
            dfs(now+1);
            p[i]=tmp;
            return;
        }
        else
        {
            p[i].r=max(p[i].r,a[now].x);
            p[i].l=min(p[i].l,a[now].x);
            p[i].u=max(p[i].u,a[now].y);
            p[i].d=min(p[i].d,a[now].y);
            dfs(now+1);
            p[i]=tmp;
        }
    }
}
signed main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
    dfs(1);
    printf("%d",ans);
    return 0;
}