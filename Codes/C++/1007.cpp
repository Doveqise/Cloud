#include<bits/stdc++.h>
using namespace std;
signed main()
{
	int l,n,maxx=0,minx=0;
    scanf("%d%d",&l,&n);
    for(int i=1,p;i<=n;i++)
    {
        scanf("%d",&p);
        maxx=max(maxx,max(l-p+1,p));
        minx=max(minx,min(l-p+1,p));
    }
    printf("%d %d",minx,maxx);
    return 0;
}
