#include<bits/stdc++.h>
#define maxn 10050
using namespace std;
struct Point{double x,y;};
Point p[maxn],ch[maxn];
bool cmp(Point x,Point y){return x.x<y.x||(x.x==y.x&&x.y<y.y);}
int Cross(Point x,Point y,Point z){
    double x1=x.x-y.x,y1=x.y-y.y,x2=z.x-y.x,y2=z.y-y.y;
    if((x1*y2-x2*y1)<=0)return 0;
    return 1;}
int andrew(int n){
    sort(p,p+n,cmp);
    int m=0;int i;for(i=0;i<n;i++){while( m>1 && !Cross(ch[m-1],ch[m-2],p[i])) m--;ch[m++]=p[i];}
    int k=m;for(i=n-2;i>=0;i--){while( m>k && !Cross(ch[m-1],ch[m-2],p[i])) m--;ch[m++]=p[i];}
    if(n>1)m--;return m;}
signed main(){
   int n;scanf("%d",&n);
   for(int i=0;i<n;i++)scanf("%lf %lf",&p[i].x,&p[i].y);
   int ans=andrew(n);double sum=0;
   for(int i=0;i<ans-1;i++){sum+=sqrt((ch[i+1].x-ch[i].x)*(ch[i+1].x-ch[i].x)+(ch[i+1].y-ch[i].y)*(ch[i+1].y-ch[i].y));}
   sum+=sqrt((ch[ans-1].x-ch[0].x)*(ch[ans-1].x-ch[0].x)+(ch[ans-1].y-ch[0].y)*(ch[ans-1].y-ch[0].y));
   printf("%.2lf",sum);
   return 0;
}
