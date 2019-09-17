#include <cstdio>
#include <set>
using namespace std;
const int maxn = 1e6+5;
const int INF = 123456789;
int n, ans;
set<int>s;
set<int>::iterator l,r;
void find(int x) {
    l=--s.lower_bound(x),r=s.lower_bound(x);
    if(x-*l<=*r-x&&*l!=-INF)
    {
        ans+=x-*l;
        s.erase(l);
    }
    else
    {
        ans+=*r-x;
        s.erase(r);
    }
    ans %= 1000000;
}
int main()
{
    scanf("%d", &n);
    int cur;
    s.insert( -INF ), s.insert( INF );
    for(int i = 1; i <= n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if(s.size() == 2) 
        {
            cur = a;
            s.insert(b);
        } 
        else if(a == cur) 
            s.insert(b);
        else find(b);
    }
    printf("%d\n", ans);
    return 0;
}