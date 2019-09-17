#include<bits/stdc++.h>
using namespace std;
const int N=200001;
struct node{int x,y,z,id;}a[N];
int c[N<<2],k,n,b[N],bj[N],f[N];
int lowbit(int x){return x&(-x);}
void add(int x,int v){while(x<=k) c[x]+=v,x+=lowbit(x);}
int sum(int x){
    int ans=0;
    while(x) ans+=c[x],x-=lowbit(x);
    return ans;}
bool cmp1(const node & a , const node & b ){
    if(a.x!=b.x) return a.x<b.x;
    if(a.y!=b.y) return a.y<b.y;
    return a.z<b.z;}
bool cmp2(const node & a , const node & b ){
    if(a.y!=b.y) return a.y<b.y;
    if(a.z!=b.z) return a.z<b.z;
    return a.x<b.x;}
void cdq(int l,int r){
    if(l==r) return;
    int mid=(l+r)>>1,flag;cdq(l,mid),cdq(mid+1,r);
    sort(a+l,a+r+1,cmp2);
    for(int i=l;i<=r;i++) (a[i].x<=mid)?add(a[i].z,1),flag=i:b[a[i].id]+=sum(a[i].z);
    for(int i=l;i<=r;i++) if(a[i].x<=mid) add(a[i].z,-1);
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z),a[i].id=i;
    sort(a+1,a+1+n,cmp1);
    for(int i=1;i<=n;){
        int j=i+1;
        while(j<=n&&a[j].x==a[i].x&&a[j].y==a[i].y&&a[j].z==a[i].z) j++;
        while(i<j) bj[a[i].id]=a[j-1].id,i++;
    }
    for(int i=1;i<=n;i++) a[i].x=i;
    cdq(1,n);
    for(int i=1;i<=n;i++) f[b[bj[a[i].id]]]++;
    for(int i=0;i<n;i++) printf("%d\n",f[i]);
}
