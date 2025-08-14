#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
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

int dfs(int i, string &s, map<int, int> &dp) {
  int sum;

  // if (dp[i])
  //   return dp[i];
  if (i == s.size()) {
    return 1;
  }

  if (i >= s.size() || s[i] - '0' == 0) {
    return 0;
  }

  sum = dfs(i + 1, s, dp);
  if (s[i] - '0' < 3 && s[i + 1] - '0' < 7) {
    sum += dfs(i + 2, s, dp);
  }

  return sum;
}

int main() {
  // string s = {1, 1, 1, 0, 6};
  string s = {1, 2};
  // string s = {0, 2};
  map<int, int> dp;
  dp[s.size() - 1] = 1;
  int res = dfs(0, s, dp);
  cout << res << endl;
  return res;
}
