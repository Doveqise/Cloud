#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll n,W[20],B[20];
ll China(){
    ll tot=1,res=0;
    for(ll i=0;i<n;i++) tot*=W[i];
    for(ll i=0;i<n;i++){
        ll m=tot/W[i];
        for(ll j=1;;j++) if((m*j)%W[i]==1){res+=m*j*B[i];res%=tot;break;}
    }
    return res>0?res:res+tot;
}
signed main(){
    scanf("%lld",&n);
    for(ll i=0;i<n;i++)scanf("%lld%lld",&W[i],&B[i]);
    printf("%d",China());
    return 0;
}