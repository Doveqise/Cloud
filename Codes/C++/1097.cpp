#include<bits/stdc++.h>
using namespace std;
int num[200005];
int main(){
	int n,ti=1;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&num[i]);
	sort(num,num+n);
	for(int i=0;i<n;i++){
		if(num[i]!=num[i+1]){
		printf("%d %d\n",num[i],ti);
		ti=1;}
		if(num[i]==num[i+1])ti++;
	}
	return 0;
}
