#include<cstdio>
using namespace std;
int a[1005],f[1005][1005];
int main(){
	int m,n;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			if(j==a[i]) f[i][j]=f[i-1][j]+1;
			if(j<a[i]) f[i][j]=f[i-1][j];
			if(j>a[i]) f[i][j]=f[i-1][j-a[i]]+f[i-1][j];
		}
	}
	printf("%d",f[n][m]);
	return 0;
}
