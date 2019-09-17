#include<bits/stdc++.h>
using namespace std;
signed main()
{
    int nk=1,n;
    scanf("%d",&n);
    if(n==1)
    {
        scanf("%d",&nk);
        puts(nk?"YES":"NO");
        return 0;
    }
    else
    {
        for(int i=1,t;i<=n;i++)
        {
            scanf("%d",&t);
            if(!t)
            {
                if(nk)
                    nk--;
                else
                {
                    puts("NO");
                    return 0;
                }
            }
        }
        puts(nk?"NO":"YES");
        return 0;
    }
}