#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 5e5+5;
int n,m,pos[maxn],c[maxn];
LL s[maxn],ansnum;
struct node
{
    int l,r,id;
    LL a,b;   
}
ans[maxn];
bool cmp(node a,node b)
{
    return pos[a.l]==pos[b.l]?a.r<b.r:a.l<b.l;
}
bool cmp1(node a,node b)
{
    return a.id<b.id;
}
LL gcd(LL a,LL b)
{
    return (!b)?a:gcd(b,a%b);
}
void getans(int p,int add)
{
    ansnum-=s[c[p]]*s[c[p]];
    s[c[p]]+=add;
    ansnum+=s[c[p]]*s[c[p]];
}
void solve()
{
    for(int i=1,l=1,r=0;i<=m;i++)
    {
        while(r<ans[i].r)
        {
            getans(r+1,1);
            r++;
        }
        while(r>ans[i].r)
        {
            getans(r,-1);
            r--;
        }
        while(l<ans[i].l)
        {
            getans(l,-1);
            l++;
        }
        while(l>ans[i].l)
        {
            getans(l-1,1);
            l--;
        }
        if(ans[i].l==ans[i].r)
        {
            ans[i].a=0;
            ans[i].b=1;
            continue;
        }
        ans[i].a=ansnum-(ans[i].r-ans[i].l+1);
        ans[i].b=(ans[i].r-ans[i].l+1)*1LL*(ans[i].r-ans[i].l);
        LL g=gcd(ans[i].a,ans[i].b);
        ans[i].a/=g;
        ans[i].b/=g;
    }
}
signed main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    int len=sqrt(n);
    for(int i=1;i<=n;i++)
        pos[i]=(i-1)/len+1;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&ans[i].l,&ans[i].r);
        ans[i].id=i;
    }
    sort(ans+1,ans+1+m,cmp);
    solve();
    sort(ans+1,ans+1+m,cmp1);
    for(int i=1;i<=m;i++)
        printf("%lld/%lld\n",ans[i].a,ans[i].b);
    return 0;
}