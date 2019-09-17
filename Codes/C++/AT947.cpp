#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int>pa;
const int INF=1234567890;
struct edge{int to,weight;};
int main() {
    int N,M;scanf("%d%d",&N,&M);
    vector<vector<edge> >cost(N+1, vector<edge>(0));
    for(int i=1;i<=N;i++) {int c;scanf("%d",&c);cost[0].push_back({i,c});}
    for(int i=1;i<=M;i++) {
        int a,b,r;scanf("%d%d%d",&a,&b,&r);
        cost[a].push_back({b,r}),cost[b].push_back({a,r});}
    priority_queue<pa, vector<pa>, greater<pa> > mincost;
    vector<bool>used(N+1,false);
    used[0]=0;mincost.push(pa(0,0));
    ll ans=0;
    while(!mincost.empty()) {
        pp v=mincost.top();mincost.pop();
        if(used[v.second])continue;
        used[v.second]=1;ans+=v.first;
        for(edge e:cost[v.second]) mincost.push(pa(e.weight, e.to));
    }
    printf("%lld",ans);
    return 0;
}
