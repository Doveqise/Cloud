#include <bits/stdc++.h>
int a[25];
int sg[] = {0, 1, 2, 4, 7, 8, 11,
            13, 14, 16, 19, 21,
            22, 25, 26, 28, 31,
            32, 35, 37, 38, 41,
            42};
signed main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int tot = 0, ans = 0, n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            if (a[i] & 1)
                ans ^= sg[n - i];
        }
        for (int i = 1; i < n; i++)
            if (a[i])
                for (int j = i + 1; j <= n; j++)
                    for (int k = j; k <= n; k++)
                        if ((!(ans ^ sg[n - i] ^ sg[n - j] ^ sg[n - k])) && (!tot++))
                            printf("%d %d %d\n", i - 1, j - 1, k - 1);
        if (!tot)
            puts("-1 -1 -1");
        printf("%d\n", tot);
    }
    return 0;
}