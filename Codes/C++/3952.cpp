#include <bits/stdc++.h>
using namespace std;
int t, n, diff, fornum, blo, ans, err, fz[10], pt;
bool tong[200], isnum, cat[100];
char stk[100];
string s;
signed main()
{
	cin >> t;
	getline(cin, s);
	while (t--)
	{
		for (int i = 0; i < 200; i++)
			tong[i] = 0;
		pt = ans = isnum = n = diff = fornum = blo = err = 0;
		memset(fz, 0, sizeof(fz));

		getline(cin, s);
		int p = 0;
		while (isdigit(s[p]))
			n = n * 10 + s[p++] - '0';
		p += 3;
		if (s[p] == 'n')
			p += 2, isnum = 1;
		while (isdigit(s[p]))
			diff = diff * 10 + s[p++] - '0';
		while (n--)
		{
			getline(cin, s);
			if (s[0] == 'F')
			{
				fornum++;
				if (tong[s[2]])
					err = 1;
				else
					tong[s[2]] = 1;
				stk[++pt] = s[2];
				fz[7] = fz[8] = 0;
				if (s[4] == 'n')
				{
					if (s[6] == 'n')
						;
					else if (!blo)
						blo = fornum;
				}
				else
				{
					int k = 4;
					while (isdigit(s[k]))
						fz[7] = fz[7] * 10 + s[k++] - '0';
					k++;
					if (s[k] == 'n')
					{
						fz[0] += cat[pt] = 1;
						if (!blo)
							ans = max(ans, fz[0]);
					}
					else
					{
						while (isdigit(s[k]))
							fz[8] = fz[8] * 10 + s[k++] - '0';
						if (fz[8] < fz[7])
							if (!blo)
								blo = fornum;
					}
				}
			}
			else
			{
				fornum--;
				fz[0] -= cat[pt];
				cat[pt] = 0;
				tong[stk[pt--]] = 0;
				if (fornum < 0)
					err = 1;
				else if (fornum == blo)
					blo = 0;
			}
		}
		if (fornum != 0)
			err = 1;
		if (err)
			puts("ERR");
		else if ((ans == diff && isnum) || (ans == 0 && !isnum))
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
