#include<bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int a[maxn];
int main()
{
	int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
    	scanf("%d",&a[i]);
    }
    sort(a+1,a+m+1);
	int l=1,r=n,ans=0;
    for(int i=m;i>0;i--)
    {
        ans+=(r-l)*a[i];
        r--;l++;
        if(l>=r) break;
    }
    printf("%d\n",ans);
    return 0;
}