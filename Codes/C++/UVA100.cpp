#include<bits/stdc++.h>
using namespace std;
int solve(int n){
	int num=1;
	if(n==1)return num;
	if(n%2)num+=solve(n*3+1);
	else num+=solve(n/2);
	return num;
}
signed main(){
	int n,m,n1,m1;
	while(scanf("%d%d",&n,&m)==2){
		n1=n;m1=m;
		if(n>m)swap(n,m);int ans=0;
		for(int i=n;i<=m;i++){
			ans=max(solve(i),ans);
		}
		printf("%d %d %d\n",n1,m1,ans);
	}
	return 0;
}
