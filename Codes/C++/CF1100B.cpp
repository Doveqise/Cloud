#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int num[maxn],cnt=0;
signed main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i=1,t;i<=n;i++)
    {
        scanf("%d",&t);
        if(!num[t])
            num[t]++,cnt++;
        else
            num[t]++;
        if(cnt==m) 
        {
            for(int j=1;j<=m;j++)
                num[j]--;
            printf("1"),cnt=0;
            for(int j=1;j<=m;j++)
                if(num[j])
                    cnt++;
        }
        else
            printf("0");
    }
    return 0;
}