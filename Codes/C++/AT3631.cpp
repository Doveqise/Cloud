#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,int>P;
const int maxn=2e5+5;
long long n,x[maxn],s[maxn],m;
signed main(){
    priority_queue<P>q;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&x[i],&s[i]);
        s[i]+=s[i-1];q.push(P(s[i]-x[i],i));}
    for(int i=1,flag;i<=n;i++){
        flag=1;while(flag){
            P p=q.top();
            if(p.second<i)q.pop();
            else{m=max(m,p.first-s[i-1]+x[i]);flag=0;}
        }
    }
    printf("%lld\n",m); return 0;
}