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

int minCoins;

int dfs(int amount, vector<int> coins, map<int, int> &dp, int nCoins = 0) {
  if (amount < 0 || dp[amount] == -1) {
    return 0;
  }

  if (dp[amount]) {
    dp[amount] = min(dp[amount], nCoins);
    return 1;
  }

  if (amount == 0) {
    minCoins = min(minCoins, nCoins);
    dp[amount] = min(dp[amount], minCoins);
    return 1;
  }

  for (int i : coins) {
    if (dfs(amount - i, coins, dp, nCoins + 1)) {
      dp[amount] = minCoins;
    }
  }

  return 1;
}

int main() {
  vector<int> coins = {1, 2, 5, 3};
  int amount = 20;
  minCoins = amount + 1;

  map<int, int> dp;
  dfs(amount, coins, dp);
  cout << dp[amount] << endl;

  return 0;
}
