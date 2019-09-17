#include <bits/stdc++.h>
using namespace std;
long long n,m,num,q,i;
string s[51];
int main(){
    scanf("%lld%lld",&n,&m);
    m/=2;
    for(i=1;i<=n;i++) cin>>s[i];
    for(i=n;i>=1;i--){
        q*=2;
        if(s[i]=="halfplus") num+=1;
        q+=num;
    }
    q*=m;
    printf("%lld",q);
    return 0;
}
