#include<cstdio>
#include<algorithm>
using namespace std;
struct seat{
    int a,b;
}k[1005],l[1005];
bool cmp1(seat x,seat y){
    return x.a>y.a;
}
bool cmp2(seat x,seat y){
    return x.b<y.b;
}
int d,n,m,p,q,x1,x2,y1,y2;
signed main(){
    scanf("%d%d%d%d%d",&m,&n,&p,&q,&d);
    for(int i=1;i<=d;i++){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(x1-x2){
			k[min(x1,x2)].b=min(x1,x2);
            k[min(x1,x2)].a++;
        }
        else{
            l[min(y1,y2)].b=min(y1,y2);
            l[min(y1,y2)].a++;  
        }
    }
    sort(l+1,l+n+1,cmp1);
    sort(k+1,k+m+1,cmp1);
    sort(l+1,l+q+1,cmp2);
    sort(k+1,k+p+1,cmp2);
    for(int i=1;i<=p;i++) printf("%d ",k[i].b);
    puts("");
    for(int i=1;i<=q;i++) printf("%d ",l[i].b);
    return 0;
}
