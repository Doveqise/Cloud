#include<bits/stdc++.h>
using namespace std;
long long f[105][500][500],sit[5000],n,k=0,ans=-1,m,ma[5000],sum[5000];
int main(){
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++){scanf("\n");for(int j=1;j<=m;j++){
            char s;ma[i]=ma[i]<<1;
            scanf("%c",&s);if(s=='H')ma[i]=ma[i]|1;}}
    for(int i=0;i<(1<<m);i++) if(!(i&(i<<2))&&!(i&(i<<1))){
        sit[++k]=i;int t=i;
        while(t){sum[k]+=t%2;t/=2;}}
    for(int i=1;i<=k;i++)if(!(sit[i]&ma[1]))f[1][1][i]=sum[i];
    for(int i=1;i<=k;i++) if(!(sit[i]&ma[2]))
        for(int j=1;j<=k;j++) if(!(ma[1]&sit[j])&&!(sit[i]&sit[j]))f[2][j][i]=sum[i]+sum[j];
    for(int i=3;i<=n;i++) for(int j=1;j<=k;j++) if(!(ma[i]&sit[j]))
		for(int l=1;l<=k;l++)
			if(!(sit[j]&sit[l])&&!(ma[i-1]&sit[l])) for(int p=1;p<=k;p++)
                if(!(sit[p]&sit[l])&&!(ma[i-2]&sit[p])&&!(sit[p]&sit[j])) f[i][l][j]=max(f[i][l][j],f[i-1][p][l]+sum[j]);
    for(int i=1;i<=k;i++)for(int j=1;j<=k;j++)ans=max(f[n][j][i],ans);
    printf("%lld",ans);}
