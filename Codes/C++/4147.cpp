#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
struct Mat
{
    int data,up,lft,rht;
}
a[maxn][maxn];
signed main()
{
    int n,m;
    scanf("%d%d",&n,&m);;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            char ch;
            cin>>ch;
            if(ch=='R')
                a[i][j].data=1;
        }
    for(int i=0;i<=n+1;i++)
        a[i][0].data=a[i][m+1].data=1;
    for(int j=0;j<=m+1;j++)
        a[0][j].data=a[n+1][j].data=1;
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=m+1;j++)
        {
            if(a[i][j].data)
            {
                int k=i+1;
                while((!a[k][j].data)&&k<=n+1)
                {
                    a[k][j].up=i+1;
                    k++;
                }
                k=j+1;
                while((!a[i][k].data)&&k<=m+1)
                {
                    a[i][k].lft=j+1;
                    k++;
                }
                k=j-1;
                while((!a[i][k].data)&&k>=0)
                {
                    a[i][k].rht=j-1;
                    k--;
                }
            }
        }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++)
    //     {
    //         printf("AT POINT (%d,%d) UP=%d LEFT = %d RIGHT = %d\n",i,j,a[i][j].up,a[i][j].lft,a[i][j].rht);
    //     }
    //     printf("\n");
    // }
    for(int j=1;j<=m;j++)
        for(int i=1;i<=n;i++)
        {
            if(a[i][j].data)
                continue;
                a[i+1][j].lft=max(a[i][j].lft,a[i+1][j].lft);
                a[i+1][j].rht=min(a[i][j].rht,a[i+1][j].rht);
        }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++)
    //     {
    //         printf("AT POINT (%d,%d) UP=%d LEFT = %d RIGHT = %d\n",i,j,a[i][j].up,a[i][j].lft,a[i][j].rht);
    //     }
    //     printf("\n");
    // }
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!a[i][j].data)
                ans=max(ans,(i-a[i][j].up+1)*(a[i][j].rht-a[i][j].lft+1));
    printf("%d",ans*3);
    return 0;
}