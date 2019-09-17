#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int ans[maxn], tot;
char a[maxn], b[maxn];
signed main()
{
    ans[0] = -1;
    scanf("%s\n%s", a, b);
    int lena = strlen(a), lenb = strlen(b);
    for (int i = 0; i < lenb; i++)
    {
        int ed = ans[tot] + 1;
        for (int t = tot; t >= 1; t--)
            for (int j = ans[t - 1] + 1; j < ans[t]; j++)
                if (a[j] == b[i])
                {
                    ans[t] = j;
                    break;
                }
        for (int j = ed; j < lena; j++)
            if (a[j] == b[i])
            {
                ans[++tot] = j;
                break;
            }
    }
    printf("%d\n", tot);
    return 0;
}