#include <bits/stdc++.h>
const int maxn = 5e5 + 5;
const int maxm = 1e3 + 5;
int tree[maxn][4], flag[maxn];
int n, m, cnt, L, ans;
char S[maxm], T[maxm];
std::bitset<maxm> f[maxn];
inline int ch(char p)
{
    if (p == 'A')
        return 0;
    if (p == 'G')
        return 1;
    if (p == 'T')
        return 2;
    if (p == 'C')
        return 3;
}
inline void ins()
{
    int len = strlen(S + 1);
    int now = 0;
    for (int i = 1; i <= len; i++)
    {
        if (!tree[now][ch(S[i])])
            tree[now][ch(S[i])] = ++cnt;
        now = tree[now][ch(S[i])];
    }
    flag[now]++;
}
void dfs(int now, int t)
{
    if (t == L + 1)
    {
        ans += flag[now];
        flag[now] = 0;
        return;
    }
    if (f[now][t])
        return;
    f[now][t] = 1;
    if (T[t] >= 'A' && T[t] <= 'Z')
    {
        if (!tree[now][ch(T[t])])
            return;
        dfs(tree[now][ch(T[t])], t + 1);
    }
    else
    {
        if (T[t] == '?')
        {
            for (int i = 0; i < 4; i++)
                if (tree[now][i])
                    dfs(tree[now][i], t + 1);
        }
        if (T[t] == '*')
        {
            dfs(now, t + 1);
            for (int i = 0; i < 4; i++)
                if (tree[now][i])
                    dfs(tree[now][i], t + 1), dfs(tree[now][i], t);
        }
    }
}
signed main()
{
    scanf("%s", T + 1);
    L = strlen(T + 1);
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%s", S + 1), ins();
    dfs(0, 1);
    printf("%d\n", n - ans);
    return 0;
}