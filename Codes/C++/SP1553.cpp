#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
const int inf=0x3f3f3f3f;
int n,m,s,l;
bool vis[maxn];
struct point{int dat,l,r;}p[maxn];
struct node{int dat,id;
	bool operator < (node it)const{return dat>it.dat;}
};priority_queue<node>q;
void del(int x){
	p[x].l=p[p[x].l].l;
	p[x].r=p[p[x].r].r;
	p[p[x].l].r=x;
	p[p[x].r].l=x;
}
signed main(){
	int T;scanf("%d",&T);
	while(T--){s=0;
		memset(vis,0,sizeof(vis));
		memset(p,0,sizeof(p));
		while(!q.empty())q.pop();
		scanf("%d%d%d",&n,&m,&l);
		for(int i=1,t;i<n;i++){
			scanf("%d",&t);
			p[i].dat=t-l;l=t;
			p[i].l=i-1;p[i].r=i+1;
			q.push((node){p[i].dat,i});
		}
		p[0].dat=p[n].dat=inf;
		for(int i=1;i<=m;i++){
			while(vis[q.top().id])q.pop();
			node t=q.top();q.pop();s+=t.dat;
			vis[p[t.id].l]=vis[p[t.id].r]=1;
			p[t.id].dat=p[p[t.id].l].dat+p[p[t.id].r].dat-p[t.id].dat;
			q.push((node){p[t.id].dat,t.id});
			del(t.id);
		}
		printf("%d\n",s);
	}
	return 0;
}