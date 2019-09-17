#include<bits/stdc++.h>
using namespace std;
int a1,a2,a3,fa[200001],n,m;
int getfa(int o){if (fa[o]==o) return o;else return fa[o]=getfa(fa[o]);}
void merge(int v,int u) {
    int t1,t2;
	t1=getfa(v);t2=getfa(u);
    if (t1!=t2) fa[t2]=t1;return; }
void find(int v,int u) {
    int t1,t2;
    t1=getfa(v);t2=getfa(u);
    if (t1==t2) printf("Y\n");else printf("N\n");}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a1,&a2,&a3);
        if (a1==1)merge(a2,a3);else find(a2,a3);
	}
	return 0;}
