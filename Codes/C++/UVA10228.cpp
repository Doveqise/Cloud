/*#include<bits/stdc++.h>
using namespace std;
int t,n,px[105],py[105];
double ansx,ansy,ansdis;
double get(double x,double y,double xx,double yy){return sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));}
double add(double x,double y){double sum=0;for (int i=1;i<=n;++i) sum+=get(x,y,(double)px[i],(double)py[i]);return sum;}
void SA(){
    double x=ansx,y=ansy,T=2000,delta=0.999;
    while (T>=1e-10){
        double xx=ansx+(rand()*2-RAND_MAX)*T,yy=ansy+(rand()*2-RAND_MAX)*T,nowans=query(xx,yy),DE=nowans-ansdis;
        if (DE<0) ansdis=nowans,x=ansx=xx,y=ansy=yy;
        else if (exp(-DE/T)*RAND_MAX>rand())x=xx,y=yy;
        T*=delta;return;}}
void solve(){
    ansx=0;ansy=0;scanf("%d",&n);
    for(int i=1;i<=n;i++){scanf("%d%d",&px[i],&py[i]);ansx+=px[i];ansy+=py[i];}
    ansx/=(double)n;ansy/=(double)n;
    ansdis=add(ansx,ansy);SA();
    printf("%.0lf\n",ansdis);return;}
signed main(){scanf("%d",&t);for(int i=1;i<=t;++i){solve();if(i!=t)printf("\n");}return 0;}
*/
#include <bits/stdc++.h>
const int MaxN=200;
const double delta=0.998;
int n;
int x[MaxN], y[MaxN];
double ansx, ansy;
double calc(double nx, double ny){
    double tmp=0;
    for(int i=1;i<=n;i++)tmp+=sqrt((nx-x[i])*(nx-x[i])+(ny-y[i])*(ny-y[i]));
    return tmp;
}
inline int read()
{
    int x = 0;
    char ch = getchar();
    while (ch>'9'||ch<'0')ch = getchar();
    while (ch<='9'&&ch>='0')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return x;
}
inline void SA(){
    double t = 10000000;
    while (t > 1e-14){
        double nowx=ansx+(rand()*2-RAND_MAX)*t;
        double nowy=ansy+(rand()*2-RAND_MAX)*t;
        double tmp=calc(nowx,nowy)- calc(ansx,ansy);
        if (tmp<0)ansx=nowx,ansy=nowy;
        else if(exp(-tmp/t)*RAND_MAX>rand())ansx=nowx,ansy=nowy;
        t*=delta;
    }
}
int main(){
    srand(time(NULL));
    int T=read();
    while(T--){
        ansx=ansy=0;
        n=read();
        for(int i=1;i<=n;i++)x[i]=read(),y[i]=read();
        for (int i=1;i<=100;i++)SA();
        printf("%.0lf\n",calc(ansx, ansy));
        if(T)printf("\n");
    }
    return 0;
}
