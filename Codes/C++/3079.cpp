#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 5;
struct node
{
    int x1, y1, x2, y2;
    bool operator<(const node &b) const
    {
        return x1 < b.x1;
    }
} 
a[maxn];
signed main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
    sort(a + 1, a + 1 + n);
    int ans = n;
    for (int i = 1, j = 2; j <= n; j++)
    {
        while (a[i].x2 <= a[j].x1) i++;
        for (int l = i; l < j; l++)
            if (a[l].y1 < a[j].y1 && a[l].x2 > a[j].x2 && a[l].y2 > a[j].y2)
            {ans--;break;}
    }
    printf("%d", ans);
    return 0;
}