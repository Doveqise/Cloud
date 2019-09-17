#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int sx,s1x,xs,gc,mx;
    scanf("%lld%lld%lld",&sx,&s1x,&xs);
    gc=s1x-sx;
    mx=sx+gc*(xs-1);
    printf("%lld\n",(sx+mx)*xs/2);
    return 0;
}