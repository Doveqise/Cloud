#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int st[N][20],dp[N],num[N];
int n,q;
void rmq(){
    for(int i=1;i<=n;i++) st[i][0]=dp[i];
    int k=log((double)(n+1))/log(2.0);
    for(int j=1;j<=k;j++)for(int i=1;i+(1<<j)-1<=n;i++) st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);}
int Query(int l,int r){
    if(l>r) return 0;    
    int k=log((double)(r-l+1))/log(2.0);    
    return max(st[l][k],st[r-(1<<k)+1][k]);} 
signed main(){    
    while(scanf("%d",&n)!=EOF&&n){scanf("%d",&q);dp[1]=1;
        for(int i=1;i<=n;i++){scanf("%d",&num[i]);
            if(i>1) dp[i]=(num[i]==num[i-1]?dp[i-1]+1:1);}
        rmq();
        while(q--){
            int a,b;scanf("%d%d",&a,&b);
            int c=a;
            while(c<=b&&num[c]==num[c-1]) c++;
            printf("%d\n",max(Query(c,b),c-a));}}   
    return 0;
}
