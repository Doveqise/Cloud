#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e4 + 5;
const int maxm = 3e5 + 5;
string s[maxn];
int ch[maxm][28], num, sta[maxm], n;
int vis[28][28], inq[28], flg, ans[maxn], ansn;
int tot, hd[28], to[maxn], nxt[maxn];
queue<int> q;
void add(int x, int y)
{
    nxt[++tot] = hd[x];
    hd[x] = tot;
    to[tot] = y;
}
void insert(string x)
{
    int u = 0, t;
    for (int i = 0; i < x.size(); i++)
    {
        t = x[i] - 'a';
        if (!ch[u][t])
            ch[u][t] = ++num;
        u = ch[u][t];
    }
    sta[u] = 1;
}
void solve(string x)
{
    int u = 0, t;
    for (int i = 0; i < x.size(); i++)
    {
        t = x[i] - 'a';
        if (sta[u])
        {
            flg = 1;
            return;
        }
        for (int j = 0; j < 26; j++)
            if (ch[u][j] && j != t && !vis[t][j])
            {
                vis[t][j] = 1;
                add(t, j);
                inq[j]++;
            }
        u = ch[u][t];
    }
}
bool judge()
{
    for (int i = 0; i < 26; i++)
        if (!inq[i])
            q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = hd[u]; i; i = nxt[i])
        {
            inq[to[i]]--;
            if (!inq[to[i]])
                q.push(to[i]);
        }
    }
    for (int i = 0; i < 26; i++)
        if (inq[i])
            return 0;
    return 1;
}
signed main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        insert(s[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        tot = flg = 0;
        while(!q.empty())
            q.pop();
        memset(hd, 0, sizeof(hd));
        memset(inq, 0, sizeof(inq));
        memset(vis, 0, sizeof(vis));
        solve(s[i]);
        if (flg)
            continue;
        if (judge())
            ans[++ansn] = i;
    }
    printf("%d\n", ansn);
    for (int i = 1; i <= ansn; i++)
        cout << s[ans[i]] << endl;
    return 0;
}