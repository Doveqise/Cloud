#include <bits/stdc++.h>
using namespace std;
long long s, t, n;
int main()
{
    while (cin>>s>>t>>n)
        printf("%lld %lld\n", s < n ? 3 * s + n - s - 1 + !t : 3 * max(n - 1, min(n, s - t)) + (s - t == n - 1), s > t ? 3 + max(0ll, n - t - 1) : min(3 + max(0ll, n - t - 1), max(n - t + s, 0ll)));
    return 0;
}