#include<bits/stdc++.h>
#define ll long long
#define reg register 
#define il inline
#define put putchar('\n')
using namespace std;
il int read(){
	char c=getchar();
	int tot=1;while((c<'0'||c>'9')&&c!='-')c=getchar();
	if (c=='-'){tot=-1;c=getchar();}
	int sum=0;
	while(c>='0'&&c<='9'){sum=sum*10+c-'0';c=getchar();}
	return sum*tot;
}
il void wr(int x){
	if(x<0){putchar('-');wr(-x);return;}
	if(x>=10)wr(x/10);
	putchar(x%10+'0');
}
il void wrt(int x){wr(x);put;}
il void wri(int x){wr(x);putchar(' ');}
int c[50005],tong[100005],n,m,s,l,r,t,num;
struct xl{int l1,l,r,i,ans1;}z[500005];
bool cmp(xl a,xl b){return a.l1==b.l1?(a.l1&1)?a.r<b.r:a.r>b.r:a.l1<b.l1;}
bool cmp2(xl a,xl b){return a.i<b.i;}
il void add(int x){num+=(++tong[c[x]]==1);}
il void del(int x){num-=(--tong[c[x]]==0);}
int main(){
    n=read();
    for(int i=1;i<=n;i++)c[i]=read();
    m=read();s=sqrt(n);
    for(int i=1;i<=m;i++){z[i].l=read();z[i].r=read();z[i].l1=z[i].l/s;z[i].i=i;}
    sort(z+1,z+m+1,cmp);
    reg int l=0,r=0;
    for(int i=1;i<=m;i++){
        while(r<z[i].r)add(++r);
        while(r>z[i].r)del(r--);
        while(l>z[i].l)add(--l);
        while(l<z[i].l)del(l++);
        z[i].ans1=num;}
    sort(z+1,z+m+1,cmp2);
    for(int i=1;i<=m;i++)wrt(z[i].ans1);
    return 0;
}
