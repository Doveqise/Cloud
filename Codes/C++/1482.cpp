#include<bits/stdc++.h>
using namespace std;
int main(){
	int a1,a2,b1,b2,n;
	scanf("%d/%d",&a1,&a2);
	scanf("%d/%d",&b1,&b2);
	a1*=b1;a2*=b2;
	n=__gcd(a1,a2);
	a1/=n;a2/=n;
	printf("%d %d",a2,a1);
	return 0;
}
