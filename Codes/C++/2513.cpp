#include<bits/stdc++.h>
using namespace std;
int p=10000,f[1010][1010];
int main(){
    int n,k;scanf("%d%d",&n,&k);
    f[1][0]=1;
    for(int i=2;i<=n;i++){
        int sum=0;
        for(int j=0;j<=k;j++){
            sum=(sum+f[i-1][j])%p;
            f[i][j]=sum;
            if(j+1>=i)sum=(sum-f[i-1][j-i+1]%p+p)%p;
        }
    }
    printf("%d\n",f[n][k]);
    return 0;
}
