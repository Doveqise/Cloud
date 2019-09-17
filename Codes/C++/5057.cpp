#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e6 + 5;
int node[maxn];
int n, m;
int lowbit(int x)
{
    return x & (-x);
}
void add(int x, int val)
{
    while (x <= n)
    {
        node[x] += val;
        x += lowbit(x);
    }
}
int query(int x)
{
    int res = 0;
    while (x)
    {
        res += node[x];
        x -= lowbit(x);
    }
    return res;
}
signed main()
{
    scanf("%lld%lld", &n, &m);
    while (m--)
    {
        int opt, a, b;
        scanf("%lld", &opt);
        switch (opt)
        {
        case 1:
            scanf("%lld%lld", &a, &b);
            add(a, 1);
            add(b + 1, -1);
            break;
        case 2:
            scanf("%lld", &a);
            printf("%lld\n", query(a) & 1);
            break;
        }
    }
    return 0;
}