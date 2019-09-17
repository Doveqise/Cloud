#include<bits/stdc++.h>
using namespace std;
int a[10000007],b[10000007];
signed main(){
	int n,tot=0,toto=0;scanf("%d",&n);
	double ans;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	for(int i=0;i<n;i++){
		tot+=3*a[i]-2*b[i];
		toto+=a[i]-b[i];
	}
	ans=(double)tot/(double)toto;
	printf("%0.6lf",ans);
	return 0;
}
