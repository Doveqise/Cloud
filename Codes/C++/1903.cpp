#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e6 + 10;
int n, m;
int a[maxn], pos[maxn];
struct query
{
	int x, y, pre, id;
} q[maxn];
int qnum = 0;
struct change
{
	int po, val;
} ch[maxn];
int cnum = 0;
int color[maxn], ans = 0, base, out[maxn];
int cmp(query a, query b)
{
	if (a.x != b.x)
		return pos[a.x] < pos[b.x];
	if (a.y != b.y)
		return pos[a.y] < pos[b.y];
	return a.pre < b.pre;
}
void add(int val)
{
	if (++color[val] == 1)
		ans++;
}
void del(int val)
{
	if (--color[val] == 0)
		ans--;
}
void work(int now, int num)
{
	if (ch[now].po >= q[num].x && ch[now].po <= q[num].y)
	{
		if (--color[a[ch[now].po]] == 0)
			ans--;
		if (++color[ch[now].val] == 1)
			ans++;
	}
	swap(ch[now].val, a[ch[now].po]);
}
void MoDui()
{
	int l = 1, r = 0, now = 0;
	for (int i = 1; i <= qnum; i++)
	{
		while (l < q[i].x)
			del(a[l++]);
		while (l > q[i].x)
			add(a[--l]);
		while (r < q[i].y)
			add(a[++r]);
		while (r > q[i].y)
			del(a[r--]);
		while (now < q[i].pre)
			work(++now, i);
		while (now > q[i].pre)
			work(now--, i);
		out[q[i].id] = ans;
	}
	for (int i = 1; i <= qnum; i++)
	{
		printf("%d\n", out[i]);
	}
}
signed main()
{
	scanf("%d%d", &n, &m);
	base = (int)sqrt(n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		pos[i] = (i - 1) / base + 1;
	}
	while (m--)
	{
		char op[5];
		scanf("%s", op);
		if (op[0] == 'Q')
		{
			qnum++;
			scanf("%d%d", &q[qnum].x, &q[qnum].y);
			q[qnum].pre = cnum;
			q[qnum].id = qnum;
		}
		else
		{
			cnum++;
			scanf("%d%d", &ch[cnum].po, &ch[cnum].val);
		}
	}
	sort(q + 1, q + qnum + 1, cmp);
	MoDui();
	return 0;
}