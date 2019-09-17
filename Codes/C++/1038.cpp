#include<bits/stdc++.h>
#define R register
int c[110], in[110];
struct e
{
    int next, to, value;
} 
edge[20010];
int hd[110], edge_n = 0, q[110], head = 0, tail = 0;
int read()
{
    R int x = 0;
    R bool f = 0;
    R char ch = getchar();
    for (; ch < '0' || ch > '9'; ch = getchar())
        if (ch == '-')
            f = 1;
    for (; ch >= '0' && ch <= '9'; ch = getchar())
        x = (x << 1) + (x << 3) + (ch ^ 48);
    return f == 1 ? -x : x;
}
void write(R int x)
{
    if (x / 10)
        write(x / 10);
    putchar(x % 10 + 48);
    return;
}
void add_edge(R int x, R int y, R int w)
{
    edge[++edge_n].next = hd[x];
    edge[edge_n].to = y;
    edge[edge_n].value = w;
    hd[x] = edge_n;
    return;
}
void topo()
{
    R int i;
    while (head != tail)
    {
        ++head;
        for (i = hd[q[head]]; i; i = edge[i].next)
        {
            --in[edge[i].to];
            if (!in[edge[i].to])
            {
                q[++tail] = edge[i].to;
            }
            if (c[q[head]] > 0)
            {
                c[edge[i].to] += c[q[head]] * edge[i].value;
            }
        }
    }
}
int main()
{
    R int n, p, i, u, x, y, w;
    R bool flag;
    n = read();
    p = read();
    for (i = 1; i <= n; ++i)
    {
        c[i] = read();
        u = read();
        if (c[i] != 0)
            q[++tail] = i;
        else
            c[i] = -u;
    }
    for (i = 1; i <= p; ++i)
    {
        x = read();
        y = read();
        w = read();
        ++in[y];
        add_edge(x, y, w);
    }
    topo();
    flag = 0;
    for (i = 1; i <= n; ++i)
    {
        if (c[i] > 0 && !hd[i])
        {
            write(i);
            putchar(' ');
            write(c[i]);
            putchar('\n');
            flag = 1;
        }
    }
    if (!flag)
    {
        puts("NULL");
    }
    return 0;
}