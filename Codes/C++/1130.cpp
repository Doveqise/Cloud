#include<bits/stdc++.h>
using namespace std;
int a[2005][2005],ans=99999999;
int main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)for(int j=0;j<n;j++)scanf("%d",&a[i][j]);
	for(int j=n-2;j>=0;j--)for(int i=0;i<m;i++){if(i==m-1)a[i][j]+=min(a[i][j+1],a[0][j+1]);else a[i][j]+=min(a[i][j+1],a[i+1][j+1]);}
	for(int i=0;i<m;i++)ans=min(a[i][0],ans);
	printf("%d",ans);
	return 0;
}
