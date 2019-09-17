#include<bits/stdc++.h>
using namespace std;
unsigned long long int a[10];
signed main(){
	int T,k;scanf("%d%d",&T,&k);
	if(k==3){
		while(T--){
			memset(a,0,sizeof(a));
			unsigned long long int tot=1;
			for(int i=1;i<=k*(k-1);i++){
				scanf("%llu",&a[i]);tot*=a[i];
			}
			if(k==3)tot=pow(tot,1.0 / 2);
			if(k==4)tot=pow(tot,1.0 / 3);
			for(int i=1;i<=k*(k-1)/2;i++){
				printf("%llu ",tot/a[i]/a[i+k*(k-1)/2]);
			}
			puts("");
		}
	}
	else if(k==2){
		while(T--){
			int a,b;scanf("%d%d",&a,&b);
			printf("%d %d\n",a,b);
		}
	}
	return 0;
}