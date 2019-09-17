#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
    int n,m,ans=0,tot=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+m);
    for(int i=0;i<m;i++)
    {
        int now=a[i];
        if(now*(m-i)>ans)
        {
            ans=now*(m-i);
            tot=now;
        }
    }
    printf("%d %d",tot,ans);
    return 0;
} 
