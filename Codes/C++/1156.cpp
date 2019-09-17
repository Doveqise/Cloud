#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;
struct node
{
    int t, h, l;
    bool operator<(const node b) const
    {
        return t < b.t;
    }
} c[maxn];
int ti[maxn], f[maxn];
signed main()
{
    //memset(f,-1,sizeof(f));
    f[0] = 10;
    int d, g;
    scanf("%d%d", &d, &g);
    for (int i = 1; i <= g; i++)
        scanf("%d%d%d", &c[i].t, &c[i].l, &c[i].h);
    sort(c + 1, c + 1 + g);
    for (int i = 1; i <= g; i++)
        for (int j = d; j >= 0; j--)
        {
            if (f[j] >= c[i].t)
            {
                if (j + c[i].h >= d)
                {
                    printf("%d\n", c[i].t);
                    exit(0);
                }
                f[j + c[i].h] = max(f[j + c[i].h], f[j]);
                f[j] += c[i].l;
            }
        }
    printf("%d\n", f[0]);
    return 0;
}