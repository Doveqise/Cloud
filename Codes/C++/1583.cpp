#include<bits/stdc++.h>
using namespace std;
struct man{
	int weight,rank;
}mm[20005];
int E[11];
bool cmp(man a,man b){
	if(a.weight!=b.weight)return a.weight>b.weight;
	else return a.rank<b.rank;
}
signed main(){
	int n,k;scanf("%d%d",&n,&k);
	for(int i=1;i<=10;i++){
		scanf("%d",&E[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&mm[i].weight);
		mm[i].rank=i;
	}
	sort(mm+1,mm+n+1,cmp);
	for(int i=1;i<=n;i++){
		mm[i].weight+=E[(i-1)%10+1];
	}
	sort(mm+1,mm+n+1,cmp);
	for(int i=1;i<=k;i++){
		printf("%d ",mm[i].rank);
	}
	return 0;
}
