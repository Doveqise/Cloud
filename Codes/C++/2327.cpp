#include<bits/stdc++.h>
#define N 10005
using namespace std;
int n;
int g[N];
int f[N][2][2];
signed main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&g[i]);
    f[0][0][0]=f[0][0][1]=1;
    for(int i=1;i<=n;i++)
        switch(g[i])
        {
            case 0:
            f[i][0][0]+=f[i-1][0][0];
            break;
            case 1:
            f[i][0][0]+=f[i-1][1][0];
            f[i][1][0]+=f[i-1][0][1];
            f[i][0][1]+=f[i-1][0][0];
            break;
            case 2:
            f[i][1][1]+=f[i-1][0][1];
            f[i][0][1]+=f[i-1][1][0];
            f[i][1][0]+=f[i-1][1][1];
            break;
            case 3:
            f[i][1][1]+=f[i-1][1][1];
            break;
        }
    printf("%d",f[n][0][0]+f[n][1][0]);
    return 0;
}