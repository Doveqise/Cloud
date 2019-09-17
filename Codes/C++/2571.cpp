#include<bits/stdc++.h>
using namespace std;
double ax,bx,ay,by,cx,cy,dx,dy,p,q,r,ans=1234567890;
const double delta=0.997;
double dis(double x1,double y1,double x2,double y2){return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));}
double rd(double x1,double y1,double x2,double y2){return dis(ax,ay,x1,y1)/p+dis(x1,y1,x2,y2)/r+dis(x2,y2,dx,dy)/q;}
double rng(){return 2*rand()-RAND_MAX;}
void SA(){
    double lab=0.5,lcd=0.5,temp=2000;
    while(temp>1e-7){
        double ab=lab+rng()*0.00003*temp,cd=lcd+rng()*0.00003*temp;
        ab=min(ab,1.0),ab=max(ab,0.0),cd=min(cd,1.0),cd=max(cd,0.0);
        double x1=ax+(bx-ax)*ab, y1=ay+(by-ay)*ab,x2=cx+(dx-cx)*cd,y2=cy+(dy-cy)*cd,as=rd(x1,y1,x2,y2);
        if(as<ans)ans=as,lab=ab,lcd=cd;temp*=delta;
    }
}
int main(){
    srand(1);
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy,&p,&q,&r);
    SA();
    printf("%0.2lf",ans);
    return 0;
}
