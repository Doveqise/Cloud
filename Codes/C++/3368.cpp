#include<bits/stdc++.h>
using namespace std;
int tree[500005],m,n;
int lowbit(int x){return x&-x;}
void add(int x,int k){
	while(x<=n){tree[x]+=k;x+=lowbit(x);} 
}
int search(int x){
	int ans=0;
	while(x){ans+=tree[x];x-=lowbit(x);}
	return ans;
}
signed main(){
	scanf("%d%d",&n,&m);
	int t=0;
	for(int i=1;i<=n;i++){
		int a;scanf("%d",&a);
		add(i,a-t);
		t=a;
	}
	for(int i=1;i<=m;i++){
		int a,b,c,d;
		scanf("%d%d",&a,&b);
		if(a==1){
			scanf("%d%d",&c,&d);
			add(b,d);add(c+1,-d);
		}
		else printf("%d\n",search(b));
	}
	return 0;
} 
