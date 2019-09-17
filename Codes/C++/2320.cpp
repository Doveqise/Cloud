#include <bits/stdc++.h>
const int maxn = 30 << 1 | 1;
int a[maxn];
signed main()
{
    int n, cnt = 0;
    scanf("%d", &n);
    while (n)
    {
        a[++cnt] = (n + 1) >> 1;
        n >>= 1;
    }
    printf("%d\n", cnt);
    for (int i = cnt; i; i--)
        printf("%d ", a[i]);
    return 0;
}