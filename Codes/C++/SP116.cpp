#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int ver[maxn],head[maxn],edge[maxn],Next[maxn];
int d[maxn],v[maxn];
int cnt;
void add_e(int x,int y,int z){ver[++cnt]=y,edge[cnt]=z,Next[cnt]=head[x],head[x]=cnt;}
void SPFA(){
	queue<int>q;memset(d,-1,sizeof(d));memset(v,0,sizeof(v));
    d[0]=0;v[0]=1;q.push(0);
    while(!q.empty()){
        int x=q.front();q.pop();v[x]=0;
        for(int i=head[x];i;i=Next[i]){
            int y=ver[i],z=edge[i];
            if(d[y]<d[x]+z){d[y]=d[x]+z;
                if(!v[y])q.push(y),v[y]=1;}
        }
    }
}
int main(){
    int t;scanf("%d",&t);
    for(int k=1;k<=t;k++){
        cnt=0;int mn=-1e9+7; 
        memset(ver,0,sizeof(ver));memset(head,0,sizeof(head));
        memset(Next,0,sizeof(Next));memset(edge,0,sizeof(edge));
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int a,b,c;scanf("%d%d%d",&a,&b,&c);
            add_e(a,b+1,c);mn=max(mn,b);}
        for(int i=1;i<=mn+1;i++){add_e(i-1,i,0);add_e(i,i-1,-1);}
        SPFA();
        printf("%d\n",d[mn+1]);
    }
    return 0;
}
