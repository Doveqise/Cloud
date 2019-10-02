#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;
const int mod = 1e9 + 7;
char str[maxn];
int f[maxn][maxn << 5];
signed main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < 26; i++)
        f[1][i] = 1;
    for (int i = 2; i < maxn; i++)
    {
        f[i][0] = 1;
        for (int j = 1; j <= maxn * 26; j++)
            for (int k = 0; k < 26; k++)
                if (j - k >= 0)
                    f[i][j] = (f[i][j] % mod + f[i - 1][j - k] % mod) % mod;
    }
    while (T--)
    {
        memset(str, 0, sizeof(str));
        scanf("%s", str);
        int len = strlen(str), tot = 0;
        for (int i = 0; i < len; i++)
            tot += str[i] - 'a';
        printf("%d\n", f[len][tot] - 1);
    }
}