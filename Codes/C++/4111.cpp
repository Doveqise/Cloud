#include<bits/stdc++.h>
using namespace std;
const int N=15,M=105;
const int mod=1e9;
char s[N][N];
int n,m,a[M][M],id[N][N];
void add(int u,int v){--a[u][v],--a[v][u],++a[u][u],++a[v][v];}
int Gauss(int n) {
    int ans=1;
    for(int i=1;i<=n;++i) {
        for(int k=i+1;k<=n;++k) {
            while(a[k][i]) {
                int d=a[i][i]/a[k][i];
                for(int j=i;j<=n;++j) a[i][j]=(a[i][j]-1LL*d*a[k][j]%mod+mod)%mod;
                swap(a[i],a[k]),ans=-ans;
            }
        }
        ans=1LL*ans*a[i][i]%mod,ans=(ans+mod)%mod;
    }
    return ans;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i) scanf("%s",s[i]+1);
    int idx=0;
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) if(s[i][j]=='.') id[i][j]=++idx;
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) if(s[i][j]=='.') {
        if(id[i-1][j]) add(id[i][j],id[i-1][j]);
        if(id[i][j-1]) add(id[i][j],id[i][j-1]);
    }
    printf("%d\n",Gauss(idx-1));
    return 0;
}
