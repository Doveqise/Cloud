#include<bits/stdc++.h>
using namespace std;
int a[35];
int T,n,ans;

int Calculate() 
{
    int x=0,y=0;
    for(int i=1;i<=n;i++)
        if(i<=(n+1)/2)x+=a[i];
        else y+=a[i];
    return abs(x-y);
}

void simulate_anneal()
{
    double T=81;
    while(T>1e-9)
    {
        int x = rand()%((n+1)/2)+1,y=rand()%((n+1)/2)+((n+1)/2);
        if(x<=0||x>n||y<=0||y>n) continue;
        swap(a[x],a[y]);
        int newans = Calculate();
        int delta=ans-newans;
        if(delta>0) ans=newans;
        else if(exp((double)((double)delta/T))*RAND_MAX<=rand())swap(a[x], a[y]);
        T*=0.999;
    }
}

int main()
{
    scanf("%d",&T);
    srand((unsigned)time(NULL));
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        ans=1e9;
        for (int i=1;i<=17;i++) simulate_anneal();
        printf("%d",ans);
    }
    return 0;
}
