#include<bits/stdc++.h>
using namespace std;
int f[100005],k,n,MOD=100003;
int dp(int x){
	if(f[x]!=-1) return f[x];
	else{int p=0;for(int i=1;i<=max(min(k,x),1);i++)p=(p+dp(x-i)%MOD);f[x]=p;return f[x];}}
signed main(){
	memset(f,-1,sizeof(f));f[0]=1;
	scanf("%d%d",&n,&k);
	printf("%d",dp(n)%MOD);
	return 0;} 
