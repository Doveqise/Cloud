#include<bits/stdc++.h>
const int maxn = 1e2+5;
int sqr(int a){return a*a;}
int a[maxn][maxn];
int main(){
	int n,m;
	scanf("%d",&n);
	m=(n*(n+2)+(n&1)-2)/2;
    for(int i=1;i<=m;i++)
    	for(int j=1,x;j<=n;j++)
    		if(!a[j][a[j][0]]||sqr(int(sqrt(a[j][a[j][0]]+i)))==a[j][a[j][0]]+i)
				{a[j][++a[j][0]]=i;break;}
    printf("%d\n",m);
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=a[i][0];j++)
			printf("%d ",a[i][j]);
    return 0;
}
