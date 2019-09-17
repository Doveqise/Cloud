#include<bits/stdc++.h>
using namespace std;
int f[1005][1005],sum[10005];
int main(){
    int n,k;scanf("%d%d",&n,&k);
    f[0][0]=1;
    for(int i=0;i<=k;i++) sum[i]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++)
            if(j>=i) f[i][j]=(sum[j]-sum[j-i]+10000)%10000;
            else f[i][j]=sum[j]%10000; 
        sum[0]=f[i][0]%10000;
        for(int j=1;j<=k;j++)sum[j]=(f[i][j]+sum[j-1])%10000;
    }
    printf("%d",f[n][k]);
}
