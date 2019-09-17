#include<bits/stdc++.h>
using namespace std;
int n,num=0;
int ans[50005];
struct P{int val,id;}a[50005],b[50005];
bool cmp(const P &l,const P &r){
    return l.val<r.val;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i].val);a[i].id=i;
        scanf("%d",&b[i].val);b[i].id=i;
    }
    sort(a+1,a+n+1,cmp);
    sort(b+1,b+n+1,cmp);
    for(int i=1,j=1;i<=n;++i){
        if(j<=n)j++;
        if(!ans[b[i].id])ans[b[i].id]=++num;
        while(a[j].val<=b[i].val&&j<=n)j++;
        ans[a[j].id]=ans[b[i].id];
    }
    printf("%d\n",num);
    for(int i=1;i<=n;++i)printf("%d\n",ans[i]);
    return 0;
}
