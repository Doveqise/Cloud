#include <bits/stdc++.h>
#include <cmath>
#define ll long long
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
#define each(i, u) for (int i = head[u]; i; i = bow[i].nxt)
#define pt(ch) putchar(ch)
#define pti(x) printf("%d", x)
#define ptll(x) printf("%I64d", x)
using namespace std;
int ci()
{
    char ch;
    while (isspace(ch = getchar()))
        ;
    static int f;
    f = ch == '-' ? -1 : 1;
    int x = (ch == '-' ? getchar() : ch) ^ '0';
    while (isdigit(ch = getchar()))
        x = (x * 10) + (ch ^ '0');
    return f * x;
}
enum
{
    N = 100023
};
class ob
{
public:
    int x, y;
    bool operator<(const ob &e) const
    {
        return x == e.x ? y < e.y : x < e.x;
    }
} d[N];
int *pa[N];
bool cmp1(int *a, int *b)
{
    return *a < *b;
}
int c[N][11];
int S, tr[N], a[N];
int lowbit(int x) { return x & -x; }
void add(int i, int x)
{
    for (; i <= S; i += lowbit(i))
        tr[i] += x;
}
int query(int i)
{
    int ans = 0;
    for (; i; i -= lowbit(i))
        ans += tr[i];
    return ans;
}
int sum[N], cur[N];
int main()
{
    ci(), ci();
    int n = ci();
    rep(i, 1, n)
    {
        d[i].x = ci(), pa[i] = &(d[i].y = ci());
    }
    int k = ci();
    {
        sort(pa + 1, pa + n + 1, cmp1);
        int t = -1, cur = 0;
        rep(i, 1, n)
        {
            *pa[i] = (*pa[i] == t) ? (cur) : (t = *pa[i], ++cur);
            sum[*pa[i]]++;
        }
        S = cur;
    }
    sort(d + 1, d + n + 1);
    {
        c[0][0] = 1;
        rep(i, 1, n)
        {
            c[i][0] = 1;
            rep(j, 1, k) c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    int ans = 0;
    {
        int t = -1, L, R, x, y, now;
        d[n + 1].x = -1;
        rep(i, 1, n)
        {
            x = d[i].x, y = d[i].y;
            if (x != t)
            {
                t = x, L = 0, R = 0;
                int j = i;
                while (d[j].x == t)
                    j++, R++;
            }
            else
            {
                ans += c[L][k] * c[R][k] * (query(y - 1) - query(d[i - 1].y));
            }
            cur[y]++;
            now = c[cur[y]][k] * c[sum[y] - cur[y]][k];
            add(y, now - a[y]);
            a[y] = now;
            L++, R--;
        }
    }
    pti(ans & 0x7fffffff);
    return 0;
}