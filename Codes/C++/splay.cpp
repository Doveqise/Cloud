#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, rt = 0, tot = 0;
struct splaytree
{
    int son[2];
    int cnt, val, siz, fa;
    int flag;
} node[maxn];
void pushup(int x)
{
    node[x].siz = node[node[x].son[0]].siz + node[node[x].son[1]].siz + /*多个相同数值时为node[x].cnt*/ 1;
    return;
}
void pushdown(int x)
{
    if (node[x].flag)
    {
        swap(node[x].son[0], node[x].son[1]);
        node[node[x].son[0]].flag ^= 1;
        node[node[x].son[1]].flag ^= 1;
        node[x].flag = 0;
    }
    return;
}
int findson(int x)
{
    return node[node[x].fa].son[1] == x;
}
void build(int l, int r, int &x)
{
    x = (l + r) >> 1;
    node[x].siz = 1;
    if (l < x)
    {
        build(l, x - 1, node[x].son[0]);
        node[node[x].son[0]].fa = x;
    }
    if (x < r)
    {
        build(x + 1, r, node[x].son[1]);
        node[node[x].son[1]].fa = x;
    }
    pushup(x);
    return;
}
void rotate(int x)
{
    int fa = node[x].fa, gp = node[fa].fa;
    int d = findson(x), dd = findson(fa);
    node[fa].son[d] = node[x].son[d ^ 1];
    node[node[fa].son[d]].fa = fa;
    node[x].son[d ^ 1] = fa;
    node[fa].fa = x;
    node[x].fa = gp;
    if (gp)
        node[gp].son[dd] = x;
    pushup(x);
    pushup(fa);
    return;
}
void rotate(int x, int &k)
{
    int fa = node[x].fa, gp = node[fa].fa, d = findson(x);
    if (fa ^ k)
        node[gp].son[findson(fa)] = x;
    else
        k = x;
    node[x].fa = gp;
    node[fa].son[d] = node[x].son[d ^ 1];
    node[node[x].son[d ^ 1]].fa = fa;
    node[x].son[d ^ 1] = fa;
    node[fa].fa = x;
    pushup(fa);
    pushup(x);
    return;
}
void splay(int x)
{
    for (int fa = node[x].fa; fa = node[x].fa; rotate(x))
        if (node[fa].fa)
            rotate(findson(fa) == findson(x) ? fa : x);
    rt = x;
    return;
}
void splay(int x, int &k)
{
    for (int fa = node[x].fa; x ^ k; fa = node[x].fa)
    {
        if (fa ^ k)
            rotate(findson(fa) ^ findson(x) ? x : fa, k);
        rotate(x, k);
    }
    return;
}
void ins(int &x, int val, int fa)
{
    if (!x)
    {
        x = ++tot;
        node[x].val = val;
        node[x].cnt = node[x].siz = 1;
        node[x].fa = fa;
        node[x].son[0] = node[x].son[1] = 0;
        splay(x);
        return;
    }
    if (node[x].val == val)
    {
        node[x].cnt++;
        pushup(x);
        pushup(node[x].fa);
        splay(x);
    }
    else if (node[x].val > val)
        ins(node[x].son[0], val, x);
    else
        ins(node[x].son[1], val, x);
    return;
}
int rk(int val)
{
    int x = rt, rk = 0;
    while (x)
    {
        if (node[x].val == val)
        {
            rk += node[node[x].son[0]].siz;
            splay(x);
            return rk + 1;
        }
        else if (node[x].val > val)
            x = node[x].son[0];
        else
        {
            rk += node[node[x].son[0]].siz + node[x].cnt;
            x = node[x].son[1];
        }
    }
}
void del(int x)
{
    rk(x);
    if (--node[rt].cnt)
        return;
    if ((!node[rt].son[0]) && (!node[rt].son[1]))
        rt = 0;
    else if (!node[rt].son[0])
    {
        rt = node[rt].son[1];
        node[rt].fa = 0;
        pushup(rt);
    }
    else if (!node[rt].son[1])
    {
        rt = node[rt].son[0];
        node[rt].fa = 0;
        pushup(rt);
    }
    else
    {
        int pre = node[rt].son[0], k = rt;
        while (node[pre].son[1])
            pre = node[pre].son[1];
        splay(pre);
        node[node[k].son[1]].fa = rt;
        node[rt].son[1] = node[k].son[1];
        pushup(rt);
    }
    return;
}
int val(int rk)
{
    int x = rt;
    while (x)
    {
        if (node[node[x].son[0]].siz >= rk)
            x = node[x].son[0];
        else if (node[node[x].son[0]].siz + node[x].cnt >= rk)
        {
            splay(x);
            return node[x].val;
        }
        else
        {
            rk -= node[node[x].son[0]].siz + node[x].cnt;
            x = node[x].son[1];
        }
    }
}
int val2(int pos)
{
    int x = rt;
    while (x)
    {
        pushdown(x);
        if (node[node[x].son[0]].siz == pos)
            return x;
        else if (node[node[x].son[0]].siz > pos)
            x = node[x].son[0];
        else
        {
            pos -= node[node[x].son[0]].siz + 1;
            x = node[x].son[1];
        }
    }
}
void reverse(int x, int y)
{
    int l = val2(x - 1), r = val2(y + 1);
    splay(l, rt);
    splay(r, node[rt].son[1]);
    node[node[node[rt].son[1]].son[0]].flag ^= 1;
    return;
}
int pre(int val)
{
    int x = rt, pre;
    while (x)
    {
        if (node[x].val < val)
        {
            pre = node[x].val;
            x = node[x].son[1];
        }
        else
            x = node[x].son[0];
    }
    return pre;
}
int nxt(int val)
{
    int x = rt, nxt;
    while (x)
    {
        if (node[x].val > val)
        {
            nxt = node[x].val;
            x = node[x].son[0];
        }
        else
            x = node[x].son[1];
    }
    return nxt;
}
signed main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int opt, t;
        scanf("%d%d", &opt, &t);
        switch (opt)
        {
        case 1:
            ins(rt, t, 0);
            break;
        case 2:
            del(t);
            break;
        case 3:
            printf("%d\n", rk(t));
            break;
        case 4:
            printf("%d\n", val(t));
            break;
        case 5:
            printf("%d\n", pre(t));
            break;
        case 6:
            printf("%d\n", nxt(t));
            break;
        }
    }
    return 0;
    /*
    int n, m;
    scanf("%d%d", &n, &m);
    build(1, n + 2, rt);
    while (m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        reverse(l, r);
    }
    for (int i = 1; i <= n; i++)
        printf("%d\n ", val2(i) - 1);
    return 0;
    */
}