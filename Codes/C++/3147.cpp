#include<bits/stdc++.h>
using namespace std;
int f[60][262144+5],ans;
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){int t;scanf("%d",&t);f[t][i]=i+1;}
    for(int i=2;i<=58;i++) for(int j=1;j<=n;j++){
		if(!f[i][j]) f[i][j]=f[i-1][f[i-1][j]];
        if(f[i][j]) ans=i;}
    printf("%d\n",ans);
    return 0;
}
