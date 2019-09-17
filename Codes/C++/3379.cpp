#include<bits/stdc++.h>
using namespace std;
const int Maxn=500005,Maxm=500005;
int fa[Maxn][25],dep[Maxn],lo[Maxn];
int tot,n,m,s;
vector<int>ed[Maxm];//edge
void add_ed(int x,int y){ed[x].push_back(y);}
void find_fa(int a,int fat){
	dep[a]=dep[fat]+1;
	fa[a][0]=fat;
	for(int i=1;(1<<i)<=dep[a];i++)
		fa[a][i]=fa[fa[a][i-1]][i-1];//obviously
	for(int i=0;i<(int)ed[a].size();i++)
		if(ed[a][i]!=fat) find_fa(ed[a][i],a);//recurrence
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);//let dep[u]>dep[v]
	while(dep[x]!=dep[y])x=fa[x][lo[dep[x]-dep[y]]-1];//make dep[u]==dep[v]
	if(x==y)return x;//bec dep[u]<=dep[v] so no necessity consider if(LCA) 
	for(int k=lo[dep[x]];k>=0;k--)
		if(fa[x][k]!=fa[y][k])x=fa[x][k],y=fa[y][k];//jump
	return fa[x][0];//return father
}
signed main(){
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=n;i++){
		if(i==(1<<lo[i-1]))lo[i]++;
		lo[i]+=lo[i-1];//get lo[a_i] from 1 to n
	}
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		add_ed(x,y);add_ed(y,x);
	}
	find_fa(s,0);
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		printf("%d\n",lca(x,y));
	}
	return 0;
}
