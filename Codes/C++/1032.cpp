#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
map<string, bool> ed;
map<string, int> st;
string a, b;
string chg[30][3];
int t = 1, k = 2;
int ans = inf;
void dfs(string now, int dep)
{
    if (dep > k)
        return;
    if (now == b)
    {
        ans = min(ans, dep);
        return;
    }
    if (ed[now])
        if (dep >= st[now])
            return;
    ed[now] = 1;
    st[now] = dep;
    int loc = 0;
    string nowc;
    for (int i = 1; i <= t; i++)
    {
        loc = -1;
        while (1)
        {
            loc = now.find(chg[i][0], loc + 1);
            if (loc == -1)
                break;
            nowc = now;
            nowc.erase(loc, chg[i][0].size());
            nowc.insert(loc, chg[i][1]);
            dfs(nowc, dep + 1);
        }
    }
    return;
}
signed main()
{
    cin >> a >> b;
    while (cin >> chg[t][0] >> chg[t][1])
        t++;
    t--;
    while (ans == inf)
    {
        dfs(a, 0);
        ed.clear();
        st.clear();
        k++;
        if (k == 11)
            break;
    }

    if (ans == inf)
        puts("NO ANSWER!");
    else
        printf("%d\n", ans);
    return 0;
}