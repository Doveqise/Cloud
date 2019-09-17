#include <bits/stdc++.h>
const int maxn = 3e5 + 5;
using namespace std;
int n;
int v[maxn], ch[maxn][2], fa[maxn], rev[maxn], sta[maxn], s[maxn], m[maxn];
inline int get(int x)
{
    return x == ch[fa[x]][0] || x == ch[fa[x]][1];
}
inline int chk(int x)
{
    return x == ch[fa[x]][1];
}
inline void pushup(int x)
{
    s[x] = s[ch[x][0]] + s[ch[x][1]] + v[x];
    m[x] = max(max(m[ch[x][0]], m[ch[x][1]]), v[x]);
}
inline void filp(int x)
{
    swap(ch[x][0], ch[x][1]);
    rev[x] ^= 1;
}
inline void pushdown(int x)
{
    if (!rev[x])
        return;
    rev[x] = 0;
    if (ch[x][0])
        filp(ch[x][0]);
    if (ch[x][1])
        filp(ch[x][1]);
}
inline void rotate(int x)
{
    int y = fa[x], z = fa[y], k = chk(x), w = ch[x][k ^ 1];
    if (get(y))
        ch[z][chk(y)] = x;
    ch[x][!k] = y, ch[y][k] = w;
    if (w)
        fa[w] = y;
    fa[y] = x, fa[x] = z;
    pushup(y);
    pushup(x);
}
inline void splay(int x)
{
    int y = x, top = 0;
    sta[++top] = y;
    while (get(y))
        sta[++top] = y = fa[y];
    while (top)
        pushdown(sta[top--]);
    while (get(x))
    {
        y = fa[x], top = fa[y];
        if (get(y))
            rotate(chk(x) == chk(y) ? y : x);
        rotate(x);
    }
    pushup(x);
    return;
}
inline void Access(int x)
{
    for (int y = 0; x; x = fa[y = x])
        splay(x), ch[x][1] = y, pushup(x);
}
inline void makeroot(int x)
{
    Access(x);
    splay(x);
    filp(x);
}
inline int findroot(int x)
{
    Access(x);
    splay(x);
    while (ch[x][0])
        pushdown(x), x = ch[x][0];
    return x;
}
inline void split(int x, int y)
{
    makeroot(x);
    Access(y);
    splay(y);
}
inline void link(int x, int y)
{
    makeroot(x);
    fa[x] = y;
}
int xx[maxn], yy[maxn], q;
int main()
{
    memset(m, -0x7f7f7f7f, sizeof(m));
    scanf("%d", &n);
    int x, y;
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        xx[i] = x;
        yy[i] = y;
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    for (int i = 1; i < n; i++)
        link(xx[i], yy[i]);
    scanf("%d", &q);
    char c[105];
    while (q--)
    {
        scanf("%s", c);
        if (c[0] == 'C')
        {
            scanf("%d%d", &x, &y);
            Access(x);
            splay(x);
            v[x] = y;
            continue;
        }
        else if (c[1] == 'M')
        {
            scanf("%d%d", &x, &y);
            split(x, y);
            printf("%d\n", m[y]);
            continue;
        }
        else
        {
            scanf("%d%d", &x, &y);
            split(x, y);
            printf("%d\n", s[y]);
            continue;
        }
    }
    return 0;
}