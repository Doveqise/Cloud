#include<cstdio>
#include<algorithm>
using namespace std;
struct num{
	int value;
}A,B,C;
signed main(){
	int a[10];
	char c[10],hc;
	scanf("%d%d%d%c%c%c%c",a+1,a+2,a+3,&hc,c+1,c+2,c+3);
	sort(a+1,a+4);
	A.value=a[1];B.value=a[2];C.value=a[3];
	for(int i=1;i<=3;i++){
		switch(c[i]){
			case'A':printf("%d",A.value);break;
			case'B':printf("%d",B.value);break;
			case'C':printf("%d",C.value);break;
		}
		if(i!=3)printf(" ");
	}
	return 0;
}
