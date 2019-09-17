#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e2+5;
int T,n,m,M,vis[maxn];
long long s[maxn],f[maxn][maxn],C[maxn][maxn];
bool flg=0;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        memset(s,0,sizeof(s));
        memset(f,0,sizeof(f));
        memset(C,0,sizeof(C));
        flg=0;
        scanf("%d%d%d",&n,&m,&M);
        for(int i=1,x,y;i<=m;++i)
        {
            scanf("%d%d",&x,&y);
            vis[y]+=1;
        }
        for(int i=n;i>=1;--i)
        {
            s[i]=s[i+1]+vis[i];
            if(s[i]>n-i+1)
                flg=1,puts("NO");
        }
        if(flg) 
            continue;
        for(int i=0;i<=n;++i)
        {
            C[i][0]=C[i][i]=1;
            for(int j=1;j<i;++j)
              C[i][j]=(C[i-1][j-1]+C[i-1][j])%M;
        }
        f[n+1][0]=1;
        for(int i=1;i<=n;++i) 
            f[n+1][i]=0;
        for(int i=n;i>=1;--i)
            for(int j=0;j<=n-s[i]-i+1;++j)
                for(int k=0;k<=j;++k)
                    f[i][j]=(f[i][j]+f[i+1][j-k]*C[j][k])%M;
        printf("YES %d\n",f[1][n-m]);
    }
}