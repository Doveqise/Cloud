#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int nxt[maxn], f[maxn], h[maxn];
char str[maxn];
signed main()
{
    int n;
    scanf("%s", str + 1);
    n = strlen(str + 1);
    nxt[0] = -1;
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j != -1 && str[j + 1] != str[i])
            j = nxt[j];
        nxt[i] = ++j;
    }
    f[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        f[i] = i;
        if (h[f[nxt[i]]] >= i - nxt[i])
            f[i] = f[nxt[i]];
        h[f[i]] = i;
    }
    printf("%d\n", f[n]);
    return 0;
}