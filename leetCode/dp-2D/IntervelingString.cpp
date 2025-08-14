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
  string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
  int m = s1.size(), n = s2.size();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

  dp[m][n] = 1;

  for (int i = m; i >= 0; i--) {
    for (int j = n; j >= 0; j--) {

      if (i < m && s3[i + j] == s1[i] && dp[i + 1][j])
        dp[i][j] = 1;
      if (j < n && s3[i + j] == s2[j] && dp[i][j + 1])
        dp[i][j] = 1;
    }
  }

  return dp[0][0];
}
