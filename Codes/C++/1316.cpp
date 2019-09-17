#include<bits/stdc++.h>
using namespace std;
int n,c,a[100010],l=1,r,mid;
bool judge(int x){
    int tot=1,num=1;
    for(int i=2;i<=n;i++) if(a[i]-a[num]>=x){tot++;num=i;}
    return tot<c?0:1;
}
int main()
{
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    r=a[n]-a[1];
    while(l<=r){
        mid=(l+r)>>1;
        if(judge(mid))l=mid+1;
        else r=mid-1;
	}
    cout<<l-1;
    return 0;
}
