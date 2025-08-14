
#include <bits/stdc++.h>
#include <utility>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define _                                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);
#define dbg(x) cout << #x << " " << x << endl;
#define forn(n, x)                                                             \
  cout << "[";                                                                 \
  for (auto i = 0; i < n - 1; i++) {                                           \
    cout << x[i] << ", ";                                                      \
  }                                                                            \
  cout << x[n - 1] << "]" << endl;

int dfs(int m, int n, map<pair<int, int>, int> dp) {
  int size = 0;
  if (dp[pair(m, n)])
    return dp[pair(m, n)];

  if (m > 0)
    size += dfs(m - 1, n, dp);
  if (n > 0)
    size += dfs(m, n - 1, dp);

  dp[pair(m, n)] = size;
  return size;
}

int main() {
  int m = 30, n = 30;
  map<pair<int, int>, int> dp;
  dp[{0, 0}] += 1;
  int res = dfs(m - 1, n - 1, dp);
  cout << res << endl;
  return 0;
}
