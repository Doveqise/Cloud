#include<bits/stdc++.h>
using namespace std;
signed main()
{
    int n, tot=0, maxx=0;
    scanf("%d",&n);
    for (int i=1,x; i<=n; i++)
    {
        scanf("%d",&x);
        tot+=x; 
        maxx=max(maxx, x);
    }
    printf("%d\n",tot); 
    tot-=maxx;
    if (tot>=maxx)
        puts("0");
    else 
        printf("%d\n",maxx-tot);
    return 0;
}