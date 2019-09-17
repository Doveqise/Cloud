#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e9 + 7;
int l, k;
struct node
{
    int x, y, z;
    void init()
    {
        scanf("%d%d%d", &x, &y, &z);
        if (x > y)
            swap(x, y);
        if (x > z)
            swap(x, z);
        if (y > z)
            swap(y, z);
    }
} a, b, p, q;
bool judge(node u, node v)
{
    return u.x == v.x && u.y == v.y && u.z == v.z;
}
node findfa(node t, int s)
{
    for (l = 0; s; l += k)
    {
        int u = t.y - t.x, v = t.z - t.y;
        if (u == v)
            return t;
        if (u < v)
        {
            k = min((v - 1) / u, s);
            t.x += k * u;
            t.y += k * u;
            s -= k;
        }
        else
        {
            k = min((u - 1) / v, s);
            t.y -= k * v, t.z -= k * v, s -= k;
        }
    }
    return t;
}
signed main()
{
    a.init(), b.init();
    p = findfa(a, inf);
    int l1 = l;
    q = findfa(b, inf);
    int l2 = l;
    if (!judge(p, q))
    {
        puts("NO");
        return 0;
    }
    if (l1 < l2)
        swap(a, b), swap(l1, l2);
    a = findfa(a, l1 - l2);
    int l = 0, r = l2, mid;
    while (l < r)
    {
        mid = l + r >> 1;
        if (judge(findfa(a, mid), findfa(b, mid)))
            r = mid;
        else
            l = mid + 1;
    }
    printf("YES\n%d\n", (l << 1) + l1 - l2);
    return 0;
}