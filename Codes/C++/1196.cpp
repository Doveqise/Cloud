#include<bits/stdc++.h>
using namespace std;
const int maxn=3e4+5;
int fa[maxn],fr[maxn],num[maxn];
void init()
{
    for(int i=1;i<=30000;i++)
    {                             
        fa[i]=i;
        fr[i]=0;
        num[i]=1;
    }   
    return;
}
int findfa(int n)
{                      
    if(fa[n]==n)
        return fa[n];
    int fn=findfa(fa[n]);               
    fr[n]+=fr[fa[n]];    
    return fa[n]=fn;
}
signed main()
{
    init();
    int T;
    scanf("%d\n",&T);
    while(T--)
    {
        char op;
        int x,y;
        //scanf("%c %d %d \n",&op,&x,&y);
        cin>>op>>x>>y;
        int fx=findfa(x);                                
        int fy=findfa(y);                                
        if(op=='M')
        {
            fr[fx]+=num[fy];
            fa[fx]=fy;                                    
            num[fy]+=num[fx];                          
            num[fx]=0;                       
        }
        if(op=='C')
        {
            if(fx!=fy)
                puts("-1");       
            else
                printf("%d\n",abs(fr[x]-fr[y])-1);
        }
    }
    return 0;
}