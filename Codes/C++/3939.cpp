#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+5;
int ans=0,col[maxn];
vector<int>v[maxn];
signed main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&col[i]);
    for(int i=1;i<=n;i++) v[col[i]].push_back(i);
    while(m--)
    {
        int opt,l,r,c,x;
        scanf("%d",&opt);
        if(opt==1)
        {
            scanf("%d%d%d",&l,&r,&c);
            int p1=lower_bound(v[c].begin(),v[c].end(),l)-v[c].begin();
            int p2=upper_bound(v[c].begin(),v[c].end(),r)-v[c].begin()-1;
            if(p2<p1) puts("0");
            else printf("%d\n",p2-p1+1);
        }
        else
        {
            scanf("%d",&x);
            if(col[x]==col[x+1]) continue;
            int p1=lower_bound(v[col[x]].begin(),v[col[x]].end(),x)-v[col[x]].begin();
            v[col[x]][p1]++;
            int p2=lower_bound(v[col[x+1]].begin(),v[col[x+1]].end(),x+1)-v[col[x+1]].begin();
            v[col[x+1]][p2]--;
            swap(col[x],col[x+1]);
        }
    }
    return 0;
}