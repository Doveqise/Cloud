#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
long long n, m, a[maxn], sum[maxn], f[maxn], d[maxn];
int q[maxn], head = 0, tail = 1;
long long solve(int i)
{
    d[i] = f[i - 1] - sum[i];
    while (head <= tail && d[q[tail]] < d[i])
        tail--;
    q[++tail] = i;
    while (head <= tail && q[head] < i - m)
        head++;
    return d[q[head]];
}
int main()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i])    ;
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
        f[i] = solve(i) + sum[i];
    printf("%lld\n", f[n]);
    return 0;
}