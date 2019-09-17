#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e3+5;
int L,W;
struct node
{
    int x,y;
    bool operator < (const node b) const
    {
        return x==b.x?y<b.y:x<b.x;
    }
}
a[maxn];
signed main()
{
    scanf("%d%d",&L,&W);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
    a[n+1].x=a[n+1].y=0;
    a[n+2].x=L,a[n+2].y=W;
    a[n+3].x=0,a[n+3].y=W;
    a[n+4].x=L,a[n+4].y=0;
    n+=4;
    int ans=0;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        int dtx=L-a[i].x,upp=W,dwn=0;
        for(int j=i+1;j<=n;j++)
        {
            if(dtx*(upp-dwn)<=ans)
                break;
            ans=max(ans,(upp-dwn)*(a[j].x-a[i].x));
            if(a[j].y>=a[i].y)
                upp=min(upp,a[j].y);
            else 
                dwn=max(dwn,a[j].y);
        }
    }
    for(int i=1;i<=n;i++)
        swap(a[i].x,a[i].y);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        int dtx=L-a[i].x,upp=W,dwn=0;
        for(int j=i+1;j<=n;j++)
        {
            if(dtx*(upp-dwn)<=ans)
                break;
            ans=max(ans,(upp-dwn)*(a[j].x-a[i].x));
            if(a[j].y>=a[i].y)
                upp=min(upp,a[j].y);
            else 
                dwn=max(dwn,a[j].y);
        }
    }
    printf("%d\n",ans);
    return 0;
}