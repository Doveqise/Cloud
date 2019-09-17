#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 200005
using namespace std;
inline int read()
{
    int x=0,k=1; char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')k=-1;c=getchar();}
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*k;
}
int dis[MAXN],vis[MAXN];
int n,m,s,t;
struct form{
	vector<int>ed,wei;
	int num;
}F[MAXM];
struct cmp{
	bool operator()(int a,int b){
		return dis[a]>dis[b];
	}
};
priority_queue<int,vector<int>,cmp>q;
void solve(){
	q.push(s);
	while(!q.empty()){
		int u=q.top();
		q.pop();vis[u]=0;
		for(int i=1;i<=F[u].num;i++){
			int v=F[u].ed[i];
            if(dis[v]>dis[u]+F[u].wei[i])
            {
                dis[v]=dis[u]+F[u].wei[i];
                if(!vis[v])
                {
                      vis[v]=1;
                      q.push(v);
                }
            }
		}
	}
	return;
}
signed main(){
	n=read();m=read();s=read();
	for(int i=1;i<=n;i++) if(i!=s)dis[i]=2147483647;
	for(int i=1;i<=m;i++) F[i].ed.push_back(0),F[i].wei.push_back(0);
	for(int i=1;i<=m;i++){
		t=read();
		F[t].num++;
		F[t].ed.push_back(read());F[t].wei.push_back(read());
	}
	solve();
	for(int i=1;i<=n;i++)printf("%d ",dis[i]);
	return 0;
} 
