#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e2+5;
const int mod = 2009;
char str[maxn];
int n,nn,T;
struct mat{
    int a[maxn][maxn];
    void clear()
    {
    	memset(a,0,sizeof(a));
	}
    void mk()
    {
    	clear();
    	for(int i=1;i<=nn;i++)
    		a[i][i]=1;
	}
	mat operator *(mat b){
    	mat re;
    	re.clear();
    	for(int i=1;i<=nn;i++)
        	for(int j=1;j<=nn;j++)
            	for(int k=1;k<=nn;k++)
                	re.a[i][j]=(re.a[i][j]+a[i][k]*b.a[k][j]%mod)%mod;
   		return re;
	}
	mat operator ^(int b){
    	mat ret;
    	ret.mk();
    	while(b)
		{
        	if(b&1)
				ret=ret*(*this);
    	    (*this)=(*this)*(*this);
        	b>>=1;
    	}
    	return ret;
	}
}a;
signed main()
{
    scanf("%d%d",&n,&T);
    nn=n*9;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=8;j++)
            a.a[9*(i-1)+j][9*(i-1)+j+1]=1;
    for(int i=1;i<=n;i++)
	{
        scanf("%s",str+1);
        for(int j=1;j<=n;j++)
            if(str[j]>'0')
                a.a[9*(i-1)+str[j]-'0'][9*(j-1)+1]=1;
    }
    a=a^T;
    printf("%d",a.a[1][nn-8]);
    return 0;
}
