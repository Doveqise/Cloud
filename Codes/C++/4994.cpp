#include <bits/stdc++.h>
int f[3] = {0, 1, 1};
signed main()
{
    int M;
    scanf("%d", &M);
    for (int i = 1; i; i++)
    {
        f[2] = f[0];
        f[0] = f[1];
        f[1] = (f[2] + f[1]) % M;
        if ((!f[0] % M) && (!(f[1] % M - 1)))
            return printf("%d", i), 0;
    }
}