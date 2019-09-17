#include<bits/stdc++.h>
using namespace std;
int f[50][50]={1};
int main(){
	int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) if(f[i][j]){
    	f[i+1][(j-1+n)%n]+=f[i][j];
    	f[i+1][(j+1)%n]+=f[i][j];
    }
    printf("%d",f[m][0]);return 0;
}