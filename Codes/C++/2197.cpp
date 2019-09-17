#include<bits/stdc++.h>
using namespace std;
signed main()
{
int T;
scanf("%d",&T);
while(T--)
{
    int n,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int t;
        scanf("%d",&t);
        ans^=t;
    }
    puts(ans?"Yes":"No");
}
}