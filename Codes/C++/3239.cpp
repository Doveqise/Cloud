#include<bits/stdc++.h>
using namespace std;
const int maxn = 2.3e2+5;
int d[maxn];
double p[maxn],f[maxn][maxn],t[maxn][maxn];
int n,r;
signed main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(p,0,sizeof(p));
        memset(f,0,sizeof(f));
        memset(t,0,sizeof(t));
        memset(d,0,sizeof(d));
        scanf("%d%d",&n,&r);
        for(int i=1;i<=n;i++)
            scanf("%lf%d",&p[i],&d[i]);
        for(int i=1;i<=n;i++)
        {
            t[i][0]=1;
            for(int j=1;j<=200;j++)
                t[i][j]=t[i][j-1]*(1-p[i]);
        }
        f[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            int lim=min(r,i);
            for(int j=0;j<=lim;j++)
            {
                f[i][j]=j?f[i-1][j-1]*(1-t[i][r-j+1]):0;
                f[i][j]+=f[i-1][j]*t[i][r-j];
            }
        }
        double ans=0;
        for(int i=1;i<=n;i++)
        {
            int lim=min(r,i);
            for(int j=0;j<lim;j++)
                ans+=f[i-1][j]*(1-t[i][r-j])*d[i];
        }
        printf("%.10lf\n",ans);
    }
}