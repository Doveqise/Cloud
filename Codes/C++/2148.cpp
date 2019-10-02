#include <bits/stdc++.h>
using namespace std;
int read()
{
    int x;
    scanf("%d", &x);
    return x;
}
signed main()
{
    int T = read(), ans;
    while ((T--) && (!(ans = 0)))
    {
        for (int i = 0, n = read() >> 1; i < n; i++)
            ans ^= __builtin_ctz(((read() - 1) | (read() - 1)) + 1);
        puts(ans ? "YES" : "NO");
    }
}