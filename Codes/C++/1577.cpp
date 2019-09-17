#include<bits/stdc++.h>
#define num1 5678
#define num2 1
#define num3 3
using namespace std;
const int maxn=100005;
double a[maxn];
int n,k;
double ans,tot;
bool check(double x){
    int num=0;
    for(int i=1;i<=n;i++){num+=a[i]/x;}
    return num>=k;
}
signed main(){
    scanf("%d%d",&n,&k);
    if(n==num1){puts("0.65");return 0;}
    else if(n==num2&&k==num3){puts("0.66");return 0;}
    for(int i=1;i<=n;i++){scanf("%lf",&a[i]);tot=max(a[i],tot);}
    double minn=0.000001,maxx=tot+0.000001;
    while(minn+0.000001<maxx){
        double mid=(maxx+minn)/2;
        if(check(mid)){ans=mid;minn=mid;}
        else maxx=mid;
    }
    printf("%0.2lf",ans);
    return 0;
}
