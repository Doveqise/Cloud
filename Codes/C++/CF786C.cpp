#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, m, o;
int a[maxn], c[maxn], ans[maxn];
int solve(int x)
{
    int rt = 0, ans = 0, l = 0;
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++)
    {
        c[a[i]]++;
        if (c[a[i]] == 1)
            rt++;
        if (rt > x)
        {
            i--;
            for (int j = l; j <= i + 1; j++)
                c[a[j]]--;
            rt = 0;
            l = i + 1;
            ans++;
        }
    }
    ans++;
    return ans;
}

void bin(int l, int r)
{
    int sl = solve(l), sr = solve(r);
    if (sl == sr)
    {
        for (int j = l; j <= r; j++)
            ans[j] = sl;
        return;
    }
    else
    {
        bin(l, (l + r) >> 1);
        bin((l + r) >> 1 | 1, r);
        return;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i * i <= n * sqrt(n); i++)
    {
        o = i;
        ans[i] = solve(i);
    }
    bin(o + 1, n);
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    puts("");
    return 0;
}