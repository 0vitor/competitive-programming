#include <bits/stdc++.h>
#include <climits>
#include <map>
#include <utility>
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

vector<int> prices;
map<pair<int, int>, int> dp;

int resMax = INT_MIN;

int dfs(int i = 0, bool buy = false) {
  if (i >= prices.size()) {
    return 0;
  }

  int cooldown = dfs(i + 1, buy);
  dp[{i, cooldown}] = cooldown;

  if (buy) {
    int sellValue = dfs(i + 2, false) + prices[i];
    dp[{i, buy}] = sellValue;
  } else {
    int buyValue = dfs(i + 1, true) - prices[i];
    dp[{i, buy}] = buyValue;
  }

  return dp[{i, buy}];
}

int main() {
  int res = dfs();
  return 0;
}
