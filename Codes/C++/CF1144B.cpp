#include<bits/stdc++.h>
using namespace std;
signed main()
{
	int n;
	priority_queue<int>qj,qo;
	scanf("%d",&n);
	for(int i=1,t;i<=n;i++)
	{
		scanf("%d",&t);
		if(t%2)
			qj.push(t);
		else
			qo.push(t);
	}
	if(abs(qj.size()-qo.size())<=1)
		puts("0");
	else
	{
		int lim=min(qj.size(),qo.size());
		for(int i=1;i<=lim;i++)
			qj.pop(),qo.pop();
		if(!qj.empty())
		{
			qj.pop();
			int ans=0;
			while(!qj.empty())
			{
				ans+=qj.top();
				qj.pop();
			}
			printf("%d\n",ans);
		}
		else
		{
			qo.pop();
			int ans=0;
			while(!qo.empty())
			{
				ans+=qo.top();
				qo.pop();
			}
			printf("%d\n",ans);
		}
	}
}
