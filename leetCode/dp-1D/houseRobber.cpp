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

int dfs(int i, vector<int> &houses, map<int, int> &dp) {
  if (dp[i])
    return dp[i];
  if (i >= houses.size())
    return 0;
  else {
    dp[i] = max(dfs(i + 1, houses, dp), dfs(i + 2, houses, dp) + houses[i]);
    return dp[i];
  }
}

int main() {
  vector<int> nums = {2, 7, 9, 3, 1};
  map<int, int> dp;
  int res = dfs(0, nums, dp);
  cout << res << endl;
  return res;
}
