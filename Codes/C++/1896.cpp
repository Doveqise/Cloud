#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,top,ans,c[1050],s[1050];
void dfs(int cond,int sum,int pos){
    if(pos>n){c[++top]=cond;s[top]=sum;return;}//��
    dfs(cond+(1<<(pos-1)),sum+1,pos+2);//��
    dfs(cond,sum,pos+1);//��
}
ll f[11][1050][31];
int main(){
    scanf("%lld%lld",&n,&k);dfs(0,0,1);//do
    for(int i=1;i<=top;++i) f[1][c[i]][s[i]]=1ll;//��
    for(int i=2;i<=n;++i) for(int j=1;j<=top;++j) for(int h=1;h<=top;++h){
		if(c[j]&c[h]) continue;//��
		if((c[j]<<1)&c[h]) continue;//б
		if((c[j]>>1)&c[h]) continue;//б
		for(int sum=k;sum>=s[j];--sum) 
			f[i][c[j]][sum]+=f[i-1][c[h]][sum-s[j]];//dp
	}
    for(int i=1;i<=top;++i) ans+=f[n][c[i]][k];//��
    printf("%lld",ans);
    return 0;
}
