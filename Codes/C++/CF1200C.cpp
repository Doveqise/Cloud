#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
signed main()
{
	int n,m,q;
	scanf("%lld%lld%lld",&n,&m,&q);
	int g=gcd(n,m);
	for(int i=1,sx,sy,ex,ey;i<=q;i++)
	{
		scanf("%lld%lld%lld%lld",&sx,&sy,&ex,&ey);
		if(sx==1) sy=(sy-1)/(n/g);
		else sy=(sy-1)/(m/g);
		if(ex==1) ey=(ey-1)/(n/g);
		else ey=(ey-1)/(m/g);
		puts(sy==ey?"YES":"NO");
	}
}
