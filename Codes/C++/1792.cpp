#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m,s;
bool vis[maxn];
struct point{int dat,l,r;}p[maxn];
struct node{int dat,id;
	bool operator < (node it)const{return dat<it.dat;}
};priority_queue<node>q;
void del(int x){
	p[x].l=p[p[x].l].l;
	p[x].r=p[p[x].r].r;
	p[p[x].l].r=x;
	p[p[x].r].l=x;
}
signed main(){
	scanf("%d%d",&n,&m);
	if(n<2*m){puts("Error!");return 0;}
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i].dat);
		p[i].l=i-1;p[i].r=i+1;
		q.push((node){p[i].dat,i});
	}
	p[1].l=n;p[n].r=1;
	for(int i=1;i<=m;i++){
		while(vis[q.top().id])q.pop();
		node t=q.top();q.pop();s+=t.dat;
		vis[p[t.id].l]=vis[p[t.id].r]=1;
		p[t.id].dat=p[p[t.id].l].dat+p[p[t.id].r].dat-p[t.id].dat;
		q.push((node){p[t.id].dat,t.id});
		del(t.id);
	}
	printf("%d\n",s);
	return 0;
}