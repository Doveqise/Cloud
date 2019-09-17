#include<bits/stdc++.h>
using namespace std;
int man[1000];
int main(){
	int n,m,i,j=0,num=0;
	scanf("%d%d",&n,&m);
	if(n==0&&m==0) return 0;
	for(i=1;i<=n;i++) man[i]=1;
	i=1;
	while(num!=n){
		while(i<=m){
			if(j>=n) j-=n;
			j++;
			if(man[j]) i++;
		}
		man[j]=0;
		num++;
		printf("%d ",j);
		i=1;
	}
	for(i=1;i<=n;i++){
		if(man[i]) printf("%d ",i);
		return 0;
	}
}
