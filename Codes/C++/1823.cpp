#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
typedef long long ll;
typedef pair<ll, ll> pii;
stack<pii> s;
ll ans = 0;
signed main()
{
    ll n, hei = 0;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &hei);
        pii t(hei, 1);
        while (!s.empty() && hei >= s.top().first)
        {
            ans += s.top().second;
            if (t.first == s.top().first)
                t.second += s.top().second;
            s.pop();
        }
        if (!s.empty())
            ans++;
        s.push(t);
    }
    printf("%lld\n", ans);
    return 0;
}