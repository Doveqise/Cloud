#include<bits/stdc++.h>
using namespace std;
int n,l,g;
void solve(int w,int h){
	if(l>min(w,h)){puts("Too Young");return;}
	if(g>=max(w,h)){puts(w==h?"Sometimes Naive":"Too Simple");return;}
	solve(w>>1,h>>1);
}
signed main(){
	scanf("%d%d%d",&n,&l,&g);
	while(n--){int w,h;scanf("%d%d",&w,&h);solve(w,h);}
	return 0;
}