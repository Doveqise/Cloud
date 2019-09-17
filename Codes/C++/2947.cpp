#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], ans[maxn];
signed main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = n - 1; i; i--)
    {
        int j = i + 1;
        while (a[i] >= a[j] && a[j])
            j = ans[j];
        ans[i] = j;
    }
    for (int i = 1; i <= n; i++)
        printf("%d\n", ans[i]);
    return 0;
}