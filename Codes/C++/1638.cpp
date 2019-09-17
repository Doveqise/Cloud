#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005,maxm=2005;
int cnt[maxm];
int n,m,a[maxn];
int main(){
    scanf("%d%d",&n,&m);
    int s=0,t=0,num=0,res=n,l=1,r=n;
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    while(1){while(t<n&&num<m) if(cnt[a[t++]]++==0)num++;
    if(num<m) break;
    if(res>t-s) {res=t-s;l=s+1;r=t;}
    if(!(--cnt[a[s++]]))num--;}
    printf("%d %d",l,r);
    return 0;
}
