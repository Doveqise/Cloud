#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x[500010],s[500010],dp[500010],n,d,k;
bool work(ll g){
     memset(dp,0,sizeof(dp));
     ll maxx=d+g,mini=max((ll)1,d-g);
     deque<int> q;int j=0;
     for(int i=1;i<=n;i++){
        for(;x[i]>=x[j]+mini;++j){
			while(!q.empty()&&dp[j]>dp[q.back()])q.pop_back();
            q.push_back(j); }
        while(!q.empty()&&x[q.front()]+maxx<x[i])q.pop_front();
        if(q.empty())dp[i]=-9999999999; else dp[i]=s[i]+dp[q.front()];
		if (dp[i]>=k)return 1;}return 0;}
int main(){
    cin>>n>>d>>k;ll tmp=0;
    memset(x,0,sizeof(x)); memset(s,0,sizeof(s));
    for(int i=1;i<=n;i++){ scanf("%lld%lld",&x[i],&s[i]); if(s[i]>0)tmp+=s[i]; }
    if (tmp<k){cout<<-1;return 0;};ll l=0,r=1e4,mon=x[n];
    while(l<=r){ll mid=(r+l)/2; if (work(mid)){mon=mid;r=mid-1;} else l=mid+1;}
    cout<<mon;return 0;
}
