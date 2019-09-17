#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int X=2147483647;
const int N=1e6+5,L=30;
int n,k,t[30*N][2],cnt,a[30*N];
int solve(int s){
    int v=1,sum=0,p=k,q=s;
    for(int i=0;i<=L;i++){if(!v)break;
        if(p>>L)v=t[v][1^(q>>L)];
        else{sum+=a[t[v][1^(q>>L)]];v=t[v][q>>L];}
        p<<=1;q<<=1;p&=X;q&=X;}v=1;++a[v];
    for(int i=0;i<=L;i++){
        if(t[v][s>>L])v=t[v][s>>L];
        else ++cnt,t[v][s>>L]=cnt,v=cnt;
        s<<=1;s&=X;++a[v];}
    return sum;}
int main(){
    int p,s=0;scanf("%d%d",&n,&k);
    cnt=1;k-=1;ll ans=solve(s);
    for(int i=1;i<=n;i++){scanf("%d",&p);s^=p;ans+=solve(s);}
    printf("%lld",ans);
    return 0;
}
