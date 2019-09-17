#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
struct mat{long long a[2][2]; }base,ans;
mat mul(mat A,mat B){
    mat res;memset(res.a,0,sizeof(res.a));
    for(int i=0;i<2;i++)for(int j=0;j<2;j++)for(int k=0;k<2;k++)res.a[i][j]=(res.a[i][j]+A.a[i][k]%mod*B.a[k][j]%mod)%mod;
    return res;
}
int main(){
    long long n,t;scanf("%lld",&t);
    while(t--){scanf("%lld",&n);n--;
        base.a[0][0]=0;base.a[0][1]=base.a[1][0]=base.a[1][1]=1;
        ans.a[0][0]=2;ans.a[0][1]=1;ans.a[1][0]=ans.a[1][1]=0;
        while(n){if(n%2)ans=mul(ans,base);base=mul(base,base);n>>=1;}
        printf("%lld\n",ans.a[0][1]%mod);}
    return 0;
}
