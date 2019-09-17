#include<cstdio>
using namespace std;
int main(){
	int n,m,tt,t,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		if(tt+t>m){tt=t;ans++;}
		else tt+=t;
	}
	printf("%d",++ans);
	return 0;
}
