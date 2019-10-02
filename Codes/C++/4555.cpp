#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e7 + 5;
char s[maxn], str[maxn];
int p[maxn], lans[maxn], rans[maxn];
int n, ans = 0;
void init()
{
    str[0] = '@', str[1] = '#';
    int cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        str[++cnt] = s[i];
        str[++cnt] = '#';
    }
    str[++cnt] = '\0';
    n = (n + 1) << 1;
}

void solve()
{
    int mx = 0, id;
    for (int i = 1; i <= n; i++)
    {
        if (i < mx)
            p[i] = min(p[(id << 1) - i], mx - i);
        else
            p[i] = 1;
        while (str[i + p[i]] == str[i - p[i]])
            ++p[i];
        if (p[i] + i > mx)
            mx = p[i] + i, id = i;
        rans[i + p[i] - 1] = max(rans[i + p[i] - 1], p[i] - 1);
        lans[i - p[i] + 1] = max(lans[i - p[i] + 1], p[i] - 1);
    }
}

signed main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    init();
    solve();
    for (int i = n; i >= 1; i -= 2)
        rans[i] = max(rans[i], rans[i + 2] - 2);
    for (int i = 1; i <= n; i += 2)
        lans[i] = max(lans[i], lans[i - 2] - 2);
    for (int i = 1; i <= n; i += 2)
        if (rans[i] && lans[i])
            ans = max(ans, lans[i] + rans[i]);
    printf("%d\n", ans);
    return 0;
}