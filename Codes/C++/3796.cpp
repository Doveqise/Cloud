#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int maxm = 131 * 71;
char s[131][71], T[maxn];
int m;
struct ACAuto
{
    int Node, f[maxm], ch[maxm][26], cnt[maxm], val[maxm], nxt[maxm];
    void clear()
    {
        Node = 0;
        memset(f, 0, sizeof(f));
        memset(ch, 0, sizeof(ch));
        memset(val, 0, sizeof(val));
        memset(cnt, 0, sizeof(cnt));
        memset(nxt, 0, sizeof(nxt));
    }
    void insert(char *s, int x)
    {
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; i++)
        {
            int c = s[i] - 'a';
            if (!ch[u][c])
                ch[u][c] = ++Node;
            u = ch[u][c];
        }
        val[u] = x;
    }
    void Fail()
    {
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int u = q.front(), k = f[u];
            q.pop();
            for (int c = 0; c < 26; c++)
            {
                int v = ch[u][c];
                if (!v)
                {
                    ch[u][c] = ch[k][c];
                    continue;
                }
                f[v] = u ? ch[k][c] : 0;
                nxt[v] = val[f[v]] ? f[v] : nxt[f[v]];
                q.push(v);
            }
        }
    }
    void query(char *T)
    {
        int u = 0, n = strlen(T), res = 0;
        for (int i = 0; i < n; i++)
        {
            int c = T[i] - 'a';
            u = ch[u][c];
            if (val[u])
                cnt[val[u]]++;
            int v = nxt[u];
            while (v)
            {
                if (val[v])
                    cnt[val[v]]++;
                v = nxt[v];
            }
        }
        for (int i = 1; i <= m; i++)
            res = max(res, cnt[i]);
        printf("%d\n", res);
        for (int i = 1; i <= m; i++)
            if (cnt[i] == res)
                printf("%s\n", s[i]);
        return;
    }
} AC;
signed main()
{
    while (scanf("%d", &m) && m)
    {
        AC.clear();
        for (int i = 1; i <= m; i++)
        {
            scanf("%s", s[i]);
            AC.insert(s[i], i);
        }
        AC.Fail();
        scanf("%s", &T);
        AC.query(T);
    }
    return 0;
}