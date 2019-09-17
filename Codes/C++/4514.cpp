#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include <bits/stdc++.h>
const int maxn = 3e3 + 5;
int n, m, ans, tree[4][maxn][maxn];
char readc()
{
    char ch;
    while (ch = getchar(), ch != EOF && !isalpha(ch))
        ;
    return ch;
}
template <typename T>
inline void read(T &x)
{
    x = 0;
    char ch;
    bool flg = 0;
    while (ch = getchar(), ch < 48 || 57 < ch)
        flg ^= !(ch ^ '-');
    x = (ch & 15);
    while (ch = getchar(), 47 < ch && ch < 58)
        x = (x << 1) + (x << 3) + (ch & 15);
    if (flg)
        x = -x;
}
void add(int x, int y, int w)
{
    if (x < 1 || n < x || y < 1 || m < y)
        return;
    for (int i = x; i <= n; i += i & -i)
        for (int j = y; j <= m; j += j & -j)
        {
            tree[0][i][j] += w;
            tree[1][i][j] += w * y;
            tree[2][i][j] += w * x;
            tree[3][i][j] += w * x * y;
        }
}
int query(int x, int y)
{
    int res = 0;
    for (int i = x; i; i -= i & -i)
        for (int j = y; j; j -= j & -j)
            res = res + (x + 1) * (y + 1) * tree[0][i][j] - (x + 1) * tree[1][i][j] - (y + 1) * tree[2][i][j] + tree[3][i][j];
    return res;
}

int main()
{
    readc();
    read(n), read(m);
    int a, b, c, d, w;
    char opt;
    while (opt = readc(), opt != EOF)
    {
        read(a), read(b), read(c), read(d);
        if (opt == 'L')
        {
            read(w);
            add(a, b, w);
            add(c + 1, b, -w);
            add(a, d + 1, -w);
            add(c + 1, d + 1, w);
        }
        else
            printf("%d\n", query(c, d) - query(a - 1, d) - query(c, b - 1) + query(a - 1, b - 1));
    }
    return 0;
}