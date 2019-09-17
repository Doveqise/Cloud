#include<bits/stdc++.h>
#define LL long long
#define mOd 1000000007
using namespace std;
LL n,k;
struct mat{LL a[105][105];}p,pp;
mat X(mat x,mat y){
    mat tmp;
    for(LL i=1;i<=n;i++) for(LL j=1;j<=n;j++) tmp.a[i][j]=0;
    for(LL i=1;i<=n;i++) for(LL j=1;j<=n;j++)  for(LL k=1;k<=n;k++) tmp.a[i][j]=(tmp.a[i][j]+(x.a[i][k]*y.a[k][j])%mOd)%mOd;
    return tmp;
}
mat quick_pow(LL kk){
    mat ans;
    for(LL i=1;i<=n;i++){ans.a[i][i]=1;}
    while(kk){
        if(kk%2) ans=X(ans,p);
        kk>>=1;
        p=X(p,p);
    }
    return ans;
}
int main(){
    scanf("%lld%lld",&n,&k);
    for(LL i=1;i<=n;i++) for(LL j=1;j<=n;j++) scanf("%lld",&p.a[i][j]);
    pp=quick_pow(k);
    for(LL i=1;i<=n;i++){for(LL j=1;j<=n;j++) printf("%lld ",pp.a[i][j]);puts("");}
    return 0;
}
