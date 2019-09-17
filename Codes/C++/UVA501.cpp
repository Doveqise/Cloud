#include<bits/stdc++.h>
using namespace std;
int ADD[30005];
vector<int>Array;
vector<int>::iterator it;
int cnt;
void add()
{
	it=lower_bound(Array.begin(),Array.end(),ADD[cnt]);
	if(it!=Array.end())
		Array.insert(it,ADD[cnt++]);
	else
		Array.push_back(ADD[cnt++]);
	return;
}
void get(int i)
{
	printf("%d\n",Array[i]);
	return;
}
signed main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		memset(ADD,0,sizeof(ADD));
		Array.clear();
		cnt=0;
		int m,n;
		scanf("%d%d",&m,&n);
		for(int i=0;i<m;i++)
		{
			scanf("%d",&ADD[i]);
		}
		for(int i=0;i<n;i++)
		{
			int t;
			scanf("%d",&t);
			while(cnt<t)
				add();
			get(i);
		}
		if(T)puts("");
	}
	return 0;
}