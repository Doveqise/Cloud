#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int leng[20], f[maxn];
char par[maxn], wd[20][11];
signed main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", wd[i]), leng[i] = strlen(wd[i]);
    for (int i = 0; i < m; i++)
    {
        memset(f, 0, sizeof(f));
        memset(par, 0, sizeof(par));
        scanf("%s", par);
        int len = strlen(par), ans = 0;
        for (int k = 0; k < n; k++)
        {
            int flg = 0;
            for (int l = 0; l < leng[k]; l++)
                if (par[l] != wd[k][l])
                {
                    flg = 1;
                    break;
                }
            if (!flg)
                f[leng[k]] = 1, ans = max(ans, leng[k]);
        }
        int pt = 1;
        if (ans)
            while (pt <= len)
            {
                if (f[pt])
                {
                    ans = max(ans, pt);
                    for (int k = 0; k < n; k++)
                        if (!f[pt + leng[k]])
                        {
                            int flg = 0;
                            for (int l = 0; l < leng[k]; l++)
                                if (par[pt + l] != wd[k][l])
                                {
                                    flg = 1;
                                    break;
                                }
                            if (!flg)
                                f[pt + leng[k]] = 1;
                        }
                }
                pt++;
            }
        printf("%d\n", ans);
    }
}