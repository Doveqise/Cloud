#include<cstdio>
using namespace std;
signed main(){
	int n,t,m,s=1,h;
	scanf("%d",&n);
	t=n*n;
	h=n;
	while(t){
		scanf("%d",&m);
		t-=m;
		s++;
		for(int i=0;i<m;i++){
			h--;
			printf("%d",s%2);
			if(h==0){
				printf("\n");
				h=n;
			}
		}
	}
	return 0;
}
