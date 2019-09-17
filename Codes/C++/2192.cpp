#include<cstdio>
using namespace std;
int main(){
	int n,w=0,t;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		if(t==5) w++;
	}
	t=n-w;
	if(!(w%9)){
		while(w>0){printf("5");w--;}
		while(t>0){printf("0");t--;}
	}
	else if(w>=9){
		while(w>9){printf("555555555");w-=9;}
		while(t>0){printf("0");t--;}
	}
	else if(t) printf("0");
	else printf("-1");
	return 0;
}
