#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int fa[maxn],ans=123456789;
int findfa(int x,int &cnt){cnt++;return fa[x]==x?x:findfa(fa[x],cnt);}
signed main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1,cnt,k;i<=n;i++){
		cnt=0;scanf("%d",&k);
		if(findfa(k,cnt)==i)ans=ans<cnt?ans:cnt;
		else fa[i]=k;
	}
	printf("%d",ans);
	return 0;
}