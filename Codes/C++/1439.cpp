#include<bits/stdc++.h>
using namespace std;
int a[100005],idx[100005];
int main(){
    int n;scanf("%d",&n);memset(a,0x3f,sizeof(a));
    for(int i=1;i<=n;i++){int t;scanf("%d",&t);idx[t]=i;}
    for(int i=1;i<=n;i++){int t;scanf("%d",&t);int x=idx[t];*lower_bound(a+1,a+n+1,x)=x;}
    printf("%lld",lower_bound(a+1,a+n+1,a[0])-a-1);
    return 0;}
