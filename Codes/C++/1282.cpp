#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int u, dw, ans, n;
int a[maxn], d[maxn];
int main()
{
    scanf("%d", &n);
    int p, q;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &p, &q);
        a[i] = p - q;
        u += p;
        dw += q;
    }
    int s = dw - u;
    if (!s)
    {
        puts("0");
        return 0;
    }
    sort(a + 1, a + 1 + n);
    if (s < 0)
        for (int i = n; i >= 1; i--)
        {
            if (a[i] > 0 && s + a[i] * 2 <= 0)
            {
                s += (a[i] * 2);
                ans++;
            }
            else
                continue;
        }
    else
        for (int i = 1; i <= n; i++)
        {
            if (a[i] < 0 && s + a[i] * 2 >= 0)
            {
                s += (a[i] * 2);
                ans++;
            }
            else
                continue;
        }
    int maxx = 0;
    int k = 1;
    for (int i = 1; i <= n; i++)
    {
        maxx = 0;
        for (int j = i + 1; j <= n; j++)
        {
            int c = a[i] + a[j];
            if (abs(s) > abs(s + (c * 2)) && abs(c) > abs(maxx))
            {
                d[k] = c;
                maxx = c;
            }
        }
        k++;
    }
    sort(d + 1, d + k + 1);
    for (int i = k; i >= 1; i--)
    {
        if (abs(s) > abs(s + d[i] * 2))
        {
            ans += 2;
            s += d[i] * 2;
        }
    }
    printf("%d\n", ans);
    return 0;
}