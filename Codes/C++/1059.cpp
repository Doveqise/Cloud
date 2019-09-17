#include<cstdio>
#include<algorithm>
using namespace std;
int gcd(int a,int b){
	if(a<b) swap(a,b);
	if(b==0) return a;
	else return gcd(a,a%b);
}
int main(){
	int x,y,ans;
	scanf("%d%d",&x,&y);
	for(int i=x;i<=y;i+=x){
		if(gcd(i,x*y/i)==x) ans++;
	}
	printf("%d",ans*2);
	return 0;
}
