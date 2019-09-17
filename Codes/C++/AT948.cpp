#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

const int64 INF = 1LL << 58;

int64 N, S[5000], M, T[5000];
vector< int > tree[5000];
int64 dp[5001][5001], sz[5001];

void dfs(int idx)
{
  dp[idx][0] = 0;
  dp[idx][1] = S[idx];
  sz[idx] = 1;
  for(auto &to : tree[idx]) {
    dfs(to);
    for(int i = sz[idx]; i > 0; i--) {
      for(int j = sz[to]; j >= 0; j--) {
        dp[idx][i + j] = min(dp[idx][i + j], dp[idx][i] + dp[to][j]);
      }
    }
    sz[idx] += sz[to];
  }
}

int main()
{
  int64 all = 0;

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> S[i];
    all += S[i];
  }
  for(int i = 1; i < N; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    tree[a].push_back(b);
  }
  cin >> M;
  for(int i = 0; i < M; i++) {
    cin >> T[i];
  }
  sort(T, T + M, greater<>());

  fill_n(*dp, 5001 * 5001, INF);
  dfs(0);

  int64 ret = 0;
  int64 latte = 0;
  for(int i = 0; i <= min(N, M); i++) {
    ret = max(ret, all + latte - dp[0][i]);
    latte += T[i];
  }
  cout << ret << endl;
}
