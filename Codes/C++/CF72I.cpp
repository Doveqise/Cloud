#include<cstdio> 
using namespace std;
int a[10],n,s,t,ti;
int main(){
	scanf("%d",&n);t=n;
	 
	while(t>=10){
		a[s]=t%10;
		s++;
		t/=10;}
	a[s]=t;
	
	for(int i=0;i<=s;i++){if(!(n%a[i]))ti++;}
	if(ti==s+1)printf("happier");
	else if(!ti)printf("upset");
	else printf("happy");
	return 0;
}
