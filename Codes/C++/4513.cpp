#include <bits/stdc++.h>
using namespace std;
const int N = 500007;
int n, m, a[N];
int max(int a, int b, int c) 
{
    return max(a, max(b, c));
}
struct SegmentTree 
{
    int all, left, right, sum;
    SegmentTree operator + (const SegmentTree &b)
    {
        return (SegmentTree)//骚气的return居蓝还可以这么用
        {
            max(all, b.all, right + b.left),
            max(left, b.left + sum),
            max(b.right, right + b.sum),
            sum + b.sum
        };
    }
} val[N << 2];

void build(int rt, int l, int r)
{
    if (l == r)
    {
        val[rt] = (SegmentTree){a[l], a[l], a[l], a[l]};
        return;
    }
    int m = (l + r) >> 1;
    build(rt << 1, l, m);
    build(rt << 1 | 1, m+1, r);
    val[rt] = val[rt << 1] + val[rt << 1 | 1];
}

SegmentTree query(int rt, int l, int r, int p, int q)
{
    if (p <= l && r <= q) return val[rt];
    int m = (l + r) >> 1;
    if (q <= m) return query(rt << 1, l, m, p, q);
    else if (p > m) return query(rt << 1 | 1, m+1, r, p, q);
    else return query(rt << 1, l, m, p, m) + query(rt << 1 | 1, m+1, r, m+1, q);
}

void change(int rt, int l, int r, int p, int q){
    if (l == r) 
    {
        val[rt] = (SegmentTree){q, q, q, q};
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m) change(rt << 1, l, m, p, q);
    else change(rt << 1 | 1, m+1, r, p, q);
    val[rt] = val[rt << 1] + val[rt << 1 | 1];
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    build(1, 1, n);
    for (int i = 1; i <= m; ++i)
    {
        int k, x, y; 
        scanf("%d%d%d", &k, &x, &y);
        if (k == 1) 
        {
            if (x > y) swap(x, y);
            printf("%d\n", query(1, 1, n, x, y).all);
        } 
        else 
        {
            change(1, 1, n, x, y);
        }
    }
    return 0;
}