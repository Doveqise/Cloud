#include<bits/stdc++.h>
using namespace std;
signed main(){
	int t;scanf("%d",&t);
	while(t--){
		int l,r;scanf("%d%d",&l,&r);
		printf("%d\n",(((l+r)%18)*((r-l+1)%18)/2)%9);}
	return 0;
}
