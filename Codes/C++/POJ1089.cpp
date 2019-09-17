#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int l,r;
}N[50005];
bool cmp(node a,node b){
	return a.l<b.l;
}
signed main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&N[i].l,&N[i].r);
	int p=1,tmp=1;
	sort(N+1,N+1+n,cmp);
	while(p<=n){
		tmp++;
		while(N[p].r>=N[tmp].l)tmp++;
		printf("%d %d\n",N[p].l,N[tmp-1].r);
		p=tmp;
	}
	return 0;
}
