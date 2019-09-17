#include<bits/stdc++.h>
signed main()
{
    int n,x,y,t,ans=0;
    scanf("%d%d%d",&n,&x,&y);
    if(x>y) 
    {
        printf("%d\n",n);
        return 0;
    }
    while(n--)
    {
        scanf("%d",&t);
        ans+=(t<=x);
    }
    printf("%d\n",(ans+1)/2);
    return 0;
}