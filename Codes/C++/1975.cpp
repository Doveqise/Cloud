#include <bits/stdc++.h>
const int maxn = 1e5+5;
using namespace std;
int n, m, ans;
int a[maxn];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    int x,y;
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
        if(a[i]>a[j]) ans++;
    printf("%d\n",ans);
    while (m--)
    {
        scanf("%d%d",&x,&y);
        if(x>y) swap(x,y);
        if(a[x]>a[y]) ans--;
        if(a[y]>a[x]) ans++;
        for(int i=x+1;i<y;i++)
        {
            ans+=(a[i]>a[x]);
            ans-=(a[i]<a[x]);
            ans+=(a[i]<a[y]);
            ans-=(a[i]>a[y]);
        }
        swap(a[x],a[y]);
        printf("%d\n",ans);
    }
    return 0;
}