#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e3+5;
bool mat[maxn][maxn];
int vis[maxn];
bool con(int a,int b)
{
    return mat[a][b]||mat[b][a];
}
void add(int a,int b)
{
    mat[a][b]=mat[b][a]=1;
}
signed main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1,a,b;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        add(a,b);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
            for(int j=i+1;j<=n;j++)
                if(!vis[j]&&(!con(i,j)))
                {
                    vis[i]=vis[j]=1;
                    break;
                }
    }
    int tot=0;
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            printf("%d ",i);
            tot++;
            if(tot*3==n)
                return 0;
        }
    return 0;
}