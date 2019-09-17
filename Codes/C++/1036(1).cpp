#include<cstdio>
using namespace std;
int n,k,ans=0;
int x[30];
bool pd(int num){
	for(int i=2;i<num/2;i++){
		if(!(num%i))return 0;
	}return 1;
}
int jh(int syn,int tot,int now,int n){
	if(syn==0) return pd(tot);
	int jia=0;
	for(int i=now;i<=n;i++){
		jia+=jh(syn-1,tot+x[i],i+1,n);
	}
	return jia;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",x+i);
	printf("%d",jh(k,0,1,n));
	return 0;
} 
