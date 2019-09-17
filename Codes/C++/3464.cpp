#include<bits/stdc++.h>
#define inf 0x7f7f7f7f
using namespace std;
const int mod=1e9;
const int N=1e4;
const int jinzhi=4;
const int weishu=1e4;
char s[N+10];
struct Dp{
    int x,y;
    Dp(){}
    Dp(int _x,int _y){x=_x,y=_y;}
}f[N+10],g[N+10];
Dp min(const Dp &a,const Dp &b){return a.x<b.x?a:b;}
Dp operator +(const Dp &a,int b){return Dp(a.x+b,a.y);}
Dp operator +(const Dp &a,const Dp &b){return a.x==b.x?Dp(a.x,(a.y+b.y)%mod):min(a,b);}
int T[N+10];

struct Bnum{
    int v[N+10],len;
    Bnum(){len=1,memset(v,0,sizeof(v));}
    void in(){
        scanf("%s",s);
        int t=strlen(s),tim=1;
        len=(t-1)/jinzhi+1;
        for (int i=0,j=t-1;i<j;i++,j--) swap(s[i],s[j]);
        for (int i=0;i<t;i++){
            v[i/jinzhi]+=(s[i]-'0')*tim,tim*=10;
            if (tim==weishu)  tim=1;
        }
    }
    void write(){
        printf("%d",v[len-1]);
        for (int i=len-2;~i;i--)    printf("%0*d",jinzhi,v[i]);
        putchar('\n');
    }
}A,Zero;
int operator %(Bnum x,int y){
    for (int i=x.len;i;i--) x.v[i-1]+=x.v[i]%y*weishu;
    return x.v[0]%y;
}
Bnum operator /(Bnum &x,int y){
    for (int i=x.len;~i;i--)    x.v[i-1]+=x.v[i]%y*weishu,x.v[i]/=y;
    while (!x.v[x.len]&&x.len)  x.len--;
    x.len++;
    return x;
}
bool operator ==(const Bnum &x,const Bnum &y){
    if (x.len!=y.len)   return 0;
    for (int i=0;i<=x.len;i++)  if (x.v[i]!=y.v[i]) return 0;
    return 1;
}
bool operator !=(const Bnum &x,const Bnum &y){return !(x==y);}

inline int in(){
    int x=0,f=1;char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar())  if (ch=='-')    f=-1;
    for (;ch>='0'&&ch<='9';ch=getchar())    x=(x<<1)+(x<<3)+ch-'0';
    return x*f;
}
inline void out(int x){
    if (x>=10)     out(x/10);
    putchar(x%10+'0');
}

int main(){
    int tot=1;
    A.in();
    while (A!=Zero) T[tot++]=A%4,A=A/4;
    f[0]=Dp(0,1),g[0]=Dp(inf,0);
    for (int i=1;i<=tot;i++){
        f[i]=(f[i-1]+T[i])+(g[i-1]+(T[i]+1));
        g[i]=(f[i-1]+(4-T[i]))+(g[i-1]+(3-T[i]));
    }
    printf("%d\n",f[tot].y);
    return 0;
}