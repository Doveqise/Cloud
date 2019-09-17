#include<bits/stdc++.h>
using namespace std;
set<int>s;
set<int>::iterator it,l;
int main()
{
    long long n,x,ans=0;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&x);
        if(s.empty())
        {
            ans+=x;
            s.insert(x);
        }
        else
        {
            it=s.lower_bound(x);
            if(*it!=x)
            {
                l=it;
                l--;
                ans+=min(abs(*l-x),abs(*it-x));
                s.insert(x);
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}