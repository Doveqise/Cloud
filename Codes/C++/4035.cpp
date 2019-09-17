#include<bits/stdc++.h>
using namespace std;
struct point{
    double num[15];
}p[15],ans,det;
double dist(point a,point b,int n){
    double ret=0;
    for(int i=1;i<=n;i++) ret+=(a.num[i]-b.num[i])*(a.num[i]-b.num[i]);
    return sqrt(ret);
}
double dis[15];
int main(){
	int n;scanf("%d",&n);
    for(int i=1;i<=n+1;i++)for(int j=1;j<=n;j++){
		scanf("%lf",&p[i].num[j]);
		ans.num[j]+=p[i].num[j]/(n+1);
	}
	double T=100000;
	while(T>=0.00001){
        double ave=0;
        for(int i=1;i<=n+1;i++) dis[i]=dist(ans,p[i],n),ave+=dis[i];
        ave/=n+1;
        for(int i=1;i<=n;i++) det.num[i]=0;
        for(int i=1;i<=n+1;i++)for(int j=1;j<=n;j++) det.num[j]+=(dis[i]-ave)*(p[i].num[j]-ans.num[j])/ave;
        for(int i=1;i<=n;i++) ans.num[i]+=det.num[i]*T;
        T*=0.99999;
    }
    for(int i=1;i<=n;i++) printf("%.3f ",ans.num[i]);
    return 0;
}
