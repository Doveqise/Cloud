#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int maxn = 2e3+5;
ll n,m,ans,num,t1,t2;
ll a[maxn],b[maxn],s1[maxn],s2[maxn];
ll quick_pow(ll x,ll y)
{
    ll ret=1;
    while(y)
    {
        if(y&1)ret=ret*x%mod;
        x=x*x%mod;
        y>>=1;
    }#include<cstring>
using namespace std;

int main(){
    int n,a,b,ans=0,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        a<0?ans++:sum++;
    }
    if(ans==1||sum==1||ans==0||sum==0)cout<<"Yes";
    else cout<<"No";
    return 0;
}
    return ret;
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    num=n*(n+1)/2%mod;
    num=num*m%mod*(m+1)%mod;
    num=num*quick_pow(2,mod-2)%mod;
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        a[i]+=a[i-1];
    }
    for(ll i=1;i<=m;i++)
    {
        scanf("%lld",&b[i]);
        b[i]+=b[i-1];
    }
    for(ll i=1;i<=m;i++)
        for(ll j=i;j<=m;j++)
            s2[++t2]=b[j]-b[i-1];
    for(ll i=1;i<=n;i++)
        for(ll j=i;j<=n;j++)
            s1[++t1]=a[j]-a[i-1];
    sort(s1+1,s1+1+t1);
    sort(s2+1,s2+1+t2);
    ll l=0;
    for(ll i=1;i<=t1;i++)
    {
        while(s2[l+1]<s1[i]&&l+1<=t2)
            l++;
        ans+=l;
        ans=ans>=mod?ans-mod:ans;
    }
    printf("%lld\n",ans*quick_pow(num,mod-2)%mod);
    return 0;
}