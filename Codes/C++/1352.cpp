#include<bits/stdc++.h>
using namespace std;
int f[5][6000];
int n,a,b,root;
int ne[12000],po[12000],ru[12000];
void dp(int x){
    for(int i=po[x];i;i=ne[i]){
		dp(i);
        f[1][x] = max(max(f[1][x],f[0][i]+f[1][x]),f[0][i]);
        f[0][x] = max(max(f[0][x],f[1][i]+f[0][x]),max(f[1][i],f[0][i]));}
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&f[1][i]);
    for(int i=1;i<=n;i++){scanf("%d%d",&a,&b);
         ru[a]++;ne[a]=po[b];po[b]=a;}
    for(int i=1;i<=n;i++) if(!ru[i]){root=i;break;}
    dp(root);   
    printf("%d",max(f[1][root],f[0][root]));
    return 0;
}
