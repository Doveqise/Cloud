#include<bits/stdc++.h>
using namespace std;
int n,m,t,lim,tong[10000005]={1,1};
void scan(){scanf("%d%d",&n,&m);lim=(int)sqrt(n+0.5);}
void solve(){for(int i=2;i<=lim;i++){if(!tong[i]) for(int j=i*i;j<=n;j+=i) tong[j]=1;}}
void print(){if(m){scanf("%d",&t);if(tong[t])printf("No\n");else printf("Yes\n");--m;print();}}
signed main(){scan();solve();print();}
