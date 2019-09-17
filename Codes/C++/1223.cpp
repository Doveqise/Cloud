#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	int n,ti;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",a[i]);
	sort(a,a+n);
	for(int i=0;i<n;i++) ti+=(n-i)*a[i];
	(double)ti/=n;
	printf("%lf",ti);
	return 0;
} 
