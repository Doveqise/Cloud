#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
struct node
{
    int x, y, z, id;
} a[maxn];
int c[maxn << 2], k, n, b[maxn], bj[maxn], f[maxn];
int lowbit(int x) { return x & (-x); }
void add(int x, int v)
{
    for (; x <= k; x += lowbit(x))
        c[x] += v;
}
int query(int x)
{
    int ans = 0;
    for (; x; x -= lowbit(x))
        ans += c[x];
    return ans;
}
bool cmp1(node a, node b)

{
    return a.x == b.x ? (a.y == b.y ? (a.z < b.z) : (a.y < b.y)) : (a.x < b.x);
}
bool cmp2(node a, node b)

{
    return a.y == b.y ? (a.z == b.z ? (a.x < b.x) : (a.z < b.z)) : (a.y < b.y);
}
void solve(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) >> 1, flag;
    solve(l, mid), solve(mid + 1, r);
    sort(a + l, a + r + 1, cmp2);
    for (int i = l; i <= r; i++)
        (a[i].x <= mid) ? add(a[i].z, 1), flag = i : b[a[i].id] += query(a[i].z);
    for (int i = l; i <= r; i++)
        if (a[i].x <= mid)
            add(a[i].z, -1);
}
signed main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &a[a[i].id = i].x, &a[i].y, &a[i].z);
    sort(a + 1, a + 1 + n, cmp1);
    for (int i = 1; i <= n;)
    {
        int j = i + 1;
        while (j <= n && a[j].x == a[i].x && a[j].y == a[i].y && a[j].z == a[i].z)
            j++;

        while (i < j)

            bj[a[i].id] = a[j - 1].id, i++;
    }
    for (int i = 1; i <= n; i++)
        a[i].x = i;
    solve(1, n);
    for (int i = 1; i <= n; i++)
        f[b[bj[a[i].id]]]++;

    for (int i = 0; i < n; i++)
        printf("%d\n", f[i]);
}