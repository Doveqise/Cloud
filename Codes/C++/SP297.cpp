#include<bits/stdc++.h>
using namespace std;
int n,m,t,a[100001];
bool judge(int x){
    int x1=a[1],cnt=1;
    for(int i=2;i<=n;++i)
        if (a[i]-x1>=x){
            ++cnt;x1=a[i];
            if(cnt==m)return 1;
        }
    return 0;
}
int main(){
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d", &a[i]);
        sort(a+1,a+n+1);
        int l=0,r=10000000; 
        while(l+1<r){
            int mid=(l+r)>>1; 
            if(judge(mid))l=mid;
            else r=mid;} 
        printf("%d\n",l);
    }
    return 0;
}

