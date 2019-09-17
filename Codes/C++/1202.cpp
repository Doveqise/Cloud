#include <bits/stdc++.h>
using namespace std;
int d[2][13] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 0};
struct node
{
    int yy, mm, ww;
    bool operator<(const node &a, const node &b)
    {
        if (a.yy != b.yy)
            return a.yy < b.yy;
        if (a.mm != b.mm)
            return a.mm < b.mm;
        return 0;
    }
    void operator++(node &a)
    {
        bool spl = 0;
        if (!(a.yy % 400))
            spl = 1;
        if ((a.yy % 100) && !(a.yy % 4))
            spl = 1;
        a.ww += d[spl][a.mm++], a.ww %= 7;
        if (a.mm == 12)
            a.yy++, a.mm = 0;
    }
};
signed main()
{
    int n, t[7] = {0};
    scanf("%d", &n);
    node a = (node){1900, 0, 5};
    node b = (node){1900 + n - 1, 11, -1};
    while (!(b < a))
        t[a.ww]++, ++a;
    for (int i = 5; i < 12; i++)
        printf("%d ", t[i % 7]);
    return 0;
}