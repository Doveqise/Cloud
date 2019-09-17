#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e2+5;
ll a[maxn],c[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    ll tot=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        tot+=a[i];
    } 
    ll m=tot/n;
    for(int i=1;i<n;i++)
        c[i]=c[i-1]+a[i]-m;
    sort(c,c+n);
    ll x1=c[n>>1];
    for(int i=0;i<n;i++)
        ans+=abs(x1-c[i]); 
    printf("%lld\n",ans); 
    return 0;
}