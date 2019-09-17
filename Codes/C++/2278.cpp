#include <bits/stdc++.h>
using namespace std;
struct node
{
    int id, ti, pri;
} tmp;
int n, t, a, b, c, d;
priority_queue<node> q;
bool operator<(node a, node b)
{
    if (a.pri != b.pri)
        return a.pri < b.pri;
    return a.id >= b.id;
}
int main()
{
    while (scanf("%d%d%d%d", &a, &b, &c, &d) == 4)
    {
        while (!q.empty())
        {
            tmp = q.top();
            q.pop();
            if ((t + tmp.ti) <= b)
            {
                t += tmp.ti;
                printf("%d %d\n", tmp.id, t);
            }
            else
            {
                tmp.ti -= (b - t);
                q.push(tmp);
                break;
            }
        }
        tmp.pri = d;
        tmp.id = a;
        tmp.ti = c;
        q.push(tmp);
        t = b;
    }
    while (!q.empty())
    {
        tmp = q.top();
        q.pop();
        t += tmp.ti;
        printf("%d %d\n", tmp.id, t);
    }
    return 0;
}