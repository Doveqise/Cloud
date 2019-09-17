#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int a[maxn],b[maxn];
int n,ans;
bool chk(int t)
{
    if(t==1)
        return 1;
    for(int i=0;i<t;i++)
        b[i]=a[i];
    sort(b+1,b+t);
    int lim=n-t;
    for(int i=1;i<t;i++)
    {
        if(b[i]>lim)
            return 0;
        lim++;
    }
    return 1;
}
signed main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int l=0,r=n;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(chk(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    printf("%d",n-ans);
    return 0;
}
