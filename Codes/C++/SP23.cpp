#include<bits/stdc++.h>
using namespace std;
signed main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        double l,n,a,m,b,c;
        scanf("%lf%lf%lf%lf%lf%lf",&l,&n,&a,&m,&b,&c);
        double v=sqrt((4*a*a*b*b*c*c-a*a*(b*b+c*c-m*m)*(b*b+c*c-m*m)-b*b*(c*c+a*a-n*n)*(c*c+a*a-n*n)-c*c*(a*a+b*b-l*l)*(a*a+b*b-l*l)+(a*a+b*b-l*l)*(b*b+c*c-m*m)*(c*c+a*a-n*n)))/12;
        printf("%.4lf\n",v);
    }
    return 0;
}
