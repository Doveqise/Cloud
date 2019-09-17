#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+5;
int t,n,m,x,y,flag,fa[maxn<<1];
int findfa(int u)
{
    return fa[u]==u?u:fa[u]=findfa(fa[u]);
}
void zip(int u,int v)
{
    fa[u]=v;
    return;
}
int main(){
    scanf("%d",&t);
    for (int j=1;j<=t;j++){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=(n<<1);i++)
        {
            fa[i]=i;
        }
        flag=0;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            if(flag)
                continue;
            if(findfa(x)==findfa(y)||findfa(x+n)==findfa(y+n))
            {
                flag=1;
                continue;
            }
            else
            {
                zip(findfa(x),findfa(y+n));
                zip(findfa(x+n),findfa(y));
            }
        }
        printf("Scenario #%d:\n",j);
        if(flag)
            printf("Suspicious bugs found!\n");
        else
            printf("No suspicious bugs found!\n");
    }
    return 0;
}