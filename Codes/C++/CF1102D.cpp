#include <bits/stdc++.h>
const int maxn = 3e5 + 5;
char str[maxn];
int cnt[128];
signed main()
{
    int n;
    scanf("%d", &n);
    if(n%3)
        return puts("Impossible"), 0;
    int lim = n / 3;
    scanf("%s", str + 1);
    for (int i = 1; i <= n; i++)
        ++cnt[(int)str[i]];
    for (int i = 1; i <= n; i++)
    {
        if (cnt['2'] <= lim)
            break;
        if (str[i] == '2')
        {
            if (cnt['0'] < lim)
                ++cnt[(int)(str[i] = '0')], --cnt['2'];
            else if (cnt['1'] < lim)
                ++cnt[(int)(str[i] = '1')], --cnt['2'];
        }
    }
    for (int i = n; i; i--)
    {
        if (cnt['0'] <= lim)
            break;
        if (str[i] == '0')
        {
            if (cnt['2'] < lim)
                ++cnt[(int)(str[i] = '2')], --cnt['0'];
            else if (cnt['1'] < lim)
                ++cnt[(int)(str[i] = '1')], --cnt['0'];
        }
    }
    int l = 1, r = n;
    while (r)
    {
        if (cnt['1'] <= lim)
            break;
        if (str[l] == '1' && cnt['0'] < lim)
            ++cnt[(int)(str[l] = '0')], --cnt['1'];
        if (str[r] == '1' && cnt['2'] < lim)
            ++cnt[(int)(str[r] = '2')], --cnt['1'];
        l++;
        r--;
    }
    printf("%s", str + 1);
    return 0;
}