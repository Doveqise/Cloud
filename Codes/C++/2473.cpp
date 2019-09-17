// luogu-judger-enable-o2
#include <bits/stdc++.h>
#define re register int
#define maxn1 20
using namespace std;
int w[maxn1], need[maxn1];
double f[105][1 << 15];
inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch))
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (isdigit(ch))
	{
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int main()
{
	int k, n, ne;
	k = read();
	n = read();
	for (re i = 1; i <= n; i++)
	{
		w[i] = read();
		ne = 1;
		while (ne = read()&&ne)
			need[i] |= (1 << (ne - 1));
	}
	int maxn = (1 << n) - 1;
	for (; k >= 1; k--)
		for (re ss = 0; ss <= maxn; ss++)
		{
			for (re i = 1; i <= n; i++)
			{
				if ((ss & need[i]) == need[i])
				{
					if (f[k + 1][ss] > f[k + 1][ss | 1 << (i - 1)] + w[i])
						f[k][ss] += f[k + 1][ss];
					else
						f[k][ss] += f[k + 1][ss | 1 << (i - 1)] + w[i];
				}
				else
					f[k][ss] += f[k + 1][ss];
			}
			f[k][ss] /= n;
		}
	printf("%.6lf", f[1][0]);
	return 0;
}