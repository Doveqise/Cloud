#include <bits/stdc++.h>
using namespace std;
int n, nt, nd;
vector<int> t, d;
double nowt, nowd;
int speed = 1;
bool comp()
{
    return (nowt + (d[nd] - nowd) * speed) > t[nt];
}
int main()
{
    cin >> n;
    char c;
    int tp;
    for (int i = 1; i <= n; i++)
    {
        cin >> c >> tp;
        if (c == 'D' && tp > 1000)
            continue;
        if (c == 'D')
            d.push_back(tp);
        else
            t.push_back(tp);
    }
    d.push_back(1000);
    sort(d.begin(), d.end());
    sort(t.begin(), t.end());
    while (nt != t.size() || nd != d.size())
    {
        bool nxttime = nd == d.size();
        if (!nxttime && nt != t.size())
            nxttime = comp();
        if (nxttime)
        {
            nowd += (t[nt] - nowt) / (double)speed;
            nowt = t[nt++];
        }
        else
        {
            nowt += (d[nd] - nowd) * speed;
            nowd = d[nd++];
        }
        ++speed;
    }
    printf("%.0lf", nowt);
}