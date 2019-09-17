#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
typedef long long ll;
struct node 
{
    int id,val;
    bool operator < (const node b) const
    {
        return val>b.val;
    }
}
D1[maxn],D2[maxn],*t;
int hd1,hd2;
signed main() 
{
    int n,v,num1=0,num2=0;   
    ll ans=0,tmp;       
    scanf("%d%d",&n,&v);
    for(int i=1,j;i<=n;i++) {
        scanf("%d",&j);
        if(j==1)
            t=&D1[hd1++];     
        else
            t=&D2[hd2++];
        t.id=i;               
        scanf("%d",&t.val);
    }
    sort(D2,D2+hd2);
    for(;v>1&&num2<hd2;v-=2)   
        ans+=D2[num2++].val;  
    sort(D1,D1+hd1);  
    for(;v>0&&num1<hd1;v-=1)    
        ans+=D1[num1++].val;
    tmp=ans;
    for(int i=num2-1,j;i>=0;i--) {    
        tmp-=D2[i].val;          
        v+=2;
        for(j=num1;j<hd1&&v>0;j++) 
        {     
            tmp+=D1[j].val;
            v-=1;
        }
        if(ans<tmp) 
        {      
            ans=tmp;
            num1=j;
            num2-=1;
        }
        else
            break;
    }
    printf("%lld\n",ans);
    for(int i=0;i<num2;i++)    
        printf("%d ",D2[i].id);
    for(int i=0;i<num1;i++)
        printf("%d ",D1[i].id);
    return 0;
}