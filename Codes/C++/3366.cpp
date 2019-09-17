/*#include<bits/stdc++.h>
#define maxn 5005
#define maxm 200005
#define inf 111111111
using namespace std;
struct edge{
	int st;
	int en;
	int we;
}e[maxm<<1];
int head[maxn],dis[maxn],cnt,n,m,tot,now=1,ans;
bool vis[maxn];
void add(int u,int v,int wei){
	e[++cnt].st=v;
	e[cnt].we=wei;
	e[cnt].en=head[u];
	head[u]=cnt;
}
void in(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<=m;++i){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w),add(v,u,w);
	}
}
int prim(){
	for(int i=2;i<=n;++i){
		dis[i]=inf;
	}
	for(int i=head[1];i;i=e[i].en){
		dis[e[i].st]=min(dis[e[i].st],e[i].we);
	}
	while(++tot<n){
		int minn=inf;
		vis[now]=1;
		for(int i=1;i<=n;++i){
			if(!vis[i]&&minn>dis[i]){
				minn=dis[i];
				now=i;
			}
		}
		ans+=minn;
		for(int i=head[now];i;i=e[i].en){
			int v=e[i].st;
			if(dis[v]>e[i].we&&!vis[v]){
				dis[v]=e[i].we;
			}
		}
	}
	return ans;
}
signed main(){
	in();
	printf("%d",prim());
	return 0;
} 
*/
#include<bits/stdc++.h>
#define maxn 5005
#define maxm 200005
#define inf 111111111
using namespace std;
struct edge{
	int st;
	int en;
	int we;
}e[maxm];
int fa[maxn],n,m,ans,eu,ev,cnt;
bool cmp(edge a,edge b){return a.we<b.we;}
int find(int x){
	while(x!=fa[x])x=fa[x]=fa[fa[x]];
	return x;
}
void kruskal(){
	sort(e,e+m,cmp);
	for(int i=0;i<m;i++){
		eu=find(e[i].st),ev=find(e[i].en);
		if(eu==ev) continue;
		ans+=e[i].we;
		fa[ev]=eu;
		if(++cnt==n-1) break;
	}
}
signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=0;i<m;i++) scanf("%d%d%d",&e[i].st,&e[i].en,&e[i].we);
	kruskal();
	printf("%d",ans);
	return 0;
}
