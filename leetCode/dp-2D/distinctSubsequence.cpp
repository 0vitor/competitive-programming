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

string s1 = "babgbag", s2 = "bag";
map<pair<int, int>, int> dp;

int dfs(int i, int j) {
  if (dp[{i, j}])
    return dp[{i, j}];
  if (j == s2.size())
    return 1;
  if (i == s1.size()) {
    return 0;
  }

  int sum = 0;
  if (s1[i] == s2[j]) {
    sum = dfs(i + 1, j + 1) + dfs(i + 1, j);
  } else {
    sum = dfs(i + 1, j);
  }

  dp[{i, j}] = sum;
  return sum;
}

int main() {
  cout << dfs(0, 0) << endl;
  return 1;
}
