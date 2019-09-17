#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 3e5+5;
struct node
{
	int bt,len;
	bool operator < (const node b) const
	{
		return len>b.len;
	}
}
a[maxn];
bool cmp(node a,node b)
{
	return a.bt>b.bt;
}
signed main()
{
	int n,k,nowlen=0,ans=0;
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&a[i].len,&a[i].bt);
	sort(a+1,a+1+n,cmp);
	priority_queue<node>q;
	for(int i=1;i<=n;i++)
	{
		nowlen+=a[i].len;
		q.push(a[i]);
		if(q.size()>k)
		{
			nowlen-=q.top().len;	
			q.pop();
		}
		ans=max(ans,nowlen*a[i].bt);
	}
	printf("%lld\n",ans);
	return 0;
}
