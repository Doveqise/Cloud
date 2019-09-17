#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, m, num;
bool Beg, End;
char s[maxn], t[maxn];
struct ACauto
{
    vector<int> ed[maxn];
    queue<int> q;
    int tot, root, cnt[maxn], seq[maxn], fail[maxn], tree[maxn][26];
    int newnode()
    {
        tot++;
        fail[tot] = 0;
        ed[tot].clear();
        for (int i = 0; i < 26; i++)
            tree[tot][i] = -1;
        return tot;
    }
    void insert(int l, int r, int id)
    {
        int p = root;
        for (int i = l; i <= r; i++)
        {
            int ch = t[i] - 'a';
            if (tree[p][ch] == -1)
                tree[p][ch] = newnode();
            p = tree[p][ch];
        }
        ed[p].push_back(id);
    }
    void Fail()
    {
        for (int i = 0; i < 26; i++)
            if (tree[root][i] != -1)
            {
                fail[tree[root][i]] = root;
                q.push(tree[root][i]);
            }
            else
                tree[root][i] = root;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int i = 0; i < (int)ed[fail[x]].size(); i++)
                ed[x].push_back(ed[fail[x]][i]);
            for (int i = 0; i < 26; i++)
            {
                if (tree[x][i] != -1)
                {
                    fail[tree[x][i]] = tree[fail[x]][i];
                    q.push(tree[x][i]);
                }
                else
                    tree[x][i] = tree[fail[x]][i];
            }
        }
    }
    bool find(int l, int r, bool fir, bool las)
    {
        tot = 0;
        root = newnode();
        memset(cnt, 0, sizeof(cnt));
        int bel = 0;
        for (int i = l, p = i; i <= r; i++, p = i)
            if (t[i] != '?')
            {
                while (p <= r && t[p] != '?')
                    p++;
                p--;
                insert(i, p, p - l + 1);
                i = p;
                bel++;
            }
        Fail();
        int p = root;
        for (int i = 1; i <= n; i++)
        {
            int ch = s[i] - 'a';
            p = tree[p][ch];
            for (int j = 0; j < (int)ed[p].size(); j++)
                if (i - ed[p][j] + 1 > 0)
                    cnt[i - ed[p][j] + 1]++;
        }
        for (int i = 1; i <= n; i++)
            if (cnt[i] == bel)
            {
                if (!num)
                {
                    if (!Beg && fir && i != 1)
                        continue;
                    if (!End && las && i + r - l != n)
                        continue;
                    seq[++num] = i + r - l;
                    return 1;
                }
                else
                {
                    if (i <= seq[num])
                        continue;
                    if (!End && las && i + r - l != n)
                        continue;
                    seq[++num] = i + r - l;
                    return 1;
                }
            }
        return 0;
    }
} 
AC;
signed main()
{
    scanf("%s", t + 1);
    scanf("%d",&T);
    m = strlen(t + 1);
    while (T--)
    {
        scanf("%s", s + 1);
        n = strlen(s + 1);
        num = 0;
        Beg = t[1] == '*';
        End = t[m] == '*';
        int len = m;
        while (len && t[len] == '*')
            len--;
        if (!len)
        {
            puts("YES");
            continue;
        }
        int bel = 0;
        bool flg = 0;
        for (int i = 1; i <= m; i++)
            if (t[i] != '*')
            {
                int p = i;
                while (p <= m && t[p] != '*')
                    p++;
                p--;
                if (!AC.find(i, p, bel == 0, p == len))
                {
                    flg = 1;
                    break;
                }
                i = p;
                bel++;
            }
        puts(flg ? "NO" : "YES");
    }
    return 0;
}