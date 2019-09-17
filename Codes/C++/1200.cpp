#include<cstdio>
#include<cstring>
using namespace std;
char ufo[6];
char hx[6];
int main(){
	int u=1,h=1;
	scanf("%s",ufo);
	int len=strlen(ufo);
	for(int i=0;i<len;i++){
		u*=ufo[i]-'A'+1;
	}
	u%=47;
	scanf("%s",hx);
	int leng=strlen(hx);
	for(int i=0;i<leng;i++){
		h*=hx[i]-'A'+1;
	}
	h%=47;
	if(u==h){
		printf("GO");
	}else{
		printf("STAY");
	}
	return 0;
}