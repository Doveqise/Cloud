#include<bits/stdc++.h>
using namespace std;
const int MODD=19260817;
struct mat{long long M[4][4];}ANS,TMP;
void pre(){
	ANS.M[0][0]=ANS.M[0][1]=ANS.M[0][2]=ANS.M[1][0]=ANS.M[2][1]=1;
    ANS.M[1][1]=ANS.M[1][2]=ANS.M[2][0]=ANS.M[2][2]=0;
	TMP.M[0][0]=TMP.M[0][1]=TMP.M[0][2]=TMP.M[1][0]=TMP.M[2][1]=1;
    TMP.M[1][1]=TMP.M[1][2]=TMP.M[2][0]=TMP.M[2][2]=0;
}
mat mul(mat a,mat b){
	mat tmp;memset(tmp.M,0,sizeof(tmp.M));
    for(int i=0;i<3;i++)for(int j=0;j<3;j++)for(int k=0;k<3;k++) tmp.M[i][j]+=a.M[i][k]*b.M[k][j],tmp.M[i][j]%=MODD;
    return tmp;
}
void quick_pow_mat(int p){for(;p;TMP=mul(TMP,TMP),p>>=1)if(p&1)ANS=mul(ANS,TMP);}
signed main(){
	int t;scanf("%d",&t);
	for(int ti=0;ti<t;ti++){
		int n;scanf("%d",&n);
		pre();quick_pow_mat(n-1);
		printf("%lld\n",(ANS.M[0][0]+ANS.M[0][1])%MODD);
	}
	return 0;
}
