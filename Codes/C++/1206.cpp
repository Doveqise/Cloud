#include<bits/stdc++.h>
using namespace std;
int B;
struct node
{
    int a[105],len;
    void mk(int x)
    {
        while(x)
        {
            a[++len]=x%B;
            x/=B;
        }
        return;
    }
    bool judge()
    {
        int l=1,r=len;
        while(l<=r)
        {
            if(a[l]!=a[r])
                break;
            l++,r--;
        }
        if(l>=r)
            return 1;
        return 0;
    }
}
num[305];
signed main()
{
    scanf("%d",&B);
    int ans=0;
    for(int i=1;i<=300;i++)
    {
        num[i].mk(i * i);
        if(num[i].judge())
        {
            for(int j=num[301].len;j>=1;j--)
                num[301].a[j] = 0;
            num[301].len = 0;
            num[301].mk(i);
            for(int j=num[301].len;j>=1;j--)
            {
                if(num[301].a[j]>=10)
                    printf("%c", num[301].a[j] - 10 + 'A');
                else printf("%d",num[301].a[j]);
            }
            printf(" ");
            for(int j=1;j<=num[i].len;j++)
            {
                if(num[i].a[j]>=10)
                    printf("%c", num[i].a[j] - 10 + 'A');
                else printf("%d",num[i].a[j]);
            }
            puts("");
        }
    }
    return 0;
}