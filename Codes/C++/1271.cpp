#include <bits/stdc++.h>
using namespace std;
int a[101], f[101][2];
string ld[101];
map<string, int> nm;
vector<int> g[101];
void dfs(int u)
{
    for (vector<int>::iterator it = g[u].begin(); it != g[u].end(); it++)
    {
        int v = *it;
        dfs(v);
        f[u][0] += max(f[v][0], f[v][1]);
        f[u][1] += f[v][0];
    }
    f[u][1] += a[u];
}
int main()
{
    int n;
    string s;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        nm[s] = i;
        scanf("%d", &a[i]);
        cin >> ld[i];
    }
    nm["NOBODY"] = 0;
    for (int i = 1; i <= n; i++)
        g[nm[ld[i]]].push_back(i);
    dfs(0);
    printf("%d\n", max(f[0][0], f[0][1]));
    return 0;
}