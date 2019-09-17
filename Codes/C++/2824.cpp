#include<bits/stdc++.h>
using namespace std;
int t[100000000],a[100005];
int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int l,r,opt,sum,minn=999999999,maxx=-99999999;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&opt,&l,&r);
        for(int j=l;j<=r;j++){t[a[j]]++;minn=min(minn,a[j]);maxx=max(maxx,a[j]);}
        if(opt==0){sum=l;for(int j=minn;j<=maxx;j++)while(t[j]>0){a[sum]=j;sum++;t[j]--;}}
        else{sum=l;for(int j=maxx;j>=minn;j--)while(t[j]>0){a[sum]=j;sum++;t[j]--;}}
    }
    int k;scanf("%d",&k);printf("%d",a[k]);
    return 0;
}
