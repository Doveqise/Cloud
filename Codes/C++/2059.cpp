// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e2+5;
int a[maxn];
double f[maxn][maxn];
signed main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	f[1][1]=1.0;
	for(int i=2;i<=n;i++)
		for(int k=1;k<=m;k++)
		{
			int pt=(a[k]%i)?(a[k]%i):i;
			for(int j=1;j<i;j++)
			{
				pt++;
                if(pt>i)
                    pt=1;
				f[i][pt]+=f[i-1][j]*(double)1.0/(double)m;
			}
		}
	for(int i=1;i<=n;i++)
		printf("%.2lf%% ",f[n][i]*100.0);
	return 0;
}
