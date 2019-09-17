#include<bits/stdc++.h>
using namespace std;
const int MODD=1e9+7;
struct mat{long long M[4][4];}ANS,TMP;
void pre(){
	memset(ANS.M,0,sizeof(ANS.M));
	for(int i=1;i<=3;i++) ANS.M[i][i]=1;
	memset(TMP.M,0,sizeof(TMP.M));
	TMP.M[1][1]=TMP.M[1][3]=TMP.M[2][1]=TMP.M[3][2]=1;
}
mat mul(mat a,mat b){
	mat tmp;memset(tmp.M,0,sizeof(tmp.M));
	for(int i=1;i<=3;i++) for(int j=1;j<=3;j++) for(int k=1;k<=3;k++) {tmp.M[i][j]+=((a.M[i][k]%MODD)*(b.M[k][j]%MODD));tmp.M[i][j]%=MODD;}
	return tmp;
}
void quick_pow_mat(int p){for(;p;TMP=mul(TMP,TMP),p>>=1)if(p&1)ANS=mul(ANS,TMP);}
signed main(){
	int t;scanf("%d",&t);
	for(int ti=0;ti<t;ti++){
		int n;scanf("%d",&n);
		if(n<=3&&n>=0) puts("1");
		else{
			pre();
			quick_pow_mat(n);
			printf("%lld\n",ANS.M[2][1]);
		}
	}
	return 0;
}
