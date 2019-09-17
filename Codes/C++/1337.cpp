#include<bits/stdc++.h>
using namespace std;
double xans,yans;
double ans=1e18+7,t;
const double delta=0.998;
struct Node{
    int x,y,weight;
}node[10005];
int n;
double potential_energy(double nowx,double nowy){
    double sum=0;
    for(int i=1;i<=n;i++){
        double delx=nowx-node[i].x;
        double dely=nowy-node[i].y;
        sum+=(sqrt(delx*delx+dely*dely))*node[i].weight;
    }
    return sum;
}
void simulate_anneal(){
    double xx=xans,yy=yans;
    t=2019;
    while(t>1e-14){
        double xtemp=xans+(rand()*2-RAND_MAX)*t;
        double ytemp=yans+(rand()*2-RAND_MAX)*t;
        double new_ans=potential_energy(xtemp,ytemp);
        double DE=new_ans-ans;
        if(DE<0){
            xx=xtemp;
            yy=ytemp;
            xans=xx;
            yans=yy;
            ans=new_ans;
        }
        else if(exp(-DE/t)*RAND_MAX>rand()){xx=xtemp;yy=ytemp;}
        t*=delta;
    }
}
void SA(){for(int i=1;i<=10;i++) simulate_anneal();return;}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d%d",&node[i].x,&node[i].y,&node[i].weight);
    SA();
    printf("%.3lf %.3lf",xans,yans);
    return 0;
}
