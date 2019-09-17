#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int a[maxn<<1];
signed main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i+n]=a[i];
	}
	int ans=0,nowl=0,lim=n<<1;
	for(int i=1;i<=lim;i++)
	{
		if(a[i])
			nowl++;
		if(!a[i])
		{
			ans=max(ans,nowl);
			nowl=0;
		}
	}
	printf("%d\n",ans);
	return 0;
}
