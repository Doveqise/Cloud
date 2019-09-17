#include<bits/stdc++.h>
#define maxx 300020
#define ll long long
using namespace std;
int n,m,p,l,r,a[maxx];
char s[maxx];
ll add[maxx<<2],sum[maxx<<2];
inline void pushup(int rt){sum[rt]=sum[rt<<1]+sum[rt<<1|1];}
inline void bulid(int l,int r,int rt){
    if(l==r){ sum[rt]=a[l]; return ;}
    int mid=(l+r)>>1;
    bulid(l,mid,rt<<1);
    bulid(mid+1,r,rt<<1|1);
    pushup(rt);
}
inline void pushdown(int rt,int len){
    if(add[rt]){
        add[rt<<1]^=1;
        add[rt<<1|1]^=1; 
        sum[rt<<1]=(len-(len>>1))-sum[rt<<1];
        sum[rt<<1|1]=(len>>1)-sum[rt<<1|1];
        add[rt]=0;
    }
}
inline ll query(int L,int R,int l,int r,int rt){
    if(l>=L&&r<=R)return sum[rt];
    pushdown(rt,r-l+1);
    int mid=(r+l)>>1;
    ll tot=0;
    if(L<=mid) tot+=query(L,R,l,mid,rt<<1);
    if(mid+1<=R) tot+=query(L,R,mid+1,r,rt<<1|1);
    return tot;
}
inline void update(int L,int R,int l,int r,int rt){
    pushdown(rt,r-l+1);
    if(l>=L&&r<=R){
        add[rt]^=1;
        sum[rt]=r-l+1-sum[rt];
        return;
    }
    int mid=(l+r)>>1;
    if(L<=mid) update(L,R,l,mid,rt<<1);
    if(mid+1<=R) update(L,R,mid+1,r,rt<<1|1);  
    pushup(rt);
} 
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++) a[i]=s[i]-'0';
    bulid(1,n,1);
    for(int i=1;i<=m;i++) 
    {
        scanf("%d%d%d",&p,&l,&r);
        if(p==0) update(l,r,1,n,1);
        if(p==1)  cout<<query(l,r,1,n,1)<<endl; 
    }
    return 0;
}
