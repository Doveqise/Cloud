#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int a[10];
char ch[maxn];
signed main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",ch+1);
	for(int i=1;i<=n;i++)
	{
		if(ch[i]=='L')
		{
			for(int j=0;j<=9;j++)
				if(!a[j])
				{
					a[j]=1;
					break;
				}
		}
		else if(ch[i]=='R')
		{
			for(int j=9;j>=0;j--)
				if(!a[j])
				{
					a[j]=1;
					break;
				}
		}
		else
		{
			a[ch[i]-'0']=0;
		}
	}
	for(int i=0;i<=9;i++)
		printf("%d",a[i]);
	return 0;
}
