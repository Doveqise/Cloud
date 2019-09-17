#include<bits/stdc++.h>
using namespace std;
int a[105],ans[105];
signed main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<n;i++)for(int j=0;j<i;j++)if(a[j]<a[i])ans[i]++;
	for(int i=0;i<n;i++)printf("%d ",ans[i]);
	return 0;
}
