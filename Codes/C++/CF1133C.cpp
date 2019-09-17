#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int a[maxn];
signed main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int ans=0,j=2;
	for(int i=1;i<=n;i++)
	{
		while(a[j]-a[i]<=5&&j<=n)
			j++;
		ans=max(ans,j-i);
	}
	printf("%d\n",ans);
	return 0;
}
