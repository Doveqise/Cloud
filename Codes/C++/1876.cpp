#include<cstdio>
using namespace std;
int main(){
	int n,num,tmp,lenn=1,len=0;
	scanf("%d",&n);
	scanf("%d",&num);
	for(int i=1;i<n;i++){
		scanf("%d",&tmp);
		if(tmp>num){
			num=tmp;
			lenn++;
		}
		else{
		num=tmp;
		lenn=1;
		}
		if(lenn>len) len=lenn;
	}
	printf("%d",len);
	return 0;
} 
