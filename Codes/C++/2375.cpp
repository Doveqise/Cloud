#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
typedef long long ll;
int nxt[maxn], ans[maxn];
char str[maxn];
signed main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll ot = 1;
        scanf("%s", str);
        int n = strlen(str);
        ans[0] = 0, ans[1] = 1;
        for (int i = 1, j = 0; i < n; i++)
        {
            while (j && str[i] != str[j])
                j = nxt[j];
            j += str[i] == str[j];
            nxt[i + 1] = j;
            ans[i + 1] = ans[j] + 1;
        }
        for (int i = 1, j = 0; i < n; i++)
        {
            while (j && str[i] != str[j])
                j = nxt[j];
            j += str[i] == str[j];
            while (j * 2 > i + 1)
                j = nxt[j];
            ot = ot * (ll)(ans[j] + 1) % mod;
        }
        printf("%lld\n", ot);
    }
}