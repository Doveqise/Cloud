#include<bits/stdc++.h>
#define il inline
#define rg register
#define vd void
#define sta static
typedef long long ll;
il int gi(){
    rg int x=0,f=1;rg char ch=getchar();
    while(ch<'0'||ch>'9')f=ch=='-'?-1:f,ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
const int maxn=50011;
int n;
namespace BITSegtree{
#define mid ((l+r)>>1)
    int rt[maxn],ls[maxn*100],rs[maxn*100],sum[maxn*100],index;
    il vd _update(int&x,int l,int r,const int&p,const int&k){
        if(!x)x=++index;sum[x]+=k;if(l==r)return;
        if(p<=mid)_update(ls[x],l,mid,p,k);
        else _update(rs[x],mid+1,r,p,k);
    }
    il int _query(int x,int l,int r,const int&L,const int&R){
        if( !x || r<L || R<l )return 0;if( L<=l && r<=R )return sum[x];
        return _query(ls[x],l,mid,L,R)+_query(rs[x],mid+1,r,L,R);
    }
    il int lb(const int&x){return x&-x;}
    il vd Update(int x,int y){while(x<=n)_update(rt[x],1,n+1,y+1,1),x+=lb(x);}
    il int Query(int l,int r,int x,int y){
        sta int ret;ret=0;
        while(r)ret+=_query(rt[r],1,n+1,x+1,y+1),r-=lb(r);
        --l;while(l)ret-=_query(rt[l],1,n+1,x+1,y+1),l-=lb(l);
        return ret;
    }
}
int lst[1000001];
int main(){
    using namespace BITSegtree;
    n=gi();int k;
    for(rg int i=1;i<=n;++i)k=gi(),Update(i,lst[k]),lst[k]=i;
    int l,r,m=gi();
    while(m--)l=gi(),r=gi(),printf("%d\n",Query(l,r,0,l-1));
    return 0;
}
