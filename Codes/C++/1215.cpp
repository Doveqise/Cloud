#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e2+5;
int A,B,C;
int vis[maxn][maxn][maxn],ans[maxn];
void dfs(int a,int b,int c)
{
	if(vis[a][b][c])
		return;
	vis[a][b][c]=1;
	if(a<A&&b)
	{
		if(b<=A-a)
			dfs(a+b,0,c);
		else
			dfs(A,a+b-A,c);
	}
	if(b<B&&a)
	{
		if(a<=B-b)
			dfs(0,a+b,c);
		else
			dfs(a+b-B,B,c);
	}
	if(a<A&&c)
	{
		if(c<=A-a)
			dfs(a+c,b,0);
		else
			dfs(A,b,a+c-A);
	}
	if(b<B&&c)
	{
		if(c<=B-b)
			dfs(a,b+c,0);
		else
			dfs(a,B,b+c-B);
	}
	if(c<C&&a)
	{
		if(a<=C-c)
			dfs(0,b,a+c);
		else
			dfs(a+c-C,b,C);
	}
	if(c<C&&b)
	{
		if(b<=C-c)
			dfs(a,0,b+c);
		else
		dfs(a,b+c-C,C);
	}
}
signed main()
{
	scanf("%d%d%d",&A,&B,&C);
	dfs(0,0,C);
	for(int i=0;i<=B;i++)
		for(int j=0;j<=C;j++)
			if(vis[0][i][j])
				ans[j]=1;
	for(int i=0;i<=C;i++)
		if(ans[i])
			printf("%d ",i);
	return 0;
}
