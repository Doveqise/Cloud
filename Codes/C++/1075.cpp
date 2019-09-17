#include<cstdio>
#include<cmath>
using namespace std;
int prime(int n){
	for(int i=2;i<=sqrt(n);i++){
		if(!(n%i)) return 0;
	}
	return 1;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=2;i<sqrt(n);i++){
		if(prime(i)&&!(n%i)){
			printf("%d",n/i);
			return 0;
		}
	}
}
