#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
struct node
{
    int l,r;
    bool operator <(const node b)
    {
        return l<b.l;
    }
}
a[maxn];
signed main()
{
    int n;
    long long ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].l,&a[i].r);
    sort(a+1,a+1+n);
    int L=a[1].l,R=a[1].r;
    for(int i=2;i<=n;i++)
    {
        if(a[i].l>R)
        {
            ans+=R-L+1;
            L=a[i].l;
            R=a[i].r;
        }
        else if(a[i].r>R)
            R=a[i].r;
    }
    ans+=R-L+1;
    printf("%lld",ans);
    return 0;
}