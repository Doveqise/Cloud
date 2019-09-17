#include<bits/stdc++.h>
using namespace std;
int dp[2][105],n,t[105],maxi=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",t+i);
	for(int i=n;i>=1;i--) for(int j=i+1;j<=n;j++) if(t[i]>t[j]) dp[0][i]=max(dp[0][i],dp[0][j]+1);
	for(int i=1;i<=n;i++) for(int j=i-1;j>=1;j--) if(t[i]>t[j]) dp[1][i]=max(dp[1][i],dp[1][j]+1);
	for(int i=1;i<=n;i++) maxi=max(maxi,dp[0][i]+dp[1][i]);
	printf("%d",n-maxi-1);
	return 0;
} 
