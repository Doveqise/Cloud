#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long num[maxn],ans;
int l[maxn],r[maxn];
bool vis[maxn];
struct node{int id;long long w;
bool operator < (node b)const{return w < b.w;}}t;
void del(int x){
	l[x]=l[l[x]];r[x]=r[r[x]];
    r[l[x]]=x;l[r[x]]=x;}
priority_queue<node>q;
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&t.w);
        num[i]=t.w;t.id=i;
        l[i]=i-1;r[i]=i+1;
        q.push(t);}
    l[n+1]=n;r[0]=1;
    for(int i=1;i<=m;i++){
        while(vis[q.top().id]) q.pop();
        t=q.top();q.pop();if(t.w<0)break;ans+=t.w;
        int c=t.id;
        num[c]=num[l[c]]+num[r[c]]-num[c];
        t.w=num[c];vis[l[c]]=vis[r[c]]=1;
        q.push(t);del(c);
    }
    printf("%lld",ans);
    return 0;
} 