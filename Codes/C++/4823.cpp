#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e3+5;
struct node
{
	int a,b;
	bool operator < (const node y) const
	{
		return a+b==y.a+y.b?b>y.b:a+b<y.a+y.b;
	}
}
r[maxn];
int dp[maxn];
signed main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&r[i].a,&r[i].b);
	int h;
	scanf("%d",&h);
	sort(r+1,r+1+n);
	for(int i=1;i<=n;i++)
	{
		dp[0]+=r[i].a;
		dp[i]=-123456789;	
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j>=1;j--)
			if(dp[j-1]+r[i].b>=h)
				dp[j]=max(dp[j-1]-r[i].a,dp[j]);
	for(int i=n;i>=0;i--)
	{
		if(dp[i]>=0)
		{
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}
