#include<bits/stdc++.h>
using namespace std;
int n,rxa,rxc,rya,ryc,rza,rzc,rp=2333333,i,j,k,l,f[45][45];
long long x,y,z,arr;
double xxx,yyy,a[45][45],b[45][45],ans;
int main(){
	scanf("%d%d%d%d%d%d%d",&n,&rxa,&rxc,&rya,&ryc,&rza,&rzc);
    for(i=1;i<=2*n;i++){
        x=(y*rxa+rxc)%rp;y=(z*rya+ryc)%rp;z=(x*rza+rzc)%rp;
        if(i%2==1){xxx=(double)(x%20)+(double)((double)(y%10)/10.0)+(double)((double)(z%10)/100.0);}
        else{yyy=(double)(x%20)+(double)((double)(y%10)/10.0)+(double)((double)(z%10)/100.0);a[(int)xxx][(int)yyy]+=xxx;b[(int)xxx][(int)yyy]+=yyy;f[(int)xxx][(int)yyy]++;}}
    for(i=0;i<=20;i++) for(j=0;j<=20;j++) for(k=i+1;k<=20;k++) for(l=j+1;l<=20;l++){ans+=(a[k][l]+b[k][l])*(double)f[i][j]-(a[i][j]+b[i][j])*(double)f[k][l];arr+=f[i][j]*f[k][l];}
    printf("%.5f",ans/arr);
    return 0;
}
