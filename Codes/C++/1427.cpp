#include<cstdio>
using namespace std;
long long num[105]={1},i=0;
int main(){
	while(num[i]!=0){i++;scanf("%lld",num+i);}
	for(int j=100;j>0;j--)if(num[j]) printf("%lld ",num[j]);
	return 0;
}
