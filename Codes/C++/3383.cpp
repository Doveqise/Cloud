#include<bits/stdc++.h>
const long long MAXN=6893911;
long long p[MAXN],cnt;
bool mark[MAXN];
int pi[MAXN];
long long L,R;
void Int()
{	scanf("%lld%lld",&L,&R);
    long long i,j;
    for (i=2;i<MAXN;i++)
    {	if (!mark[i]) p[cnt++]=i;
        pi[i]=pi[i-1]+!mark[i];
        for (j=0;p[j]*i<MAXN&&j<cnt;j++)
        {	mark[p[j]*i]=true;
            if (i%p[j]==0)
                break;
        }
    }
}
int f(long long n,int m)
{	if (n==0)return 0;
    if (m==0)return n-n/2;
    return f(n,m-1)-f(n/p[m],m-1);
}
int Pi(long long N);
int p2(long long n, int m)
{	int p22=0;
    for (int i=m+1;(long long)p[i]*p[i]<=n;i++)
        p22+=Pi(n/p[i])-Pi(p[i])+1;
    return p22;
}
int p3(long long n, int m)
{	int p33=0;
    for (int i=m+1;(long long)p[i]*p[i]*p[i]<=n;i++)
        p33+=p2(n/p[i],i-1);
    return p33;
}
int Pi(long long N)
{	if (N<MAXN)return pi[N];
    int limit=f(N,0.25)+1;
    int i;
    for (i=0;p[i]<=limit;i++);
        int Pii=i+f(N,i-1)-1-p2(N,i-1)-p3(N,i-1);
    return Pii;
}
int main()
{	Int();
    printf("%d",Pi(R)-Pi(L-1));
}
