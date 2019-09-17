#include <bits/stdc++.h>
using namespace std;
int gcd(int m,int n){int r=m%n;while(r){m=n;n=r;r=m%n;}return n;}
int main(){
    int n;scanf("%d",&n);
    while(n--){
        int a0,a1,b0,b1,i;scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
        if(b1%a1){puts("0");continue;}
        int s=b1/a1,c=a0/a1,d=b1/b0,ans=0;
        for(i=1;i*i<s;i++){
            if(s%i)continue;int j=s/i;
            if(gcd(c,i)==1&&gcd(d,j)==1)ans++;
            if(gcd(c,j)==1&&gcd(d,i)==1)ans++;}
        if(i*i==s&&gcd(c,i)==1&&gcd(d,i)==1) ans++;
        printf("%d\n",ans);
    }
    return 0;
}
