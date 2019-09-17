#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e2 + 5;
int n, m, v, p, q;
int w[maxn], c[maxn], w1[maxn][3], c2[maxn][3], f[maxn];
signed main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &v, &p, &q);
		if (!q)
		{
			w[i] = v;
			c[i] = v * p;
		}
		else
		{
			w1[q][0]++;
			w1[q][w1[q][0]] = v;
			c2[q][w1[q][0]] = v * p;
		}
	}
	for (int i = 1; i <= m; i++)
		for (int j = n; w[i] != 0 && j >= w[i]; j--)
		{
			f[j] = max(f[j], f[j - w[i]] + c[i]);
			if (j >= w[i] + w1[i][1])
				f[j] = max(f[j], f[j - w[i] - w1[i][1]] + c[i] + c2[i][1]);
			if (j >= w[i] + w1[i][2])
				f[j] = max(f[j], f[j - w[i] - w1[i][2]] + c[i] + c2[i][2]);
			if (j >= w[i] + w1[i][1] + w1[i][2])
				f[j] = max(f[j], f[j - w[i] - w1[i][1] - w1[i][2]] + c[i] + c2[i][1] + c2[i][2]);
		}
	printf("%d\n", f[n]);
	return 0;
}