#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
struct node{
    int a,b;
    bool operator < (const node x)const
    {
        return a==x.a?b>x.b:a<x.a;
    }
}w[maxn];
int n,i;
long long ans;
priority_queue<int,vector<int>,greater<int> >q;
signed main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d%d",&w[i].a,&w[i].b);
    sort(w+1,w+n+1);
    for(i=1;i<=n;i++)
    {
        if(w[i].a<=q.size())
        {
            if (w[i].b>q.top())
            {
                ans-=q.top();
                q.pop(); 
                q.push(w[i].b);
                ans+=w[i].b;
            }
        }
        else
        {
            q.push(w[i].b);
            ans+=w[i].b;
        }
    }
    printf("%lld",ans);
    return 0;
}