#include<bits/stdc++.h>
#define ll long long
using namespace std;
int p;
ll a[100005];
struct node
{
    ll v,mul,add;
}st[400005];
void bt(int root,int l,int r)
{
    st[root].mul=1;
    st[root].add=0;
    if(l==r)
    {
        st[root].v=a[l];
    } 
    else
    {
        int m=(l+r)>>1;
        bt(root*2,l,m);
        bt(root*2+1,m+1,r);
        st[root].v=st[root*2].v+st[root*2+1].v;
    }
    st[root].v%=p;
    return;
}
void pushdown(int root,int l,int r)
{
    int m=(l+r)>>1;
    st[root*2].v=(st[root*2].v*st[root].mul+st[root].add*(m-l+1))%p;
    st[root*2+1].v=(st[root*2+1].v*st[root].mul+st[root].add*(r-m))%p;
    st[root*2].mul=(st[root*2].mul*st[root].mul)%p;
    st[root*2+1].mul=(st[root*2+1].mul*st[root].mul)%p;
    st[root*2].add=(st[root*2].add*st[root].mul+st[root].add)%p;
    st[root*2+1].add=(st[root*2+1].add*st[root].mul+st[root].add)%p;
    st[root].mul=1;
    st[root].add=0;
    return;
}
void ud1(int root,int stdl,int stdr,int l,int r,lll k)
{
    if(r<stdl||l>stdr)return;
    if(l<=stdl&&r>=stdr)
    {
        st[root].v=(st[root].v*k)%p;
        st[root].mul=(st[root].mul*k)%p;
        st[root].add=(st[root].add*k)%p;
        return;
    }
    pushdown(root,stdl,stdr);
    int m=(stdl+stdr)>>1;
    ud1(root*2,stdl,m,l,r,k);
    ud1(root*2+1,m+1,stdr,l,r,k);
    st[root].v=(st[root*2].v+st[root*2+1].v)%p;
    return;
}
void ud2(int root,int stdl,int stdr,int l,int r,lll k)
{
    if(r<stdl||l>stdr)return;
    if(l<=stdl&&r>=stdr)
    {
        st[root].add=(st[root].add+k)%p;
        st[root].v=(st[root].v+k*(stdr-stdl+1))%p;
        return;
    }
    pushdown(root,stdl,stdr);
    int m=(stdl+stdr)>>1;
    ud2(root*2,stdl,m,l,r,k);
    ud2(root*2+1,m+1,stdr,l,r,k);
    st[root].v=(st[root*2].v+st[root*2+1].v)%p;
    return;
}
ll sum(int root,int stdl,int stdr,int l,int r)
{
    if(r<stdl||l>stdr)return 0;
    if(l<=stdl&&r>=stdr)return st[root].v;
    pushdown(root,stdl,stdr);
    int m=(stdl+stdr)>>1;
    return (sum(root*2,stdl,m,l,r)+sum(root*2+1,m+1,stdr,l,r))%p;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&p);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    bt(1,1,n);
    scanf("%d",&m);
    while(m--)
    {
        int chk;
        scanf("%d",&chk);
        int x,y;
        lll k;
        if(chk==1)
        {
            scanf("%d%d%lld",&x,&y,&k);
            ud1(1,1,n,x,y,k);
        }
        else if(chk==2)
        {
            scanf("%d%d%lld",&x,&y,&k);
            ud2(1,1,n,x,y,k);
        }
        else
        {
            scanf("%d%d",&x,&y);
            cout<<sum(1,1,n,x,y)<<endl;
        }
    }
    return 0;
}
