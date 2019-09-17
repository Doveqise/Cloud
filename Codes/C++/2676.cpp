#include<cstdio>
#include<algorithm>
using namespace std;
int h[20005];
int main(){
	int n=0,b=0,s=0,ans=0,p=0;
	scanf("%d%d",&n,&b);
	for(int i=0;i<n;i++){
		scanf("%d",h+i);
	}
	sort(h,h+n);
	p=n;
	while(s<b){
		s+=h[p-1];
		ans++;
		p--;
	}
	printf("%d",ans);
	return 0;
} 
