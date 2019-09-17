#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    int t,g,m;
}a[50],s[50];
bool cmp(node a,node b){return a.t<b.t;}
int top,n;ll ans;
int solve(ll k,ll t,ll g){
    ll a=1,b=k-t,c=g-k*t;
    ll det=pow(b,2)-4*a*c;
    if(det<0)return -19260817;
    return (floor((-b+sqrt(det))/2/a)+1e-7);
}
bool judge(){
    ll p=1,g=0;
    for(int i=1;i<=top;i++){
        ll sum=0;int t=s[i].t-s[i-1].t;
        for(int j=i;j<=top;j++){sum+=s[j].g;if(sum>g)t=min(t,solve(p,s[j].t-s[i-1].t,sum-g));}
        if(t<0)return false;
        p+=t;g+=p*(s[i].t-s[i-1].t-t);g-=s[i].g;}
    return true;}
int main(){
    scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i].t,&a[i].g,&a[i].m);
    sort(a+1,a+1+n,cmp);
    int lim=pow(2,n);
    for(int i=1;i<lim;i++){
        ll re=0;top=0;
        for(int j=1;j<=n;j++)if(i&(1<<(j-1))){s[++top]=a[j];re+=a[j].m;}
        if(judge())ans=max(ans,re);}
    printf("%lld",ans);
    return 0;
}
