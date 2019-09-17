// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
double ans=0;
namespace Mker
{
//  Powered By Kawashiro_Nitori
//  Made In Gensokyo, Nihon
	#define uint unsigned int
	uint sd;int op;
	inline void init() {scanf("%u %d", &sd, &op);}
	inline uint uint_rand()
	{
		sd ^= sd << 13;
		sd ^= sd >> 7;
		sd ^= sd << 11;
		return sd;
	}
	inline double get_n()
	{
		double x = (double) (uint_rand() % 100000) / 100000;
		return x + 4;
	}
	inline double get_k()
	{
		double x = (double) (uint_rand() % 100000) / 100000;
		return (x + 1) * 5;
	}
	inline void read(double &n,double &a, double &b)
	{
		n = get_n(); a = get_k();
		if (op) b = a;
		else b = get_k(); 
	}
}
signed main()
{
    int T;
    scanf("%d",&T);
    double n,a,b;
    Mker::init();
    while(T--)
    {
        Mker::read(n,a,b);
        double powa=pow(n,a-1),powb=pow(n,b-1);
        ans+=(powa*a+powb*b-floor(powa*a+powb*b))/(a*powa+b*powb)-(powa*a+powb*b-ceil(powa*a+powb*b))/(a*powa+b*powb);
    }
    printf("%lf",ans);
    return 0;
}