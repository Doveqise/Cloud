#include<bits/stdc++.h>
using namespace std;
int maxn,n,S[50];
bool find(int step,int now){
	if(step>maxn||now<=0||now<<(maxn-step)<n) return 0;
	if(now==n||now<<(maxn-step)==n) return 1;
	S[step]=now;
	for(int i=0;i<=step;i++){
		if(find(step+1,now+S[i]))return 1;
		if(find(step+1,now-S[i]))return 1;}
	return 0;
}
signed main(){
	while(scanf("%d",&n)&&n){
	for(maxn=0;!find(0,1);maxn++);
	printf("%d\n",maxn);}
}
