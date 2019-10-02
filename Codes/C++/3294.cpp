#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5.1e5 + 5;
int ch[maxn][26], cnt, sta[maxn], tmp[maxn];
int hd[maxn], to[maxn], nxt[maxn], tot;
char str[maxn];
ll n, ans, stp;
bool cmp(int x, int y)
{
    return ch[x][0] < ch[y][0];
}
void add(int x)
{
    nxt[++tot] = hd[x];
    hd[x] = tot;
    to[tot] = tot;
}
void insert()
{
    scanf("%s", str);
    int u = 0, len = strlen(str);
    for (int i = len - 1; i >= 0; i--)
    {
        int c = str[i] - 'a';
        if (!ch[u][c])
            ch[u][c] = ++cnt;
        u = ch[u][c];
    }
    sta[u] = 1;
}
void build(int u, int id)
{
    if (sta[u])
        add(id), id = tot;
    for (int i = 0; i < 26; i++)
        if (ch[u][i])
            build(ch[u][i], id);
}
void query(int u)
{
    ch[u][0] = 1;
    for (int i = hd[u]; i; i = nxt[i])
    {
        int v = to[i];
        query(v);
        ch[u][0] += ch[v][0];
    }
}
void dfs(int u, int res)
{
    ans += (++stp) - res;
    res = stp;
    int lst = tmp[0];
    for (int i = hd[u]; i; i = nxt[i])
        tmp[++tmp[0]] = to[i];
    int rpc = tmp[0];
    stable_sort(tmp + lst + 1, tmp + rpc + 1, cmp);
    for (int i = lst + 1; i <= rpc; i++)
        dfs(tmp[i], res);
    tmp[0] = lst;
}
signed main()
{
    scanf("%lld", &n);
    while (n--)
        insert();
    build(0, 0);
    query(0);
    dfs(0, 1);
    printf("%lld\n", ans);
    return 0;
}