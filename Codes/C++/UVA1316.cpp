#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
struct node{
    int a, b;
    bool operator < (const node x) const {
        return b < x.b;
    }
}a[maxn];
struct cmp{
    int a;
    bool operator < (const cmp x) const {
        return a > x.a;
    }
};
int n, ans;
int main()
{
    while(cin >> n)
    {
        ans=0;
        memset(a,0,sizeof(a));
        priority_queue<cmp>q;
        for(int i=1;i<=n;i++)
            scanf("%d%d",&a[i].a,&a[i].b);
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++) 
        {
            if(a[i].b>q.size())
                q.push((cmp){a[i].a});
            else if(a[i].b==q.size()&&a[i].a>q.top().a)
            {
                q.pop();
                q.push((cmp){a[i].a});
            }
        }
        while(!q.empty())
        {
            ans+=q.top().a;
            q.pop();
        }
        printf("%d\n",ans);
    }
    return 0;
}