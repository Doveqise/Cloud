#include<cstdio>
#include<cstring>
using namespace std;
char num[100];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",num);
		if(num[strlen(num)-1]=='1'||num[strlen(num)-1]=='3'||num[strlen(num)-1]=='5'||num[strlen(num)-1]=='7'||num[strlen(num)-1]=='9') printf("odd\n");
		else printf("even\n");
		memset(num,0,sizeof(num));
	}
	return 0;
} 
