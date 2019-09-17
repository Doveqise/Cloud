#include<bits/stdc++.h>
using namespace std;
const int Maxn = 1e5 + 7;
int n,cnt;
int a[Maxn];
bool del[Maxn];
int main()
{
    int t,mid;
    while(scanf("%d",&t)&&t)
    {
        a[1]=t;n=cnt=mid=1;
        memset(del,0,sizeof del);
        while(scanf("%d",&t))
        {
            if(!t) break;
            if(t == -1)
            {
                printf("%d\n",a[mid]);
                del[mid]=1;
                if(--cnt&1)
                	while(del[++mid]);
                else
                	while(del[--mid]);
            }
            else
            {
                a[++n]=t;
                ++cnt;
                if(cnt&1)
                	while(del[++mid]);
            }
        }
        puts("");
    }
    return 0;
}
