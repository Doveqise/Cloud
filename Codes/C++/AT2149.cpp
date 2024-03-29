#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int a[N], b[N], q[N], n, w, h, Y, ans;
struct node
{
	int x, y;
} p[N];
bool cmp(node a, node b)
{
	return a.x < b.x;
}
void solve(int l, int r)
{
	if (l == r)
		return;
	int mid = (l + r) >> 1;
	for (int i = mid, y1 = 0, y2 = h; i >= l; i--)
	{
		a[i] = y1;
		b[i] = y2;
		if (p[i].y >= Y)
			y2 = min(y2, p[i].y);
		if (p[i].y <= Y)
			y1 = max(y1, p[i].y);
	}
	for (int i = mid + 1, y1 = 0, y2 = h; i <= r; i++)
	{
		a[i] = y1;
		b[i] = y2;
		if (p[i].y >= Y)
			y2 = min(y2, p[i].y);
		if (p[i].y <= Y)
			y1 = max(y1, p[i].y);
	}
	for (int i = mid, j = mid + 1, h = 1, t = 0; i >= l; i--)
	{
		for (; j <= r && a[j] <= a[i]; j++)
		{
			for (; h <= t && b[q[t]] + p[q[t]].x <= b[j] + p[j].x; t--);
			q[++t] = j;
		}
		for(; h < t && b[i] + p[q[h]].x <= b[q[h + 1]] + p[q[h + 1]].x; h++);
		ans = max(ans, (p[q[h]].x - p[i].x + min(b[i], b[q[h]]) - a[i]) * 2);
	}
	for (int i = mid + 1, j = mid, h = 1, t = 0; i <= r; i++)
	{
		for (; j >= l && a[j] <= a[i]; j--)
		{
			for (; h <= t && b[q[t]] - p[q[t]].x <= b[j] - p[j].x; t--);
			q[++t] = j;
		}
		for (; h < t && b[i] - p[q[h]].x <= b[q[h + 1]] - p[q[h + 1]].x; h++);
		ans = max(ans, (p[i].x - p[q[h]].x + min(b[i], b[q[h]]) - a[i]) * 2);
	}
	solve(l, mid);
	solve(mid + 1, r);
}
void work()
{
	sort(p + 1, p + n + 1, cmp);
	Y = h / 2;
	p[0].x = 0;
	p[n + 1].x = w;
	p[0].y = p[n + 1].y = Y;
	solve(0, n + 1);
}
int main()
{
	scanf("%d%d%d", &w, &h, &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &p[i].x, &p[i].y);
	ans = max(h, w) * 2 + 2;
	work();
	swap(w, h);
	for (int i = 1; i <= n; i++)
		swap(p[i].x, p[i].y);
	work();
	printf("%d\n", ans);
}
