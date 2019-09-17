namespace read
{
    #define LL long long
    #define ULL unsigned long long
    inline char get()
    {
     static char buf[100000],*p1=buf,*p2=buf;
     return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
    }
    inline int Iread()
    {
        char ch;
        int flag=1,res=0;
        ch=get();
        for(;!isdigit(ch);ch=get())
            if(ch=='-')flag=-1;
        for(;isdigit(ch);ch=get())
            res=res*10+(ch-'0');
        return flag*res; 
    }
    inline LL Lread()
    {
        char ch;
        LL flag=1,res=0;
        ch=get();
        for(;!isdigit(ch);ch=get())
            if(ch=='-')flag=-1;
        for(;isdigit(ch);ch=get())
            res=res*10+(ch-'0');
        return flag*res; 
    }
    inline double Fread()
    {
        double r;
        double x=0,t=0;int s=0,f=1;char c=get();
        for(;!isdigit(c);c=get()) 
          {
          if (c=='-') f=-1;
          if (c=='.') goto readt;
          }
        for (;isdigit(c)&&c!='.';c=get()) x=x*10+c-'0';
        readt:for (;c=='.';c=get()); 
        for (;isdigit(c);c=get()) t=t*10+c-'0',++s;
        r=(x+t/pow(10,s))*f;
        return r;
    }
    inline void Sread1(char s[])
    {
        char ch;
        for(register int i=0;;i++)
        {
            ch=get();
            if(ch=='\n')break;
            s[i]=ch;
        }
    }
    inline void Sread2(char s[])
    {
        char ch;
        for(register int i=0;;i++)
        {
            ch=get();
            if(ch==' ')break;
            s[i]=ch;
        }
    }
    inline int Iout(int x)
    {
        if(x<0)
        {
            putchar('-');x=-x;
        }
        if(x>9)Iout(x/10);
        putchar(x%10+'0');
    }
    inline LL Lout(LL x)
    {
        if(x<0)
        {
            putchar('-');x=-x;
        }
        if(x>9)Iout(x/10);
        putchar(x%10+'0');
    }
    inline void Sout(char s[])
    {
        for(register int i=0;i<strlen(s);i++)
            putchar(s[i]);
    }
    inline void Fout(double x,int k)
    {
        static ULL n=pow(10,k);
        if (x==0) 
          {
          putchar('0'),putchar('.');
          for (int i=1;i<=k;++i) putchar('0');
          return;
          }
        if (x<0) putchar('-'),x=-x;
        LL y=(LL)(x*n)%n;x=(LL)x;
        Lout(x),putchar('.');
        int bit[100],p=0,i;
        for (;p<k;y/=10) bit[++p]=y%10;
        for (i=p;i>0;i--) putchar(bit[i]+48);
    }
}
using namespace read;
/*int main()
{
    int a;
    long long b;
    char c[100];
    double d;
    a=Iread();Iout(a);putchar('\n');//整形读入输出 
    b=Lread();Lout(b);putchar('\n');//长整型读入输出 
    Sread1(c);Sout(c);putchar('\n');//字符串读入输出，遇到\n停止 
    Sread2(c);Sout(c);putchar('\n');//同上，遇到' '停止 *
    d=Fread();Fout(d,18);putchar('\n');//浮点型输入输出，保留最多18位小数 
    return 0;
}*/
