#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
#define int long long
int dp[maxn], s[maxn], a, b, c, n;
int q[maxn], h, tt;
inline double calc(int x1, int x2)
{
    return (double)(dp[x1] + a * s[x1] * s[x1] - b * s[x1] - dp[x2] - a * s[x2] * s[x2] + b * s[x2]) / (s[x1] - s[x2]);
}
#undef int
int main()
{
    scanf("%lld", &n);
    scanf("%lld%lld%lld", &a, &b, &c);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &s[i]);
        s[i] += s[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        while (h < tt && calc(q[h + 1], q[h]) > (long long)2 * a * s[i])
            h++;
        dp[i] = dp[q[h]] + a * (s[i] - s[q[h]]) * (s[i] - s[q[h]]) + b * (s[i] - s[q[h]]) + c;
        while (h < tt && calc(q[tt], q[tt - 1]) < calc(i, q[tt]))
            tt--;
        q[++tt] = i;
    }
    printf("%lld", dp[n]);
    return 0;
}
