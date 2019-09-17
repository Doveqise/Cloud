#include<bits/stdc++.h>
using namespace std; 
const int maxn=1e6+5;
const int lim=1e6;
const int mod=(1e7+19)*43;
const int ms=79;
int n,len=0,p,p1;
int hsh1[maxn],hsh2[maxn],jz[maxn]={1};
char ans[maxn],ch[maxn];
bool check(int x) 
{
	int hs1=((hsh1[p1]-1ll*hsh1[p1-x]*jz[x])%mod+mod)%mod;
	int hs2=hsh2[x];
	return hs1==hs2;
}
signed main() 
{
	scanf("%d",&n);
	for(int i=1;i<=lim;i++)
		jz[i]=1ll*jz[i-1]*ms%mod;
	for(int i=1;i<=n;i++) 
	{
		scanf("%s",ch+1);
		len=strlen(ch+1);
		for(int j=1;j<=len;j++)
			hsh2[j]=(1ll*hsh2[j-1]*ms+ch[j]-'0'+1)%mod;
		for(p=len;p;p--) 
			if(p1>=p&&check(p))
				break;
		for(int j=p+1;j<=len;j++)
		{
			ans[++p1]=ch[j];
			hsh1[p1]=(1ll*hsh1[p1-1]*ms+ch[j]-'0'+1)%mod;
		}
	}
	printf("%s",ans+1);
	return 0;
}
