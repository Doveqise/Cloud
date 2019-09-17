/*#include<bits/stdc++.h>
using namespace std;
struct num{
	int xuhao;
	int shuzi;
}a[10005];
bool cmp(num a,num b){return a.shuzi<b.shuzi;}
int main(){
	int n,k,ans=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].shuzi);
		a[i].xuhao=i;
	}
	sort(a,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(ans+a[i].shuzi<=k)ans+=a[i].shuzi;
		else{
			printf("%d\n",i);
			for(int j=1;j<=i;j++)printf("%d ",a[j].xuhao);
			return 0;
		}
		if(i==n)
		{
			printf("%d\n",n);
			for(int j=1;j<=n;j++)printf("%d ",a[j].xuhao);
			return 0;
		}
	}
}
*/
#include<bits/stdc++.h>
using namespace std;
int n,k,c[105],f[10005],x,y; 
int pd[105][10005];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i) scanf("%d",&c[i]);
    for(int i=1;i<=n;++i)
    {
        for(register int j=k;j>=c[i];--j) 
        {
            if(f[j-c[i]]>=f[j]) 
            {
                f[j]=f[j-c[i]]+1;
                pd[i][j]=1; 
            }
        }
    }
    printf("%d\n",f[k]); 
    x=n,y=k; 
    while(x>0&&y>0)
    {
        if(pd[x][y]) 
        {
            printf("%d ",x); 
            y-=c[x];
        }
        --x; 
    }
    return 0;
}
