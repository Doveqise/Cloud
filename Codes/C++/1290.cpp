#include <bits/stdc++.h>
using namespace std;
int m, n, T;
int solve(int a, int b, int hand)
{
    if (a == b)
        return hand;
    if (b / a >= 2)
        return hand;
    else
        return solve(b - a, a, hand ^ 1);
}
signed main()
{
    while(cin>>m>>n&&m&&n)
    {
        if (m > n)
            swap(m, n);
        if (solve(m, n, 0))
            puts("Ollie wins");
        else
            puts("Stan wins");
    }
    return 0;
}