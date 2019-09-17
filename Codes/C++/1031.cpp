#include<cstdio>
using namespace std;
int dui[105];
int main(){
	int n,ave,times=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",dui+i);
		ave+=dui[i];
	}
	ave/=n;
	for(int i=0;i<n;i++){
		dui[i]-=ave;
		if(!dui[i]) continue;
		dui[i+1]+=dui[i];
		times++;
	}
	printf("%d",times);
	return 0;
}
