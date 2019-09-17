#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 5;
int a[maxn], l[7], r[7];
int rd()
{
    int x;
    scanf("%d", &x);
    return x;
}
signed main()
{
    int n = rd(), mx = -1;
    for (int i = 1; i <= n; i++)
        a[i] = (rd() + a[i - 1]) % 7;
    for (int i = n; i >= 1; i--)
        l[a[i]] = i;
    for (int i = 1; i <= n; i++)
        r[a[i]] = i;
    for (int i = 0; i <= 6; i++)
        mx = max(r[i] - l[i], mx);
    printf("%d\n", mx);
}