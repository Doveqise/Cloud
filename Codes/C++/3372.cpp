/*#include<bits/stdc++.h>
using namespace std;
const long long maxn=100005;
long long a[maxn+2];
struct node{
	long long l,r;
	long long val,laz;
}t[4*maxn+2];
void build(long long p,long long l,long long r){
	t[p].l=l;t[p].r=r;
	if(l==r) {t[p].val=a[l];return;}
	long long mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	t[p].val=t[p*2].val+t[p*2+1].val;
}
void spread(long long p){
	if(t[p].laz){
		t[p*2].val+=t[p].laz*(t[p*2].r-t[p*2].l+1);
		t[p*2+1].val+=t[p].laz*(t[p*2+1].r-t[p*2+1].l+1);
		t[p*2].laz+=t[p].laz;
		t[p*2+1].laz+=t[p].laz;
		t[p].laz=0;
	}
}
void change(long long p,long long x,long long y,long long z){
	if(x<=t[p].l&&y>=t[p].r){
		t[p].val+=(long long)z*(t[p].r-t[p].l+1);
		t[p].laz+=z;
		return;
	}
	spread(p);
	long long mid=(t[p].l+t[p].r)>>1;
	if(x<=mid) change(p*2,x,y,z);
	if(y>mid) change(p*2+1,x,y,z);
	t[p].val=t[p*2].val+t[p*2+1].val;
}
long long ask(long long p,long long x,long long y){
	if(x<=t[p].l&&y>=t[p].r) return t[p].val;
	spread(p);
	long long mid=(t[p].l+t[p].r)>>1;
	long long ans=0;
	if(x<=mid) ans+=ask(p*2,x,y);
	if(y>mid) ans+=ask(p*2+1,x,y);
	return ans;
}
signed main(){
	freopen("testdata.in","r",stdin);
	freopen("testdata.out","w",stdout); 
	long long n,m;
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		build(1,1,n);
	}
	for(long long i=1;i<=m;i++){
		long long q,x,y,z;
		scanf("%lld",&q);
		if(q==1){
			scanf("%lld%lld%lld",&x,&y,&z);
			change(1,x,y,z);
		}
		else{
			scanf("%lld%lld",&x,&y);
		printf("%lld\n",ask(1,x,y));
		}
	}
	return 0;
}
*/
/*
#include<bits/stdc++.h>
#define MAXN 1000
using namespace std;
struct node{
	long long left,right;
	long long s,lazy;
	node *ch[2];
}pool[MAXN],*root;
void Build(node *r,long long left,long long right){
	r->left=left;r->right=right;
	if(left==right){r->s=a[left];return;}
	long long mid=(left+right)/2;
	node *lson=&pool[++cnt];node *rson=&pool[++cnt];
	r->ch[0]=lson;r->ch[1]=rson;
	Build(lson,left,mid);Build(rson,mid+1,right);
	r->s=r->ch[0]->s+r->ch[1]->s;
}
inline void Push(node *r){
	if(r->lazy==0)return;
	r->s+=(r->right-r->left+1)*r->lazy;
	if(r->ch[0])r->ch[0]->lazy+=r->lazy;if(r->ch[1])r->ch[1]->lazy+=r->lazy;
	r->lazy=0;
}
void change(node *r,long long left,long long right,long long d){
	if(r->left==left&&r->right==right){r->lazy+=d;return;}
	Push(r);
	if(r->ch[0]->right>=right)change(r->ch[0],left,right,d);else if(r->ch[1]->left<=right)change(r->ch[1],left,right,d);
	else{change(r->ch[0],left,r->ch[0]->right,d);
		change(r->ch[1],r->ch[1]->left,right,d);}
	Push(r->ch[0]);Push(r->ch[1]);
	r->s=r->ch[0]->s+r->ch[1]->s;
}
long long query(node *r,long long left,long long right){
	Push(r);
	if(r->left==left&&r->right==right)return r->s;
	if(r->ch[0]->right>=right)return query(r->ch[1],left,right);else if(r->ch[1]->left<=left)return query(r->ch[1],left,right);
	else return query(r->ch[0],left,r->ch[0]->right)+query(r->ch[1],r->ch[1]->left,right);
}
signed main(){
	
}*/
/*
#include<iostream>
#include<cstdio>
#define MAXN 1000001
#define ll long long
using namespace std;
unsigned ll n,m,a[MAXN],ans[MAXN<<2],tag[MAXN<<2];
inline ll ls(ll x)
{
    return x<<1;
}
inline ll rs(ll x)
{
    return x<<1|1;
}
void scan()
{
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    scanf("%lld",&a[i]);
}
inline void push_up(ll p)
{
    ans[p]=ans[ls(p)]+ans[rs(p)];
}
void build(ll p,ll l,ll r)
{
    tag[p]=0;
    if(l==r){ans[p]=a[l];return ;}
    ll mid=(l+r)>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    push_up(p);
} 
inline void f(ll p,ll l,ll r,ll k)
{
    tag[p]=tag[p]+k;
    ans[p]=ans[p]+k*(r-l+1);
}
inline void push_down(ll p,ll l,ll r)
{
    ll mid=(l+r)>>1;
    f(ls(p),l,mid,tag[p]);
    f(rs(p),mid+1,r,tag[p]);
    tag[p]=0;
}
inline void update(ll nl,ll nr,ll l,ll r,ll p,ll k)
{
    if(nl<=l&&r<=nr)
    {
        ans[p]+=k*(r-l+1);
        tag[p]+=k;
        return ;
    }
    push_down(p,l,r);
    ll mid=(l+r)>>1;
    if(nl<=mid)update(nl,nr,l,mid,ls(p),k);
    if(nr>mid) update(nl,nr,mid+1,r,rs(p),k);
    push_up(p);
}
ll query(ll q_x,ll q_y,ll l,ll r,ll p)
{
    ll res=0;
    if(q_x<=l&&r<=q_y)return ans[p];
    ll mid=(l+r)>>1;
    push_down(p,l,r);
    if(q_x<=mid)res+=query(q_x,q_y,l,mid,ls(p));
    if(q_y>mid) res+=query(q_x,q_y,mid+1,r,rs(p));
    return res;
}
int main()
{
    ll a1,b,c,d,e,f;
    scan();
    build(1,1,n);
    while(m--)
    {
        scanf("%lld",&a1);
        switch(a1)
        {
            case 1:{
                scanf("%lld%lld%lld",&b,&c,&d);
                update(b,c,1,n,1,d);
                break;
            }
            case 2:{
                scanf("%lld%lld",&e,&f);
                printf("%lld\n",query(e,f,1,n,1));
                break;
            }
        }
    }
    return 0;
}*/
/*
#include<bits/stdc++.h>
#define MAXN 100005
#define LL long long
using namespace std;
unsigned long long n,m,a[MAXN],ans[MAXN<<2],tag[MAXN<<2];
void scan(){
	scanf("%llu%llu",&n,&m);
	for(LL i=1;i<=n;i++)scanf("%llu",&a[i]);
}
inline int ls(int p){return p<<1;}
inline int rs(int p){return p<<1|1;}
//void push_up_sum(int p){t[p]=min(t[ls(p)]+t[rc(p)]);}
//void push_up_min(int p){t[p]=min(t[lc(p)],t[rc(p)]);}
inline void push_up(LL p){ans[p]=ans[ls(p)]+ans[rs(p)];}
void build(LL p,LL l,LL r){
	if(l==r){ans[p]=a[l];return;}
	LL mid=(l+r)>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
}
inline void change(LL p,LL l,LL r,LL k){
	tag[p]=tag[p]+k;
	ans[p]=ans[p]+k*(r-l+1);
}
inline void push_down(LL p,LL l,LL r){
	LL mid=(l+r)>>1;
	change(ls(p),l,mid,tag[p]);
	change(rs(p),mid+1,r,tag[p]);
	tag[p]=0;
}
inline void update(LL nl,LL nr,LL l,LL r,LL p,LL k){
	if(nl<=l&&nr>=r){
		ans[p]+=k*(r-l+1);
		tag[p]+=k;
		return;
	}
	push_down(p,l,r);
	LL mid=(l+r)>>1;
	if(nl<=mid)update(nl,nr,l,mid,ls(p),k);
	if(nr>mid)update(nl,nr,mid+1,r,rs(p),k);
	push_up(p);
}
LL query(LL q_x,LL q_y,LL l,LL r,LL p){
	LL res=0;
	if(q_x<=l&&r>=q_y)return ans[p];
	LL mid=(l+r)>>1;
	push_down(p,l,r);
	if(q_x<=mid) res+=query(q_x,q_y,l,mid,ls(p));
	if(q_y>mid) res+=query(q_x,q_y,mid+1,r,rs(p));
	return res;
}
signed main(){
	LL a,b,c,d,e,f;
	scan();
	build(1,1,n);
	while(m--){
		scanf("%llu",&a);
		switch(a){
			case 1:{
				scanf("%llu%llu%llu",&b,&c,&d);
				update(b,c,1,n,1,d);
				break;
			}
			case 2:{
				scanf("%llu%llu",&e,&f);
				printf("%llu\n",query(e,f,1,n,1));
				break;
			}
		}
	}
	return 0;
}*/
