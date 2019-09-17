#include <bits/stdc++.h>
using namespace std;
char str[3005];
signed main()
{
    int n;
    scanf("%d %s", &n, str);
    int cnt = 0, flag = -1, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'L')
        {
            if (flag == 1 && cnt % 2)
                ans++;
            cnt = 0;
            flag = 0;
        }
        else if (str[i] == 'R')
        {
            if (flag == -1)
                ans += cnt;
            else if (!flag)
                ans += cnt;
            cnt = 0;
            flag = 1;
        }
        else
            cnt++;
    }
    cnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (str[i] == 'L')
        {
            ans += cnt;
            cnt = 0;
            break;
        }
        else if (str[i] == 'R')
        {
            cnt = 0;
            break;
        }
        else
            cnt++;
    }
    ans += cnt;
    printf("%d\n", ans);
    return 0;
}