#include<stdio.h>
#include<stdlib.h>
int cmp(const void * a,const void * b){
	int * pa=(int *)a;
	int * pb=(int *)b;
	return (*pa)-(*pb);
}
int main(){
	int a[10]={5,6,4,3,7,0,8,9,2,1};
	qsort(a,10,sizeof(int),cmp);
	for(int i=0;i<10;i++)printf("%d",a[i]);
	getchar();
	return 0;
}