#include<cstdio>
#include<iostream>
using namespace std;
char lei[105][105];
int ans[105][105];
signed main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>lei[i][j];
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(lei[i][j]=='?'){
				if(i>=1&&lei[i-1][j]=='*')ans[i][j]++;
				if(i>=1&&j>=1&&lei[i-1][j-1]=='*')ans[i][j]++;
				if(i>=1&&j<=m-2&&lei[i-1][j+1]=='*')ans[i][j]++;
				if(i<=n-2&&lei[i+1][j]=='*')ans[i][j]++;
				if(i<=n-2&&j>=1&&lei[i+1][j-1]=='*')ans[i][j]++;
				if(i<=n-2&&j<=m-2&&lei[i+1][j+1]=='*')ans[i][j]++;
				if(j>=1&&lei[i][j-1]=='*')ans[i][j]++;
				if(j<=m-2&&lei[i][j+1]=='*')ans[i][j]++;}
			else ans[i][j]=-1;}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(ans[i][j]==-1)printf("*");
			else printf("%d",ans[i][j]);
		}
		if(n-i-1)printf("\n");
	}
}
 
