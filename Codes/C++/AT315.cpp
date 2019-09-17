#include <bits/stdc++.h>
using namespace std;
long long wei[14];
bool cmp(string a, string b)
{
    if (a.size() > b.size())
        return 1;
    if (a.size() < b.size())
        return 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (wei[a[i] - '0'] < wei[b[i] - '0'])
            return 0;
        if (wei[a[i] - '0'] > wei[b[i] - '0'])
            return 1;
    }
    return 0;
}
long long n, b;
string c[800];
signed main()
{
    for (int i = 0, t; i < 10; i++)
    {
        cin >> t;
        wei[t] = i;
    }
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
        for (int v = i + 1; v < n; v++)
            if (cmp(c[i], c[v]))
                swap(c[i], c[v]);
    for (int i = 0; i < n; i++)
        cout << c[i] << endl;
    return 0;
}