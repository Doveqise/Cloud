#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e2+5;
int h[maxn];
signed main()
{
	int t;
	scanf("%d",&t);
	for(int ti=1;ti<=t;ti++)
	{
		memset(h,0,sizeof(h));
		int n,m,k,flg=0;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&h[i]);
		for(int i=1;i<n;i++)
		{
			if(h[i]>=max(h[i+1]-k,0))
			{
				m+=h[i]-max(h[i+1]-k,0);
				continue;
			}
			else if(h[i+1]-k>h[i]+m)
			{
				puts("NO");
				flg=1;
				break;
			}
			else
			{
				m-=h[i+1]-h[i]-k;
				continue;
			}
		}
		if(flg)
			continue;
		else
			puts("YES");
	}
}
