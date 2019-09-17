#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int n, r, q;
struct node
{
    int id, num, pow;
    bool operator<(const node b) const
    {
        return num == b.num ? id < b.id : num > b.num;
    }
} nd[maxn << 1];
signed main()
{
    scanf("%d%d%d", &n, &r, &q);
    n <<= 1;
    for (int i = 1; i <= n; i++)
        scanf("%d", &nd[nd[i].id = i].num);
    for (int i = 1; i <= n; i++)
        scanf("%d", &nd[i].pow);
    for (int i = 1; i <= r; i++)
    {
        sort(nd + 1, nd + 1 + n);
        // for (int ti = 1; ti <= n; ti++)
        //     printf("RK %d ND %d : POW = %d NUM = %d\n", ti, nd[ti].id, nd[ti].pow, nd[ti].num);
        for (int j = 1; j <= n; j += 2)
            if (nd[j].pow > nd[j + 1].pow)
                nd[j].num++;
            else
                nd[j + 1].num++;
    }
    sort(nd + 1, nd + 1 + n);
    // for (int i = 1; i <= n; i++)
    //     printf("RK %d ND %d : POW = %d NUM = %d\n", i, nd[i].id, nd[i].pow, nd[i].num);
    printf("%d", nd[q].id);
}