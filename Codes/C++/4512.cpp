#include<bits/stdc++.h>
#define For(i,a,b) for(i=(a);i<=(b);++i)
#define Forward(i,a,b) for(i=(a);i>=(b);--i)
#define Rep(i,a,b) for(register int i=(a),i##end=(b);i<=i##end;++i)
#define Repe(i,a,b) for(register int i=(a),i##end=(b);i>=i##end;--i)
using namespace std;
template<typename T>inline void read(T &x){
    T s=0,f=1;char k=getchar();
    while(!isdigit(k)&&k^'-')k=getchar();
    if(!isdigit(k)){f=-1;k=getchar();}
    while(isdigit(k)){s=s*10+(k^48);k=getchar();}
    x=s*f;
}
const int MAXN=1<<20;
namespace polynomial
{
    static int mod=998244353,gen=3,g[21],rev[MAXN],Len;

    inline int ad(int a,int b){return (a+=b)>=mod?a-mod:a;}

    inline int power(int a,int b)
    {
        static int sum;
        for(sum=1;b;b>>=1,a=(long long)a*a%mod)if(b&1)
            sum=(long long)sum*a%mod;
        return sum;
    }

    inline void predone()
    {
        static int i,j;
        for(i=1,j=2;i<=19;++i,j<<=1)g[i]=power(gen,(mod-1)/j);
    }

    inline void calrev(int Len)
    {
        static int Logl;Logl=(int)floor(log(Len)/log(2)+0.3)-1;
        Rep(i,1,Len-1)rev[i]=(rev[i>>1]>>1)|((i&1)<<Logl);
    }

    inline void NTT(int X[],int typ)
    {
        Rep(i,1,Len-1)if(i<rev[i])swap(X[i],X[rev[i]]);
        static int i,j,k,kk,w,t,wn,r;
        for(k=2,kk=1,r=1;k<=Len;k<<=1,kk<<=1,++r)
        {
            wn=g[r];
            for(i=0;i<Len;i+=k)for(j=0,w=1;j<kk;++j,w=(long long)w*wn%mod)
            {
                t=(long long)w*X[i+j+kk]%mod;
                X[i+j+kk]=ad(X[i+j],mod-t);
                X[i+j]=ad(X[i+j],t);
            }
        }
        if(typ==-1)
        {
            reverse(X+1,X+Len);
            static int invn;invn=power(Len,mod-2);
            Rep(i,0,Len-1)X[i]=(long long)X[i]*invn%mod;
        }
    }

    static int x[MAXN],y[MAXN];
    inline void mul(int a[],int b[])
    {
        memset(x,0,sizeof x);memset(y,0,sizeof y);
        Rep(i,0,(Len>>1)-1)x[i]=a[i],y[i]=b[i];
        NTT(x,1);NTT(y,1);
        Rep(i,0,Len-1)x[i]=(long long)x[i]*y[i]%mod;
        NTT(x,-1);
        Rep(i,0,Len-1)a[i]=x[i];
    }

    static int c[2][MAXN];

    inline void Inv(int a[],int n)
    {
        static int t;t=0;
        memset(c,0,sizeof c);
        c[0][0]=power(a[0],mod-2);
        Len=2;
        while(Len<=(n<<1))
        {
            Len<<=1;
            calrev(Len);t^=1;
            memset(c[t],0,sizeof c[t]);
            Rep(i,0,Len)c[t][i]=ad(c[t^1][i],c[t^1][i]);
            mul(c[t^1],c[t^1]);mul(c[t^1],a);
            Rep(i,0,Len)c[t][i]=ad(c[t][i],mod-c[t^1][i]);
        }
        Rep(i,0,Len-1)a[i]=c[t][i];
    }
}
using namespace polynomial;

int n,m,F[MAXN],G[MAXN],Q[MAXN],R[MAXN],Gr[MAXN];

int main(){
    read(n);read(m);
    Rep(i,0,n)read(F[i]),Q[n-i]=F[i];
    Rep(i,0,m)read(G[i]),Gr[m-i]=G[i];
    Rep(i,n-m+2,m)Gr[i]=0;
    predone();
    Inv(Gr,n-m+1);
    mul(Q,Gr);
    reverse(Q,Q+n-m+1);
    Rep(i,n-m+1,n)Q[i]=0;
    Rep(i,0,n-m)printf("%d ",Q[i]);
    puts("");
    while(Len<=(n<<2))Len<<=1;
    calrev(Len);
    mul(Q,G);
    Rep(i,0,m-1)printf("%d ",ad(F[i],mod-Q[i]));
    puts("");
    return 0;
}
