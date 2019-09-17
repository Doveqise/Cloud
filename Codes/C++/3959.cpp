#include<bits/stdc++.h>
#define inf 2147483647
using namespace std;
int n, m;
int world[13][13];int depth[13]; 
struct edge {int u, v;}; bool operator < (struct edge a, struct edge b) {return depth[a.u]*world[a.u][a.v]>depth[b.u]*world[b.u][b.v];}
int search(int source) {
    memset(depth, 0, sizeof(depth));int vis[13]={0};
    priority_queue <struct edge> heap;edge past[1000]; int p = 0;
    struct edge e, e2;int cost = 0;depth[source]=1; vis[source]=1;
    for (int i = 1; i <= n; ++i)if(world[source][i]<inf){e.u=source; e.v=i;heap.push(e);}
    for (int i = 1; i < n; ++i) {
        e=heap.top(); heap.pop();
        while (!heap.empty()&&((vis[e.v]||rand()%(n)<1))) {if (!vis[e.v])past[p++]=e;e=heap.top(); heap.pop();} vis[e.v]=1; depth[e.v]=depth[e.u]+1;
        if (p-->0) {for (;p>=0;--p) {heap.push(past[p]);}}p=0;
        for (int i = 1; i <= n; ++i) {if (world[e.v][i]<inf&&!vis[i]) {e2.u=e.v; e2.v=i;heap.push(e2);}} 
        cost+=world[e.u][e.v]*depth[e.u];
    } return cost;
}

int main() {
    int a, b, c;scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i){for(int j=1;j<=n;++j){world[i][j]=inf;}}
    for (int i = 0; i < m; ++i) {scanf("%d %d %d", &a, &b,&c);world[a][b]=world[b][a]=min(c, world[a][b]);} 
    srand(123);int MIN = inf;
    for (int j = 1; j <123; ++j) {for (int i=1;i<=n; ++i) {MIN=min(MIN, search(i));}}
    printf("%d", MIN); return 0;
}