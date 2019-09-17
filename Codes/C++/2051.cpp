#include<bits/stdc++.h>
using namespace std;
long long f[102][102][102],sum; 
int main(){
    int n,m;scanf("%d%d",&n,&m);
    f[0][m][0]=1;    
    for(int i=1;i<=n;i++)
		for(int x=0;x<=m;x++)
			for(int y=0;y<=m;y++)
				if(x+y<=m) 
					f[i][x][y]=(f[i-1][x][y]+f[i-1][x+1][y-1]*(x+1)+f[i-1][x][y+1]*(y+1)+f[i-1][x+2][y-2]*((x+2)*(x+1)/2)+f[i-1][x][y+2]*((y+2)*(y+1)/2)+f[i-1][x+1][y]*(x+1)*y)%9999973;//神秘的状转方程                   
    for(int x=0;x<=m;x++)
		for(int y=0;y<=m-x;y++){sum+=f[n][x][y]%(9999973);sum%=9999973;}
    printf("%lld",sum%9999973);
    return 0;
} 
