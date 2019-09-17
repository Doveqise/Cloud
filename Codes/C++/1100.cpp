#include<bits/stdc++.h>
using namespace std;
long long num[32],ans[32],ansn=0;
long long solve(long long n){
	int ti=0;
	while(n>1){
		if(n%2) num[ti]=1;
		else num[ti]=0;
		n>>=1;
		ti++;}
	num[ti]=1;
	for(int i=0;i<16;i++) ans[i]=num[i+16];
	for(int i=16;i<32;i++) ans[i]=num[i-16];
	for(int i=0;i<32;i++) ansn+=pow(2,i)*ans[i];
	return ansn;
}
int main(){
	long long numn;cin>>numn;
	printf("%lld",solve(numn));
	return 0;
}
