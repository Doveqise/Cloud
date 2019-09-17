#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n,m,w,x,y,ans;
int a[maxn],s[maxn];
int main()
{
    scanf("%d%d",&n,&w);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        a[x]=a[x]+y;
        m=max(m,x);
    }
    for(int i=1;i<=m;i++)
        s[i]=s[i-1]+a[i];
    for(int i=1;i<=m-w+1;i++)
        ans=max(ans,s[i+w-1]-s[i-1]);
    printf("%d",ans);
    return 0;
}