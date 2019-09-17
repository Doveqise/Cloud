#include<bits/stdc++.h>
using namespace std;
const int maxn = 500;
struct dbd
{
	int id,num;
	int hm[maxn],nowh;
	bool operator < (const dbd b) const
	{
		return num==b.num?id<b.id:num>b.num;
	}
}
db[maxn];
struct czc
{
	int id,num,nowr;
	bool operator < (const czc b) const
	{
		return num==b.num?id<b.id:num>b.num;
	}
}
cz[maxn];
signed main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		scanf("%d",&db[db[i].id=i].num);
	for(int i=1;i<=n;i++)
		scanf("%d",&cz[cz[i].id=i].num);
	sort(db+1,db+1+m);
	sort(cz+1,cz+1+n);
	for(int i=1;i<=m;i++)
	{
		int nowt=1;
		while(nowt<=n)
		{
			if(!db[i].num)
				break;
			if(!cz[nowt].num)
			{
				nowt++;
				continue;
			}
			db[i].num--;
			db[i].hm[db[i].nowh]=cz[nowt].id;
			cz[nowt].num--;
			db[i].nowh++;
			nowt++;
		}
		if(db[i].num)
		{
			puts("0");
			return 0;
		}
	}
	sort(db+1,db+1+m);
	printf("1\n");
	for(int i=1;i<=m;i++)
	{
		int j=0;
		while(db[i].hm[j])
		{
			printf("%d ",db[i].hm[j]);
			j++;
		}
		puts("");
	}
}
