#include<cstdio>
using namespace std;
int main(){
	int a[200];
	int *p;
	p=a;
	*p=10;
	*(p+1)=20;
	p[0]=30;
	p[4]=40;
	for(int i=0;i<10;++i){
		printf("%d ",p[i]);
	}
	printf("\n");
	for(int i=0;i<10;++i){
		printf("%d ",*(p+i));
	}
	return 0;
}
