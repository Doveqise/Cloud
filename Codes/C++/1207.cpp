#include <bits/stdc++.h>
using namespace std;
int n, s, ans;
bool judge(int n, int k)
{
    short res[100], p = 0;
    while (n)
        res[p++] = n % k, n /= k;
    int i = 0, j = p - 1;
    while (i < j)
        if (res[i++] != res[j--])
            return 0;
    return 1;
}
int main()
{
    scanf("%d%d", &n, &s);
    for (int i = s + 1; ans != n; i++)
    {
        int cnt = 0;
        for (int j = 2; j <= 10 && cnt < 2; j++)
            if (judge(i, j))
                cnt++;
        if (cnt >= 2)
            printf("%d\n", i), ans++;
    }
    return 0;
}