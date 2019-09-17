#include<bits/stdc++.h>
using namespace std;
int ans,sum;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1,a,b;i<=n;i++){
        scanf("%d%d",&a,&b);#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
int n,m; 
int a[MAXN];
int c[MAXN];
int ans[MAXN];

int solve(int x) {
    int rt = 0,ans = 0;
    int ls = 0;
    memset(c,0,sizeof(c));
    for(int i = 1; i <= n; i ++) {
        c[a[i]] ++; 
        if(c[a[i]] == 1) {
            rt ++;
        }
        if(rt > x) {
            i --;
            for(int j = ls; j <= i+1; j ++)
                c[a[j]] --;
            rt = 0;
            ls = i+1;
            ans ++;
        }
    }
    ans ++;
    return ans;
}

void orz(int l,int r)
{
    int sl = solve(l),sr = solve(r);
    if(sl == sr) {
        for(int j = l; j <= r; j ++)
            ans[j] = sl;
     } else {
        int mid = (l+r)>>1;
        orz(l,mid);
        orz(mid+1,r);
     }
} 

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    int o = 0;
    for(int i = 1; i*i <= n*log2(n); i ++)
    {    o = i;
        ans[i] = solve(i);
    }
    orz(o+1,n);
    for(int i = 1; i <= n; i ++)
        cout<<ans[i]<<"\n"; 
    return 0;
}
        a<0?ans++:sum++;
    }
    if(ans==1||sum==1||ans==0||sum==0)
        puts("Yes");
    else
        puts("No");
    return 0;
}