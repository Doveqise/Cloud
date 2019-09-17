#include<cstdio>
#include<cstring>
using namespace std;
char a[1005];
signed main(){
	int m,low;
	scanf("%d%s",&m,a);
	int len=strlen(a);
	for(int i=len-1;;i--){
		if(a[i]!='0'){
			low=i;
			break;
		}
	}
	for(int i=0;i<len;i++){
		if(a[i]!='0'){
			printf("%d*%d^%d",a[i]-48,m,len-i-1);
			if(i<low) printf("+");
		}
	}
	return 0;
} 
