#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
char ch[maxn];
signed main()
{
    int n, p1 = 0, p2 = 0, base = 1, ans;
    scanf("%d%s", &n, ch + 1);
    ans = n;
    for (int i = 1; i < n; i++)
    {
        p1 = p1 * 37 + ch[i];
        p2 = ch[n - i + 1] * base + p2;
        base *= 37;
        if (p1 == p2)
            ans = n - i;
    }
    printf("%d\n", ans);
    return 0;
}