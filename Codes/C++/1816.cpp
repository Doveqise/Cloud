#include<bits/stdc++.h>
using namespace std;
struct form{
	int num,rank;
}tong[100005];
bool cmp(form a,form b){
	return a.num<b.num;
}
signed main(){
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++){
		scanf("%d",&tong[i].num);
		tong[i].rank=i+1;
	}
	sort(tong,tong+m,cmp);
	for(int i=0;i<n;i++){
		int left,right;
		scanf("%d%d",&left,&right);
		for(int j=0;j<m;j++) if(tong[j].rank>=left&&tong[j].rank<=right){printf("%d ",tong[j].num);break;}
	}
	return 0;
}
