#include<bits/stdc++.h>
using namespace std;
int a[1000005];
void solve(int x)
{
    int lim=sqrt(x+0.5);
    for(int i=1;i<=lim;i++)
        if(!(x%i))
        {
            a[i]++;
            if(x!=i*i) a[x/i]++;
        }
    return;
}
signed main()
{
    int n,maxx=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int t;
        scanf("%d",&t);
        solve(t);
        maxx=max(maxx,t);
    }
    int t=1;
    int x=maxx;
    for(int i=1;i<=n;i++)
    {
        while(a[x]<i) x--;
        printf("%d\n",x);
    }
    return 0;
}