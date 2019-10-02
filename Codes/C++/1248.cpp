#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int tot, tot1, ta[maxn], tb[maxn];
struct node
{
    int a, b, c;
} a[maxn], b[maxn];
bool cmp(node a, node b)
{
    return a.a < b.a;
}
bool cmp1(node a, node b)
{
    return a.b > b.b;
}
bool cmp2(node a, node b)
{
    return a.a <= b.a;
}
bool cmp3(node a, node b)
{
    return a.b >= b.b;
}
signed main()
{
    int n, ans = 0, ans1 = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &ta[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &tb[i]);
    for (int i = 1; i <= n; i++)
        if (ta[i] < tb[i])
            a[++tot] = (node){ta[i], tb[i], i};
        else
            b[++tot1] = (node){ta[i], tb[i], i};
    sort(a + 1, a + tot + 1, cmp);
    sort(b + 1, b + tot1 + 1, cmp1);
    for (int i = 1; i <= tot; i++)
    {
        ans += a[i].a;
        ans1 -= a[i].a;
        ans1 = max(ans1, 0);
        ans1 += a[i].b;
    }
    for (int i = 1; i <= tot1; i++)
    {
        ans += b[i].a;
        ans1 -= b[i].a;
        ans1 = max(ans1, 0);
        ans1 += b[i].b;
    }
    printf("%d\n", ans + ans1);
    sort(a + 2, a + tot + 1, cmp2);
    sort(b + 2, b + tot1 + 1, cmp3);
    for (int i = 1; i <= tot; i++)
        printf("%d ", a[i].c);
    for (int i = 1; i <= tot1; i++)
        printf("%d ", b[i].c);
    return 0;
}