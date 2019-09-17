#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int mg, s, t;
    scanf("%d%d%d", &mg, &s, &t);
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= t; i++)
    {
        ans1 += 17;
        if (mg >= 10)
            ans2 += 60, mg -= 10;
        else
            mg += 4;
        ans1 < ans2 ? ans1 = ans2 : ans1 = ans1;
        if (ans1 > s)
        {
            printf("Yes\n%d\n", i);
            exit(0);
        }
    }
    printf("No\n%d\n", ans1);
}