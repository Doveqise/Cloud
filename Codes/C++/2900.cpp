#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int q[maxn];
double f[maxn],k[maxn];
struct Land{
    int w,l;
    bool operator<(const Land &x)const{
        return l>x.l||(l==x.l&&w>x.w);
    }
}a[maxn];
double calc(int i,int j)
{
	return (f[j-1]-f[i-1])/(a[i].l-a[j].l);
}
signed main(){
    int n,h;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    	scanf("%d%d",&a[i].w,&a[i].l);
    sort(a+1,a+n+1);
    for(int i=h=1;i<=n;i++)
        if(a[h].w<a[i].w)a[++h]=a[i];
    n=h;
    for(int i=h=1,t=0;i<=n;i++){
        while(h<t&&k[t-1]>=calc(q[t],i))
			t--;
        k[t]=calc(q[t],i);
		q[++t]=i;
        while(h<t&&k[h]<=a[i].w)
			h++;
        f[i]=(double)a[q[h]].l*a[i].w+f[q[h]-1];
    }
    printf("%.0lf\n",f[n]);
    return 0;
}
