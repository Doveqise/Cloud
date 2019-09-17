#include<bits/stdc++.h>
using namespace std;
#define int long long
int f[25]={0,0,1,2},n;
signed main()
{
    scanf("%lld",&n);
    if(n<4)
    {
        printf("%d",f[n]);
        return 0;
    }
    for(int i=4;i<=n;i++)
        f[i]=(i-1)*(f[i-1]+f[i-2]);
    printf("%lld",f[n]);
    return 0;
}