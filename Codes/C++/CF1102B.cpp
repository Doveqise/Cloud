#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e3+5;
int a[maxn],cnt[maxn],col[maxn];
signed main()
{
    int n,k,t=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    for(int i=1;i<=5000;i++)
    {
        if(cnt[i]>k||cnt[i]==n&&n!=1&&n!=5000&&n!=k)
            puts("NO"),exit(0);
        else
            for(int j=1;j<=n;j++)
                if(a[j]==i)
                {
                    col[j]=++t;
                    t%=k;
                }
    }
    puts("YES");
    int flg = 0;
    for(int i=1;i<=n;i++)
        if(col[i])
            flg = 1;
    if(!flg)
    {
        for(int i=1;i<=n;i++)
            printf("%d ", i);
        return 0;
    }
    for(int i=1;i<=n;i++)
        printf("%d ",col[i]?col[i]:col[i]+k);
    return 0;
}