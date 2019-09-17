#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;//Ð¡¸ù¶Ñ
}
signed main(){
	vector<int>h;
	int n,t;
	scanf("%d",&n);
	make_heap(h.begin(),h.end(),cmp);
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		if(t==1){
			scanf("%d",&t);
			h.push_back(t);
			push_heap(h.begin(),h.end(),cmp);
		}
		else if(t==2) printf("%d\n",h[0]);
		else {
			pop_heap(h.begin(),h.end(),cmp);
			h.pop_back();
		}
	}
	return 0;
}
