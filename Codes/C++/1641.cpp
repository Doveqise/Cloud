#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL read(){
    int res=0,ch=getchar();
    while(!isdigit(ch)&&ch!=EOF)ch=getchar();
    while(isdigit(ch)){res=(res*10+ch-'0');ch=getchar();}
    return res;
}
LL quick_pow(LL a,LL k,LL p){
    LL ret=1;
    for(;k;k>>=1,a=a*a%p)if(k&1)ret=ret*a%p;
    return ret;
}
LL sol(LL n,LL m,LL p){
	LL ans1=1,ans2=1;
    if(m>n)return 0;
    if(n>=p)return sol(n/p,m/p,p)*sol(n%p,m%p,p)%p;
		for(int i=m+1;i<=n;i++) ans1=ans1*i%p;
		for(int i=1;i<=n-m;i++) ans2=ans2*i%p;
		return(ans1*quick_pow(ans2,p-2,p))%p;
}
signed main(){
    LL n=read(),m=read();
    printf("%lld",(sol(n+m,m,20100403)-sol(n+m,m-1,20100403)+20100403)%20100403);
	return 0;
}
