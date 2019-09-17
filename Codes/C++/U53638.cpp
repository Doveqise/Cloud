#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;  
namespace Mker
{
    unsigned long long SA,SB,SC;
    void init(){scanf("%llu%llu%llu",&SA,&SB,&SC);}
    unsigned long long rand()
    {
        SA^=SA<<32,SA^=SA>>13,SA^=SA<<1;
        unsigned long long t=SA;
        SA=SB,SB=SC,SC^=t^SA;return SC;
    }
}
struct mat  
{  
    unsigned long long a[2][2];  
}first;  

mat mat_mul(mat x,mat y)
{  
    mat res;
    memset(res.a,0,sizeof(res.a));  
    for(int i=0;i<2;i++)  
        for(int j=0;j<2;j++)  
        	for(int k=0;k<2;k++){  
        		res.a[i][j]+=x.a[i][k]*y.a[k][j];  
        		res.a[i][j]%=MOD;
    		}  
    return res;  
}
mat pow(unsigned long long n){  
    mat c,res;
    memset(res.a,0,sizeof(res.a));  
    c.a[0][0]=233;c.a[0][1]=666;c.a[1][0]=1;c.a[1][1]=0;
    for(unsigned long long i=0;i<2;i++) res.a[i][i]=1;
    while(n){
        if(n&1) res=mat_mul(res,c);
        c=mat_mul(c,c);
        n>>=1;
    }
    return res;
}
int main(){
	unsigned long long t,n,ans=0;
	scanf("%llu",&t);
	Mker::init();
	first.a[0][0]=1;
	first.a[1][0]=0;
	for(unsigned long long i=0;i<t;i++){
		n=Mker::rand();
		ans^=mat_mul(first,pow(n-1)).a[0][0];
	}
	printf("%llu",ans);
	return 0;
} 
