#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;
int n, g[maxn], f[maxn][maxn];
string str;
bool judge(int l, int r, int len)
{
    for (int i = l; i <= l + len - 1; i++)
    {
        char ch = str[i];
        for (int j = i; j <= r; j += len)
            if (str[j] != ch)
                return 0;
    }
    return 1;
}
signed main()
{
    cin >> str;
    n = str.size();
    str = " " + str;
    for (int i = 1; i <= 9; i++)
        g[i] = 1;
    for (int i = 10; i <= 99; i++)
        g[i] = 2;
    g[100] = 3;
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; i++)
        f[i][i] = 1;
    for (int len = 1; len <= n; len++)
        for (int i = 1, j = len; j <= n; i++, j++)
            for (int k = i; k < j; k++)
            {
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
                int l = k - i + 1;
                if (len % l)
                    continue;
                if (judge(i, j, l))
                    f[i][j] = min(f[i][j], g[len / l] + 2 + f[i][k]);
            }
    cout << f[1][n] << endl;
    return 0;
}