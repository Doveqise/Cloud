#include<cstdio>
#include<cstring>
using namespace std;
int tong[100005],ans[100005];
int main(){
	int n,t,T;
	scanf("%d",&T);
	for(int tt=0;tt<T;tt++){
		memset(tong,0,sizeof(tong));
		memset(ans,0,sizeof(ans));
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&t);
			if(!tong[t]){
				ans[i]=t;
				tong[t]=1;
			}
		}
		for(int i=0;i<n;i++){
			if(ans[i]) printf("%d ",ans[i]);
		}
		printf("\n");
	}
	return 0;
} 
