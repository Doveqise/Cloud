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
int search_sum(int x,int y){
	return search(y)-search(x-1);
}
signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int a;scanf("%d",&a);
		add(i,a);
	}
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(a==1)add(b,c);
		else printf("%d\n",search_sum(b,c));
	}
	return 0;
} 
