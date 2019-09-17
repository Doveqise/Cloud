#include<bits/stdc++.h>
using namespace std;
int a,b,c;int vis[1010][1010];
struct node{int x,y,dep,op,pa;};
node q[1001*1001];
int head=0,tail=1;
void cherk(int x,int y,int dep,int op,int pa){
    if(vis[x][y]!=0)return;vis[x][y]=1;
    q[tail++]=(node){x,y,dep,op,pa};}
int bfs(int x,int y,int op,int pa){head=0,tail=1;
    while(head<tail){
        node p=q[head++];int x=p.x,y=p.y,d=p.dep;if(y==c)return d;
        if(x<a)cherk(a,y,d+1,1,head-1);if(y<b)cherk(x,b,d+1,2,head-1);
        if(x>0)cherk(0,y,d+1,3,head-1);if(y>0)cherk(x,0,d+1,4,head-1);
        if(x>0&&y<b){if(x<b-y)cherk(0,y+x,d+1,6,head-1);else cherk(x+y-b,b,d+1,6,head-1);}
        if(y>0&&x<a){if(y<a-x)cherk(x+y,0,d+1,5,head-1);else cherk(a,y+x-a,d+1,5,head-1);}}
}
void dfs(int p){if(p>0){dfs(q[p].pa);cout<<q[p].op<<" ";}}
int main(){
    int t;scanf("%d",&t);
    for(int u=1;u<=t;u++){
        scanf("%d%d%d",&a,&b,&c);
        memset(vis,0,sizeof(vis));vis[0][0]=1;
        cout<<bfs(0,0,0,0)<<" ";dfs(head-1);cout<<endl;}
}
