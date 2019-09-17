#include<bits/stdc++.h>
using namespace std;
struct ball{int x,y;}a[100001],f[1000001];
bool cmp(ball a,ball b){return a.x<b.x;}
int main(){
    int n,d;scanf("%d %d",&n,&d);
    for(int i=1;i<=n;i++) scanf("%d %d",&a[i].x,&a[i].y);
    sort(a+1,a+1+n,cmp);
    int head=1,tail=1,ti=2,minn=123456789;
    f[1]=a[1];
    while(ti<=n){
        while((f[tail].y>a[ti].y)&&(tail>=head)) tail--;
        tail++;f[tail]=a[ti];
        while((tail>=head)&&(f[tail].y-f[head].y>=d)){head++;minn=min(minn,f[tail].x-f[head-1].x);}
        ti++;
    }
    if(minn==123456789) printf("-1");
    else printf("%d\n",minn);
    return 0;
}
