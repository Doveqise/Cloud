#include <bits/stdc++.h>
using namespace std;
int tms[30], a[30];
char str[100005];
bool cmp(int a, int b)
{
    return a > b;
}
signed main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", str);
        tms[str[0] - 'A' + 1]++;
    }
    int ans = 0;
    while (1)
    {
        int ts = 0;
        sort(tms + 1, tms + 27, cmp);
        for (int i = 1; i <= 26; i++)
        {
            if (tms[i])
            {
                tms[i]--;
                ts++;
                if (ts == k)
                    break;
            }
        }
        if (ts == k)
            ans++;
        else
            break;
    }
    printf("%d\n", ans);
    return 0;
}