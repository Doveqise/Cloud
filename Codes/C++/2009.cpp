#include<bits/stdc++.h>
using namespace std;

int n,k;
int be,end;
int f[505][505];

int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

void in()
{
    memset(f,0x3f,sizeof(f));
    int x;
    n=read();k=read();
    for(int i=1;i<=n;++i)
    {
        x=read();
        if(i<n)
        {
            f[i][i+1]=x;
            f[i+1][i]=x;
        }
        if(i==n)
        {
            f[i][1]=x;
            f[1][i]=x;
        }
    }

    char a,b;
    int c,d,e;
    for(int i=1;i<=k;++i)
    {
        scanf("%c %c",&a,&b);
        e=read();
        c=a-'A'+1;
        d=b-'A'+1;
        if(f[c][d]!=4806756)
        {
            if(e>f[c][d])
            {
                f[c][d]=e;
                f[d][c]=e;
            }
        }
        else
        {
            f[c][d]=e;
            f[d][c]=e;
        }
    }
}

void floyd()
{
    for(int k=1;k<=n;++k)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(f[i][j]>f[i][k]+f[k][j])
                f[i][j]=f[i][k]+f[k][j];
            }
        }
    }
}

void work()
{
    char u,v;
    scanf("%c %c",&u,&v);
    floyd();
    printf("%d",f[u-'A'+1][v-'A'+1]);
}

int main()
{
    in();
    work();
    return 0;
}