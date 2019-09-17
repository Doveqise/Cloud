#include<bits/stdc++.h> 
#define CHECK(a) (!(1&(a)))
#define CLEAN2(a) while(CHECK(a))a=a>>=1
#define BIGERA if(a<b)(t=a,a=b,b=t)
using namespace std;
long long n,m,a[1000000];
int gcd(int a,int b){
 int c_2=0,t;
 while((CHECK(a))&&(CHECK(b))){
 a=a>>=1;b=b>>=1;c_2++;
 }
 CLEAN2(a);
 CLEAN2(b);
 BIGERA;
 while(a=((a-b)>>1)){
 CLEAN2(a);
 BIGERA;
 }
 return b<<c_2;
}
int main()
{
    cin>>n>>m;
    long long int p=gcd(n,m);
    a[1]=1;
    a[2]=1;
    for(int i=3;i<=p;i++)a[i]=(a[i-1]+a[i-2])%100000000;
    cout<<a[p]<<endl;
    return 0;
}
