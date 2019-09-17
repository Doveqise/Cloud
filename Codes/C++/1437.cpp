#include<bits/stdc++.h>
using namespace std;
const int maxn = 50+5;
const int maxm = 1250;
int val[maxn][maxn],f[maxn][maxm],maxl[maxn][maxm];
int n,m,s,ans;
signed main()
{
    scanf("%d%d",&n,&m);
    for(int j=1;j<=n;j++)
        for(int i=n;i>=j;i--)
        {
            scanf("%d",&s);
            val[i][j]=val[i][j-1]+s;
        }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j>=1;j--)
            for(int k=min(j+i*(i-1)/2,m);k>=j*(j+1)/2;k--)
            {
                f[j][k]=maxl[j-1][k-j]+val[i][j];
                maxl[j][k]=max(maxl[j+1][k],f[j][k]);
                ans=max(ans,f[j][k]);
            }
        for(int k=i*(i-1)/2+1;k<=i*(i+1)/2;k++)
            for(int j=k-i*(i-1)/2-1;j>=0;j--)
                maxl[j][k]=max(maxl[j+1][k],f[j][k]);
        for(int k=1;k<=i*(i+1)/2;k++)
            maxl[0][k]=max(maxl[1][k],maxl[0][k]);
    }
    printf("%d",ans);
    return 0;
}