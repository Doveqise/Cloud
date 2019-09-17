#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e3+5;
struct node
{
    int id,arm,leg;
    bool operator < (const node b) const
    {
        return arm+leg==b.arm+leg?leg>b.leg:arm+leg>b.arm+b.leg;
    }
}
man[maxn];
signed main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        man[i].id=i;
        int x,y;
        scanf("%d%d",&man[i].arm,&man[i].leg);
    }
    int h;
    scanf("%d",&h);
    sort(man+1,man+1+n);
    int now=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        if(now+man[i].arm+man[i].leg>=h)
            ans++;
        else
            now+=man[i].arm;
    }
    printf("%d\n",ans);
    return 0;
}