#include<bits/stdc++.h>
using namespace std;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
const int maxn = 1e2+5;
bool bar[maxn][maxn];
bool vis[maxn][maxn];
int ans=0,n,b;
char ch;
bool judge(int x,int y)
{
    return x>=0&&x<n&&y>=0&&y<n?1:0;
}
void dfs(int x,int y,int sid,int now,int flag)
{
    if(vis[x+dx[sid]][y+dy[sid]])
    {
        ans=max(ans,now);
        return;
    }
    else if(bar[x+dx[sid]][y+dy[sid]]||(!judge(x+dx[sid],y+dy[sid])))
    {
        if(!flag)
        {
            ans=max(ans,now);
            return;
        }
        dfs(x,y,(sid+3)%4,now,0);
        dfs(x,y,(sid+1)%4,now,0);
    }
    else
    {
        vis[x][y]=1;
        dfs(x+dx[sid],y+dy[sid],sid,now+1,1);
        vis[x][y]=0;
    }
    return;
}
signed main()
{
    scanf("%d %d\n",&n,&b);
    for(int i=0,t;i<b;i++)
    {
        cin>>ch>>t;
        bar[ch-'A'][t-1]=1;
    }
    dfs(0,0,0,1,1);
    dfs(0,0,1,1,1);
    printf("%d\n",ans);
    return 0;
}