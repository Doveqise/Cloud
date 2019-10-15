#include <bits/stdc++.h>
#define mid ((l + r) >> 1)
using namespace std;
const int maxn = 2e5 + 5;
char opt[10];
int sizz, ls[maxn << 6], rs[maxn << 6], rt[maxn << 6], sum[maxn << 6];
int bitl[maxn], bitr[maxn];
int n, m, b[maxn], c[maxn], totl, totr, siz, cnt;
struct node
{
    int a, b, c, x, y;
} q[maxn];
int lowbit(int x)
{
    return x & (-x);
}
void insert(int &u, int l, int r, int pos, int x)
{
    if(!u)u = ++cnt;
    sum[u]+=x;
    if (l < r)
    {
        if (pos <= mid)
            insert(ls[u],l, mid, pos, x);
        else
            insert(rs[u],mid + 1, r, pos, x);
    }
    return ;
}
void add(int x, int v)
{
    int pos = lower_bound(c + 1, c + sizz + 1, b[x]) - c;
    for (int j = x; j <= n; j += lowbit(j))
        insert(rt[j], 1, sizz, pos, v);
}
int query(int l, int r, int k)
{
    if (l == r)
        return l;
    int suml = 0;
    for (int k = 1; k <= totl; k++)
        suml -= sum[ls[bitl[k]]];
    for (int k = 1; k <= totr; k++)
        suml += sum[ls[bitr[k]]];
    if (k <= suml)
    {
        for (int k = 1; k <= totl; k++)
            bitl[k] = ls[bitl[k]];
        for (int k = 1; k <= totr; k++)
            bitr[k] = ls[bitr[k]];
        return query(l, mid, k);
    }
    else
    {
        for (int k = 1; k <= totl; k++)
            bitl[k] = rs[bitl[k]];
        for (int k = 1; k <= totr; k++)
            bitr[k] = rs[bitr[k]];
        return query(mid + 1, r, k - suml);
    }
}
signed main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
        c[++siz] = b[i];
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%s", opt);
        switch (opt[0])
        {
        case 'Q':
            scanf("%d%d%d", &q[i].a, &q[i].b, &q[i].c);
            break;
        default:
            scanf("%d%d", &q[i].x, &q[i].y);
            c[++siz] = q[i].y;
            break;
        }
    }
    sort(c + 1, c + siz + 1);
    sizz = unique(c + 1, c + siz + 1) - c - 1;
    for (int i = 1; i <= n; i++)
        add(i, 1);
    for (int i = 1; i <= m; i++)
    {
        if (q[i].c)
        {
            totl = totr = 0;
            for (int j = q[i].a - 1; j; j -= lowbit(j))
                bitl[++totl] = rt[j];
            for (int j = q[i].b; j; j -= lowbit(j))
                bitr[++totr] = rt[j];
            printf("%d\n", c[query(1, sizz, q[i].c)]);
        }
        else
        {
            add(q[i].x, -1);
            b[q[i].x] = q[i].y;
            add(q[i].x, 1);
        }
    }
}