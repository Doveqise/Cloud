#include <bits/stdc++.h>
using namespace std;
int n, a, b, f[100005];
inline int read()
{
    int ans = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}
int main()
{
    n = read(), a = read(), b = read();
    for (int i = 1; i <= n; i++)
    {
        char ch = getchar();
        f[i] = ch;
    }
    if (f[a] == f[b])
        putchar('0');
    else
        putchar('1');
}