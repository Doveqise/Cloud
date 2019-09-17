#pragma GCC optimize(3)
#pragma GCC diagnostic error "-std=c++14"
#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse4,mmx")
#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e4 + 1;
const int blk = 2e2 + 5;
int a[maxn], b[maxn], rk[maxn], tmp[maxn], blc[maxn], unrk[maxn],
    num[maxn][blk + 1], f[blk + 1][blk + 1], g[blk + 1][blk + 1];
int t1[maxn], t2[blk << 1 | 1];
inline int getpos(int l, int r)
{
  int x = blc[l], y = blc[r], maxx, numb;
  if (y <= x + 1)
  {
    maxx = numb = 0;
    for (int k = l; k <= r; k++)
    {
      t1[rk[k]]++;
      t2[++t2[0]] = k;
      if (t1[rk[k]] > maxx)
      {
        maxx = t1[rk[k]];
        numb = k;
      }
      else if (t1[rk[k]] == maxx)
        numb = rk[numb] < rk[k] ? numb : k;
    }
    while (t2[0])
    {
      t1[rk[t2[t2[0]]]]--;
      t2[0]--;
    }
  }
  else
  {
    maxx = f[x + 1][y - 1];
    numb = g[x + 1][y - 1];
    for (int k = l; k <= x * blk; k++)
    {
      t1[rk[k]]++;
      t2[++t2[0]] = k;
      if (t1[rk[k]] + num[rk[k]][y - 1] > num[rk[k]][x] + maxx)
      {
        maxx = t1[rk[k]] + num[rk[k]][y - 1] - num[rk[k]][x];
        numb = k;
      }
      else if (t1[rk[k]] + num[rk[k]][y - 1] == maxx + num[rk[k]][x])
        numb = rk[numb] < rk[k] ? numb : k;
    }
    for (int k = (y - 1) * blk + 1; k <= r; k++)
    {
      t1[rk[k]]++;
      t2[++t2[0]] = k;
      if (t1[rk[k]] + num[rk[k]][y - 1] > num[rk[k]][x] + maxx)
      {
        maxx = t1[rk[k]] + num[rk[k]][y - 1] - num[rk[k]][x];
        numb = k;
      }
      else if (t1[rk[k]] + num[rk[k]][y - 1] == maxx + num[rk[k]][x])
        numb = rk[numb] < rk[k] ? numb : k;
    }
    while (t2[0])
    {
      t1[rk[t2[t2[0]]]]--;
      t2[0]--;
    }
  }
  return numb;
}
signed main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  int s = unique(b + 1, b + n + 1) - (b + 1);
  for (int i = 1; i <= n; i++)
  {
    int l = 1, r = s;
    while (l < r)
    {
      int mid = l + r >> 1;
      if (b[mid] < a[i])
        l = mid + 1;
      else
        r = mid;
    }
    rk[i] = l;
    unrk[l] = i;
  }
  for (int i = 1; i <= n; i++)
  {
    blc[i] = (i + blk - 1) / blk;
    num[rk[i]][blc[i]]++;
  }
  int t = blc[n];
  for (int i = 1; i <= t; i++)
  {
    int maxx = 0, numb = 0;
    memset(tmp, 0, sizeof(tmp));
    for (int j = i; j <= t; j++)
    {
      for (int k = (j - 1) * blk + 1; k <= min(n, j * blk); k++)
        if (maxx < ++tmp[rk[k]])
        {
          maxx = tmp[rk[k]];
          numb = k;
        }
        else if (maxx == tmp[rk[k]])
          numb = rk[numb] < rk[k] ? numb : k;
      f[i][j] = maxx;
      g[i][j] = numb;
    }
  }

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= t; j++)
      num[i][j] += num[i][j - 1];
  for (int i = 1, l, r, ans = 0; i <= m; i++)
  {
    scanf("%d%d", &l, &r);
    l = (l + ans - 1) % n + 1;
    r = (r + ans - 1) % n + 1;
    if (l > r)
      swap(l, r);
    ans = a[getpos(l, r)];
    printf("%d\n", ans);
  }
  return 0;
}
