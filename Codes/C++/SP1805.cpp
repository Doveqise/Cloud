#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int n,h[maxn],wid[maxn],s[maxn],t;
ll ans;
int main()
{
    while(scanf("%d",&n)&&n)
    {
        memset(s,0,sizeof(s));
        memset(h,0,sizeof(h));
        memset(wid,0,sizeof(wid));
        t=0;ans=0;
        for(int i=1;i<=n;i++)
            cin>>h[i];
        h[++n]=0;
        for(int i=1;i<=n;i++)
        {
            int w=0;
            while(t&&h[s[t]]>h[i])
            {
                w+=wid[t];
                ans=max(ans,(ll)w*h[s[t]]);
                t--;
            }
            s[++t]=i;
            wid[t]=w+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}