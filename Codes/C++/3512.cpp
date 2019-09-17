#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=3e6+5;
ll k,n,a[maxn],q_mx[maxn],q_mn[maxn];
ll hmx,hmn,tmx,tmn,len,pre;
int main()
{
    scanf("%lld%lld",&k,&n);
    q_mx[1]=1;
    q_mn[1]=1;
    pre=1;
    len=0;
    hmx=1;
    tmx=1;
    hmn=1;
    tmn=1;
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=2;i<=n;i++)
    {
        while(hmx<=tmx&&a[q_mx[tmx]]<a[i])
            tmx--;
        while(hmn<=tmn&&a[q_mn[tmn]]>a[i])
            tmn--;
        q_mx[++tmx]=i;
        q_mn[++tmn]=i;
        while(a[q_mx[hmx]]-a[q_mn[hmn]]>k)
        {
            if(q_mx[hmx]<q_mn[hmn])
                {
                    pre=q_mx[hmx]+1;
                    hmx++;
                }
            else
            {
                pre=q_mn[hmn]+1;
                hmn++;
            }
        }
        len=max(len,i-pre+1);
    }
    printf("%lld",len);
    return 0;
}