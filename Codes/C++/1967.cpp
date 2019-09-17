#include<bits/stdc++.h>
using namespace std; 
const int maxn=10077,inf=0x3f3f3f3f; 
struct E1{int x,y,dis;}e1[50005]; 
struct E2{int to,next,w;}e2[100005]; 
int cnt,n,m,li[maxn],deep[maxn],f[maxn],fa[maxn][21],w[maxn][21]; 
bool b[maxn]; 
void adde(int from, int to, int w){ 
	e2[++cnt].next=li[from];e2[cnt].to=to;e2[cnt].w=w; 
	li[from]=cnt;return;
} 
bool CMP(E1 x,E1 y){return x.dis>y.dis; } 
int find(int x){if(f[x]!=x) f[x]=find(f[x]);return f[x];} 
void kruskal(){ 
	sort(e1+1,e1+m+1,CMP); 
	for(int i=1;i<=n;i++) f[i]=i; 
	for(int i=1;i<=m;i++) if(find(e1[i].x)!=find(e1[i].y)) { 
		f[find(e1[i].x)]=find(e1[i].y); 
		adde(e1[i].x, e1[i].y, e1[i].dis);adde(e1[i].y, e1[i].x, e1[i].dis); 
	}
	return; 
} 
void dfs(int node) { 
	b[node]=true; 
	for(int i=li[node];i;i=e2[i].next) { 
	int to=e2[i].to; 
	if(b[to]) continue; 
	deep[to]=deep[node]+1;fa[to][0]=node;w[to][0]=e2[i].w; 
	dfs(to);} 
	return; 
} 
int lca(int x, int y) { 
	if(find(x)!=find(y)) return -1; 
	int ans=inf; 
	if(deep[x]>deep[y]) swap(x,y); 
	for(int i=20; i>=0; i--) if(deep[fa[y][i]]>=deep[x]) { 
		ans=min(ans, w[y][i]);y=fa[y][i]; 
	} 
	if(x==y) return ans; 
	for(int i=20; i>=0; i--) if(fa[x][i]!=fa[y][i]) { 
		ans=min(ans, min(w[x][i],w[y][i])); 
		x=fa[x][i];y=fa[y][i];} 
	ans=min(ans,min(w[x][0],w[y][0])); 
	return ans; 
} 
int main() { 
	int x,y,z,q;scanf("%d%d",&n,&m); 
	for(int i=1;i<=m;i++) {scanf("%d%d%d",&x,&y,&z); e1[i].x=x; e1[i].y=y; e1[i].dis=z; } 
	kruskal(); 
	for(int i=1;i<=n;i++) if(!b[i]) { deep[i]=1; dfs(i); fa[i][0]=i; w[i][0]=inf; } 
	for(int i=1;i<=20;i++) for(int j=1; j<=n; j++) { 
		fa[j][i]=fa[fa[j][i-1]][i-1];w[j][i]=min(w[j][i-1], w[fa[j][i-1]][i-1]);} 
	scanf("%d",&q); 
	for(int i=1; i<=q; i++){scanf("%d%d",&x,&y); printf("%d\n",lca(x,y)); } 
	return 0; 
} 
