#include<bits/stdc++.h>
using namespace std;
const int maxn=200200,inf=214748364;
int cnt[maxn],dis[maxn],t,n,m,p,head[maxn],tot,st=1;
bool vis[maxn],flag;
struct node{int to,nxt,wei;}edge[maxn<<1];
int in(){
    int x=0,f=1; char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
void add_edge(int x,int y,int z){edge[++tot].to=y,edge[tot].nxt=head[x],edge[tot].wei=z,head[x]=tot;}
bool spfa(){
    queue<int> q;
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[st]=0;vis[st]=1,cnt[st]=1;
    q.push(st);
    while(q.size())
    {
        int x=q.front();q.pop();vis[x]=0;
        for(int i=head[x];i;i=edge[i].nxt)
        {
            int y=edge[i].to,z=edge[i].wei;
            if(dis[y]>dis[x]+z)
            {
                dis[y]=dis[x]+z;
                cnt[y]=cnt[x]+1;
                if(cnt[y]>n) return 1;
                if(!vis[y])
                {
                    vis[y]=1;
                    q.push(y);
                }
            }
        }
    }
    return 0;
}
int main(){
    t=in();while(t--){
        for(int i=1;i<=n;i++) dis[i]=0;
        memset(head,0,sizeof(head));
        memset(vis,0,sizeof(vis));
        flag=tot=0;n=in(),m=in();dis[1]=0;
        for(int i=1,x,y,z;i<=m;i++){
            x=in(),y=in(),z=in();
            if(z>=0) add_edge(y,x,z);
            add_edge(x,y,z);}
        if(spfa())puts("YE5");
        else puts("N0");   
    }
    return 0;    
}