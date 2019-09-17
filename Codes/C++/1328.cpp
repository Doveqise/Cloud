#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e2 + 5;
int N, NA, NB, ans1, ans2;
int A[maxn], B[maxn];
int bian(int x, int flg)
{
    if (flg)
    {
        if (x == NB)
            return 1;
        return x + 1;
    }
    else
    {
        if (x == NA)
            return 1;
        return x + 1;
    }
}
int jud[6][6] =
    {
        {0, 0, 1, 1, 0},
        {1, 0, 0, 1, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 0, 1},
        {1, 1, 0, 0, 0}};
signed main()
{
    scanf("%d%d%d", &N, &NA, &NB);
    for (int i = 1; i <= NA; i++)
        scanf("%d", &A[i]);
    for (int i = 1; i <= NB; i++)
        scanf("%d", &B[i]);
    int p1 = 1, p2 = 1;
    for (int i = 1; i <= N; i++,
             p1 = bian(p1, 0),
             p2 = bian(p2, 1))
        ans1 += jud[A[p1]][B[p2]],
            ans2 += jud[B[p2]][A[p1]];
    printf("%d %d\n", ans1, ans2);
    return 0;
}