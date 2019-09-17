#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int c[maxn];
struct node
{
    int l,r;
    bool operator < (const node b)
    {
        return l<b.l;
    }
}
s[maxn];
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int n)
{
    for(int i=x;i<=(n<<1);i+=lowbit(i)) c[i]++;
    return;
}
int query(int x)
{
    int ans=0;
    for(int i=x;i>=1;i-=lowbit(i)) ans+=c[i];
    return ans;
}
signed main()
{
    int n;
    scanf("%d",&n);
    for(int i=1,a;i<=(n<<1);i++)
    {
        scanf("%d",&a);
        s[a].l?s[a].r=i:s[a].l=i;
    }
    sort(s+1,s+1+n);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        add(s[i].r,n);
        ans+=query(s[i].r-1)-query(s[i].l);
    }
    printf("%d",ans);
    return 0;
}
