#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
using namespace std;
int n,m,sum;
int a[30];
int x[10];
double ans=123456789,ave;
void calc(){
    memset(x,0,sizeof(x));
    for(int i=1;i<=n;i++) {
        int p=1;
        for(int j=1;j<=m;j++) if(x[j]<x[p]) p=j;
        x[p]+=a[i];
    }
    double now=0;
    for(int i=1;i<=m;i++) now+=sqr(x[i]-ave);
    now/=(double)m;
    if(now<ans)ans=now;
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
    ave=(double)sum/m;
    for(int i=1;i<=4567;i++) {
        random_shuffle(a+1,a+n+1);
        calc();
    }
    printf("%.2f\n",sqrt(ans));
    return 0;
}
