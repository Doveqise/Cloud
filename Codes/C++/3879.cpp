#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, m, num, cnt[maxn];
string s;
map<string, vector<int> > a;
signed main()
{
    scanf("%d", &n);
    for (int i = 1, opt; i <= n; i++)
    {
        scanf("%d", &opt);
        for (int j = 1; j <= opt; j++)
        {
            cin >> s;
            a[s].push_back(i);
        }
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++, puts(""))
    {
        cin >> s;
        memset(cnt, 0, sizeof(cnt));
        for (int j = 0; j < a[s].size(); j++)
            if (!cnt[a[s][j]])
            {
                printf("%d ", a[s][j]);
                cnt[a[s][j]]++;
            }
    }
    return 0;
}