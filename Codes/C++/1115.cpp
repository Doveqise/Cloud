#include<cstdio>
using namespace std;
int main(){
	int n,j,sum,ans;   
    scanf("%d%d",&n,&ans);
	sum=ans;
    while(--n){
		scanf("%d",&j);
		if(sum<0) sum=0;
		sum+=j;
		if(sum>ans) ans=sum;
	} 
	printf("%d",ans);
    return 0;
}
