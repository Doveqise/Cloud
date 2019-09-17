#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
const int maxk = 5e2 + 5;
const int lar = 6e3 + 5;
int n, k, mx, ans;
int h[maxn], tree[lar][maxk];
int lowbit(const int a)
{
    return a & (-a);
}
void update(int pos, const int val, int sel)
{
    for (; pos <= mx + k; pos += lowbit(pos))
        for (int i = sel; i <= k + 1; i += lowbit(i))
            tree[pos][i] = max(tree[pos][i], val);
}
int search(int pos, int sel)
{
    int ans = 0;
    for (; pos; pos -= lowbit(pos))
        for (int i = sel; i; i -= lowbit(i))
            ans = max(ans, tree[pos][i]);
    return ans;
}
int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &h[i]);
        mx = max(mx, h[i]);
    }
    for (int i = 1; i <= n; i++)
        for (int j = k; j >= 0; j--)
        {
            int x = search(h[i] + j, j + 1) + 1;
            ans = max(ans, x);
            update(h[i] + j, x, j + 1);
        }
    printf("%d\n", ans);
    return 0;
}