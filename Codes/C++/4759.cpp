#include<bits/stdc++.h>
using namespace std;
int t[100000005]={0};
signed main(){
	int T;scanf("%d",&T);
	while(T--){
		int m,he=1,ta=2;scanf("%d",&m);
		for(int i=1;i<=m;i++) t[i]=t[i-1]+i;
		while(ta!=m){
			if(t[ta]-t[he-1]==m){
				printf("%d = ",m);
				for(int j=he;j<=ta;j++){
					printf("%d ",j);
					if(j!=ta)printf("+ ");
				}
				puts("");
				break;
			}
			else if(t[ta]-t[he-1]<m)ta++;
			else if(t[ta]-t[he-1]>m)he++;
		}
		if(ta==m)puts("IMPOSSIBLE");
	}
	return 0;
}