/*#include<bits/stdc++.h>
using namespace std;
const int MOD=19260817;
int a[1005][1005];
int C(int n,int m){
	if(a[n][m]) return a[n][m]%MOD;
    if(n<m) return 0;
    if(n==m||m==0) return a[n][m]=1;
    if(m==1){a[n][m]=n;return n;}
    else return a[n][m]=C(n-1,m-1)+C(n-1,m)%MOD;
}
signed main(){
	int q;scanf("%d",&q);
	while(q--){
		int num=0;
		int n,m;scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) for(int j=i;j<=m;j++){num+=C(j,i);num%=MOD;}
		printf("%d\n",num);
	}
}*/
#include<bits/stdc++.h>
using namespace std;
int C[1005][1005],tot[1005][1005];
const int MOD=19260817;
int q,n,m;
int main(){
    scanf("%d",&q);
    for(int i=0;i<=1001;i++){C[i][0]=1;C[i][i]=1;}
    for(int i=2;i<=1001;i++)
        for(int j=1;j<i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
    for(int i=1;i<=1001;i++)
        for(int j=1;j<=1001;j++)
            tot[i][j]=((C[i][j]-tot[i-1][j-1]+MOD)%MOD+tot[i-1][j]+tot[i][j-1])%MOD;
    while(q--){scanf("%d%d",&n,&m);printf("%d\n",tot[m][n]);}
    return 0;
}
