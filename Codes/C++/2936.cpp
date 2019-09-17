#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int maxn = 2 << 10;
queue<int> q;
int n, w[maxn][maxn], d[maxn];
inline bool bfs()
{
    memset(d, 0, sizeof(d));
    d['A'] = 1;
    q.push('A');
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = 'A'; i <= 'z'; i++)
            if (w[now][i] > 0 && d[i] == 0)
            {
                d[i] = d[now] + 1;
                q.push(i);
            }
    }
    return d['Z'] != 0;
}
int dfs(int now, int dist)
{
    if (now == 'Z')
        return dist;
    for (int i = 'A'; i <= 'z'; i++)
        if (d[i] == d[now] + 1 && w[now][i] > 0)
        {
            int x = dfs(i, min(dist, w[now][i]));
            if (x > 0)
            {
                w[now][i] -= x;
                w[i][now] += x;
                return x;
            }
        }
    return 0;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char x, y;
        int z;
        cin >> x >> y >> z;
        w[x][y] += z;
    }
    int ans = 0;
    while (bfs())
    {
        while (int di = dfs('A', INF))
            ans += di;
    }
    cout << ans;
    return 0;
}