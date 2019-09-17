#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e4 + 5;
char str[maxn];
bool f[maxn], vis[maxn];
struct ACauto
{
    int cnt, ed[maxn], nxt[maxn], ch[maxn][2];
    void insert(char *s)
    {
        int u = 0, len = strlen(s);
        for (int i = 0; i < len; i++)
        {
            int c = s[i] - '0';
            if (!ch[u][c])
                ch[u][c] = ++cnt;
            u = ch[u][c];
        }
        ed[u]++;
    }
    void Fail()
    {
        queue<int> q;
        memset(nxt, 0, sizeof(nxt));
        for (int i = 0; i < 2; i++)
            if (ch[0][i])
                q.push(ch[0][i]);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (ed[nxt[u]])
                ed[u] = 1;
            for (int i = 0; i < 2; i++)
            {
                if (ch[u][i])
                {
                    nxt[ch[u][i]] = ch[nxt[u]][i];
                    q.push(ch[u][i]);
                }
                else
                    ch[u][i] = ch[nxt[u]][i];
            }
        }
    }
    bool query(int x)
    {
        f[x] = 1;
        for (int i = 0; i < 2; i++)
        {
            if (f[ch[x][i]])
                return 1;
            if (vis[ch[x][i]] || ed[ch[x][i]])
                continue;
            vis[ch[x][i]] = 1;
            if (query(ch[x][i]))
                return 1;
        }
        f[x] = 0;
        return 0;
    }
} AC;
signed main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", str);
        AC.insert(str);
    }
    AC.Fail();
    puts(AC.query(0) ? "TAK" : "NIE");
    return 0;
}