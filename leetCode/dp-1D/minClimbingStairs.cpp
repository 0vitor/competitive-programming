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

int dfs(int i, vector<int> cost, map<int, int> &dp) {
  if (dp[i])
    return dp[i];
  if (i >= cost.size())
    return 0;
  else {
    dp[i] = min(dfs(i + 1, cost, dp) + cost[i], dfs(i + 2, cost, dp) + cost[i]);
    return dp[i];
  }
}

int main() {
  vector<int> cost = {10, 15, 20};
  map<int, int> dp;
  int res = min(dfs(0, cost, dp), dfs(1, cost, dp));
  cout << res << endl;
  return res;
}
