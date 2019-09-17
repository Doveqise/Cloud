#include<bits/stdc++.h>
using namespace std;
const int mod=100000000;
int res[15][15],f[18],n,m,dp[18][1000005],ans;
bool judge(int s){return ((!(s&(s>>1)))&&(!(s&(s<<1))));}
signed main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++) for(int j=1,x;j<=n;j++){scanf("%d",&x);(f[i]<<=1)|=x;}
    int s=(1<<n)-1; dp[0][0]=1;
    for(int i=1;i<=m;i++)
        for(int j=0;j<=s;j++)
            if(judge(j)&&((f[i]&j)==j))
                for(int k=0;k<=s;k++) if(!(k&j))(dp[i][j]+=dp[i-1][k])%=mod;
    for(int i=0;i<=s;i++)(ans+=dp[m][i])%=mod;
    printf("%d",ans%mod);
    return 0;
}

/*
#include<cstdio>
#include<cctype>
#define mod 100000000
#define R register
using namespace std;
inline void in(int &x)
{
    int f=1;x=0;char s=getchar();
    while(!isdigit(s)){if(s=='-')f=-1;s=getchar();}
    while(isdigit(s)){x=x*10+s-'0';s=getchar();}
    x*=f;
}
int res[15][15],f[18],n,m,dp[18][1<<15],ans;
inline bool ok(int state)
{
    return ((state&(state>>1))==0 and (state&(state<<1))==0);
}
int main()
{
    in(n),in(m);
    for(R int i=1;i<=n;i++)
        for(R int j=1,x;j<=m;j++)
        {
            in(x);
            (f[i]<<=1)|=x;
        }
    int state=(1<<m)-1;
    dp[0][0]=1;
    for(R int i=1;i<=n;i++)
        for(R int j=0;j<=state;j++)
            if(ok(j) and (f[i]&j)==j)
                for(R int k=0;k<=state;k++)
                    if((k&j)==0)
                        (dp[i][j]+=dp[i-1][k])%=mod;
    for(R int i=0;i<=state;i++)
        (ans+=dp[n][i])%=mod;
    printf("%d",ans%mod);
}
*/
