#include<cstdio>
using namespace std;
int a,b,x,y;
int exgcd(int a,int b){
	int tmp;
    if(b==0){return x=1;}
    exgcd(b,a%b);
    tmp=x;x=y;y=tmp-(a/b)*y;
    return x;
}
int main(){
    scanf("%d%d",&a,&b);
    printf("%d",(exgcd(a,b)+b)%b);
    return 0;
}
