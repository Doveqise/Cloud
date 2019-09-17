#include<bits/stdc++.h>
using namespace std;
int jud[10002][202],a[10002][202];
signed main()
{
    int n,m,x,i,j,ans=0,l=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        l=0;
        for(j=0;j<m;j++)
        {
            scanf("%d%d",&jud[i][j],&a[i][j]);
            if(jud[i][j]==1)l++;
        }
        jud[i][m]=l;
    }
    scanf("%d",&x);i=1;
    while(i<=n)
    {
        ans+=a[i][x];
        ans%=20123;
        int k=0;j=x;
        while(1)
        {
            if(j==m) j=0;
            if(jud[i][j]==1) k++;
            if(k==(a[i][x]-1)%jud[i][m]+1) break;
            j++;
        }
        x=j;i++;
    }
    printf("%d",ans);
    return 0;
}