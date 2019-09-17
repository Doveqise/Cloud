#include <bits/stdc++.h>
using namespace std;
int n, sz[20], ss;
char symbol[20];
void sech(int k, int s, int q, char c)
{
    if (k == n)
    {
        if (c == '+')
        {
            s = s + q;
        }
        else
        {
            s = s - q;
        }
        if (s == 0)
        {
            ss++;
            cout << "1";
            for (int i = 1; i < n; i++)
            {
                cout << symbol[i] << sz[i];
            }
            cout << " " << ss << endl;
        }
    }
    else
    {
        symbol[k] = ' ';
        sech(k + 1, s, q * 10 + sz[k], c);
        symbol[k] = '+';
        if (c == '+')
        {
            sech(k + 1, s + q, sz[k], '+');
        }
        else
        {
            sech(k + 1, s - q, sz[k], '+');
        }
        symbol[k] = '-';
        if (c == '+')
        {
            sech(k + 1, s + q, sz[k], '-');
        }
        else
        {
            sech(k + 1, s - q, sz[k], '-');
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        sz[i] = i + 1;
    }
    sech(1, 0, 1, '+');
    return 0;
}