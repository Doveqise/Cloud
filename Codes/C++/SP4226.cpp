#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int l,n,m,k,c[1005],a[1005];
long long ans=0;
struct node
{
    int x,y;
}Node[N*N];
int lowbit(int x)
{
    return x&-x;
}
void add(int pos,int x)
{
    for(int i=pos;i<=n;i+=lowbit(i))
    {
        c[i]+=x;
    }
}
int query(int pos)
{
    long long sum=0;
    for(int i=pos;i>=1;i-=lowbit(i))
    {
        sum+=c[i];
    }
    return sum;
}
bool cmp(node a,node b)
{
    return (a.x<b.x)||((a.x==b.x)&&(a.y<b.y));
}
int main()
{
    scanf("%d",&l);
    for(int i=1;i<=l;i++)
    {
        memset(c,0,sizeof(c));
        memset(a,0,sizeof(a));
        scanf("%d%d%d",&n,&m,&k);
        for(int j=1;j<=k;j++)
        {
            scanf("%d%d",&Node[j].x,&Node[j].y);
        }
        sort(Node+1,Node+1+k,cmp);    
        ans=0;                                                                                                    
        for(int j=k;j>=1;j--)
        {
            add(Node[j].y,1);
            ans+=query(Node[j].y-1);
        }
    printf("Test case %d: %lld\n",i,ans);
    }
    return 0;
}