
#include <bits/stdc++.h>
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

int main() {
  int m = 3, n = 7;
  vector<vector<int>> dp(m + 2, vector<int>(n + 2, 0));
  dp[m][n] = 1;

  for (int i = m; i > 0; i--) {
    for (int j = n; j > 0; j--) {
      dp[i][j] += dp[i + 1][j];
      dp[i][j] += dp[i][j + 1];
    }
  }

  // cout << dp[1][1] << endl;

  return dp[1][1];
}
