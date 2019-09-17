#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int P = 39989;
const int mod = 1e9;
const int eps = 1e-10;
int t[maxn << 2], a[maxn];
int ansa, x2, y2, x, y, n, lastans, top, kind;
double b[maxn], ansb;
struct node
{
    double k, b;
    int l, r;
    double f(int x)
    {
        return k * x + b;
    }
} line[maxn];
int pt(node a, node b)
{
    return floor((b.b - a.b) / (a.k - b.k));
}
node cal(int x, int y, int x2, int y2)
{
    node ret;
    ret.l = min(x, x2);
    ret.r = max(x, x2);
    if (ret.l != ret.r)
    {
        ret.k = (y2 - y) / (double)(x2 - x);
        ret.b = y - ret.k * x;
    }
    else
    {
        ret.k = 0.0;
        ret.b = max(y, y2);
    }
    return ret;
}
int chk0(double x)
{
    return (x > -eps) - (x < eps);
}
void pia(int k, int x)
{
    double t = line[k].f(x);
    int ff = chk0(t - b[x]);
    if (!a[x] || (ff > 0 || ((!ff) && k < a[x])))
    {
        a[x] = k;
        b[x] = t;
    }
}

void ins(int k, int l, int r, int x)
{
    if (line[x].l <= l && r <= line[x].r)
    {
        if (!t[k])
        {
            t[k] = x;
            return;
        }
        else
        {
            int fl = chk0(line[x].f(l) - line[t[k]].f(l)) > 0;
            int fr = chk0(line[x].f(r) - line[t[k]].f(r)) > 0;
            if (fl && fr)
                t[k] = x;
            else if (fl || fr)
            {
                int mid = (l + r) >> 1;
                int p = pt(line[x], line[t[k]]);
                if (p <= mid && fl)
                    ins(k << 1, l, mid, x);
                if (p <= mid && fr)
                    ins(k << 1, l, mid, t[k]), t[k] = x;
                if (p > mid && fl)
                    ins(k << 1 | 1, mid + 1, r, t[k]), t[k] = x;
                if (p > mid && fr)
                    ins(k << 1 | 1, mid + 1, r, x);
            }
            else
                pia(x, l), pia(x, r);
        }
        return;
    }
    int mid = (l + r) >> 1;
    if (line[x].l <= mid)
        ins(k << 1, l, mid, x);
    if (line[x].r > mid)
        ins(k << 1 | 1, mid + 1, r, x);
}
void query(int k, int l, int r, int x)
{
    if (t[k])
    {
        double tt = line[t[k]].f(x);
        int ff = chk0(tt - ansb);
        if ((ff > 0 || ((!ff) && ansa < t[k])))
        {
            ansa = t[k];
            ansb = tt;
        }
    }
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    if (x <= mid)
        query(k << 1, l, mid, x);
    else
        query(k << 1 | 1, mid + 1, r, x);
}
signed main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &kind);
        if (kind)
        {
            scanf("%d%d%d%d", &x, &y, &x2, &y2);
            x = (x + lastans - 1) % P + 1;
            x2 = (x2 + lastans - 1) % P + 1;
            y = (y + lastans - 1) % mod + 1;
            y2 = (y2 + lastans - 1) % mod + 1;
            line[++top] = cal(x, y, x2, y2);
            ins(1, 1, P, top);
        }
        else
        {
            scanf("%d", &x);
            ansa = 0;
            ansb = -1.0;
            x = (x + lastans - 1) % P + 1;
            query(1, 1, P, x);
            int ff = chk0(b[x] - ansb);
            if ((ff > 0 || ((!ff) && a[x] < ansa)))
            {
                ansa = a[x];
            }
            lastans = ansa;
            printf("%d\n", lastans);
        }
    }
    return 0;
}
