#include<bits/stdc++.h>
using namespace std;
int num[200005];
int main(void){
	register int n,c,ans=0;
	scanf("%d%d",&n,&c);
	for(register int i=0;i<n;++i)scanf("%d",&num[i]);
	sort(num,num+n);
	for(register int i=0;i<n;++i)for(register int j=i;j<n&&!(num[j]-num[i]>c);++j)if(num[j]-num[i]==c)++ans;
	printf("%d",ans);
	return 0;
}
