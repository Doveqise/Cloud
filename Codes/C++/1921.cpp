#include<bits/stdc++.h>
const int maxm = 1e3+5;
const int maxn = 5e1+5;
const int eps = 1e-6;
double a[maxn][maxn],b[maxn][maxn];
double pi[maxn],dp[maxm][maxm];
int O[maxm];
//bool equal(double t,double k)
//{
//	return fabs(t-k)<=eps;
//}
bool operator == (const double &a,const int &b)
{
	return fabs(a-b)<=eps;
}
signed main()
{
	int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++)
        scanf("%lf",&pi[i]);
    for(int i=1;i<=n;i++)
        for(int j=0;j<q;j++)
            scanf("%lf",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%lf",&b[i][j]);
    for(int i=1;i<=m;i++)
        scanf("%d",&O[i]);
    for(int i=1;i<=n;i++)
        dp[1][i]=pi[i]*a[i][O[1]];
    for(int i=1;i<m;i++)
        for(int j=1;j<=n;j++)
        {
            if((dp[i][j]==0)) 
				continue;
            for(int k=1;k<=n;k++)
                dp[i+1][k]+=dp[i][j]*a[k][O[i+1]]*b[j][k];
        }
    double ans=0;
    for(int i=1;i<=n;i++)
        ans+=dp[m][i];
    printf("%.4lf",ans);
    return 0;
}
