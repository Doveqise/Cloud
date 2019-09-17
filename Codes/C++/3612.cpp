#include <bits/stdc++.h>
using namespace std;
string s;
long long n, t = 1, l;
signed main()
{
    cin >> s >> n;
    t = l = s.length();
    if (s == "ABC")
        return puts("A"), 0;
    while (t <= n)
        t <<= 1;
    n--;
    while ((t >>= 1) && (t >= l))
        if (n >= t)
        {
            if ((n -= t) && (!n))
                n = t - 1;
            else
                n--;
        }
    return printf("%c", s[n % l]), 0;
}