#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int T,n,x,y,e,fa[maxn],flag,cnt;
vector<pair<int,int> >V;
map<int,int>M;
void init()
{
    for(int i=1;i<=(n<<1);i++)
        fa[i]=i;
}
int findfa(int x)
{
    return fa[x]==x?x:fa[x]=findfa(fa[x]);
}
bool judge(int x,int y)
{
    return findfa(x)==findfa(y);
}
void merge(int x,int y)
{
    fa[findfa(x)]=findfa(y);
}
signed main()
{
    scanf("%d",&T);
    while(T--)
    {
        M.clear();
        V.clear();
        init();
        cnt=0;
        flag=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&x,&y,&e);
            if(M.find(x)!=M.end())
                x=M[x];
            else
            {
                M[x]=++cnt;
                x=cnt;
            }
            if(M.find(y)!=M.end())
                y=M[y];
            else
            {
                M[y]=++cnt;
                y=cnt;
            }
            if(e)
            {
                merge(x,y);
            }
            else
            {
                V.push_back(make_pair(x,y));
            }
        }
        for(vector<pair<int,int> >::iterator it=V.begin();it!=V.end();++it)
        {
            if(judge(it->first,it->second))
            {
                puts("NO");
                flag=1;
                break;
            }
        }
        if(!flag)
            puts("YES");
    }
    return 0;
}
