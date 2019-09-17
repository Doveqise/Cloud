#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e4 + 5;
struct node
{
	int a, b;
	bool operator<(const node y) const
	{
		return min(a, y.b) == min(b, y.a) ? a < y.a : min(a, y.b) < min(b, y.a);
	}
} a[maxn];
int b[maxn], c[maxn];
signed main()
{
	int T;
	scanf("%lld", &T);
	while (T--)
	{
		memset(c, 0, sizeof(c));
		memset(b, 0, sizeof(b));
		memset(a, 0, sizeof(a));
		int n;
		scanf("%lld", &n);
		for (int i = 1; i <= n; i++)
			scanf("%lld%lld", &a[i].a, &a[i].b);
		sort(a + 1, a + 1 + n);
		int tot = 0;
		for (int i = 1; i <= n; i++)
		{
			tot += a[i].a;
			c[i] = max(c[i - 1], tot) + a[i].b;
		}
		printf("%lld\n", c[n]);
	}
}
