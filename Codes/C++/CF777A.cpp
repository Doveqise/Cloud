#include<bits/stdc++.h>
using namespace std;
int main(){
	int c[3]={0,1,2};
	long long n,x;
    scanf("%lld%lld",&n,&x);
    n%=6;
    for(int i=1;i<=n;i++){
    	if(i%2==0){
    		swap(c[2],c[1]);
    	}
		else{
			swap(c[0],c[1]);
		}
    }
    printf("%d",c[x]);
    return 0;
}
