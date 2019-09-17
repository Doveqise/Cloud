#include <cstdio>
    #include<cstring>
    #include <string>
    #include <iostream>
    #include <algorithm>
    #include <cmath>
    using namespace std;
    long long int a[30],b[30],n,m,we=0,v=0,g[30],w7,g1=1;
    bool sushu(int x)
    {
        int i,t=1;
        if(x==1){return false;}
        else if(x==2||x==3){return true;}
        for(i=2;i*i<=x;i++)
        {
            if(x%i==0)
            {t=0;
            break;
            }
        }
        if(t){return true;}
        else{return false;}
    }
    void dfs(int x,int y)
    {if(y==0)
    {
        if(sushu(v))
        {we++;}
        return ;
    }
    else
    {
        for(int w1=0;w1<x;w1++)
        {
            if(b[w1]==0)
            {
                b[w1]=1;
                v+=a[w1];
                dfs(x,y-1);
                b[w1]=0;
                v-=a[w1];
            }
        }
    }    
    }
    int main()
    {    
        for(w7=1;w7<21;w7++)
        {g1*=w7;
        g[w7]=g1;
        }
        scanf("%lld %lld",&n,&m);
        for(int w0=0;w0<n;w0++){scanf("%d",&a[w0]);}
        dfs(n,m);
        printf("%lld",we/g[m]);
        return 0;
    } 
