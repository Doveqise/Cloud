#include<bits/stdc++.h>
using namespace std;
int a[55],num[105],f,sum,ans,n;
void dfs(){
    if(sum+f>=ans) return;
    if((!f)&&a[1]==1){ans=sum;return;}
    for(int i=2;i<=n;++i){
        if(i!=n)f+=(abs(a[1]-a[1+i])!=1)-(abs(a[i+1]-a[i])!=1);
        for(int j=1;j<i+1-j;++j)swap(a[j],a[i+1-j]);
        sum++;dfs();sum--;
        for(int j=1;j<i+1-j;++j)swap(a[j],a[i+1-j]);
        if(i!=n)f-=(abs(a[1+i]-a[1])!=1)-(abs(a[i+1]-a[i])!=1);}
} 
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){scanf("%d",&a[i]);num[a[i]]++;}
    for(int i=1;i<=100;i++)num[i]+=num[i-1];
    for(int i=1;i<=n;i++)a[i]=num[a[i]];
    ans=2*n-2;
    for(int i=1;i<n;++i) if(abs(a[i]-a[i+1])!=1)f++;
    dfs();printf("%d",ans);
    return 0;
}
