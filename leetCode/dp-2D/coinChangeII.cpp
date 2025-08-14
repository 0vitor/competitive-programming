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

vector<int> coins = {1, 2, 5};
int sum = 0;
map<pair<int, int>, int> dp;
int dfs(int i, int amount) {
  if (dp[{i, amount}])
    return dp[{i, amount}];
  if (amount == 0)
    return 1;
  if (amount < 0 || i >= coins.size())
    return 0;

  dp[{i, amount}] = dfs(i, amount - coins[i]) + dfs(i + 1, amount);
  return dp[{i, amount}];
}

int main() {
  int amount = 5;
  // vector<int> coins = coinsInput;
  cout << dfs(0, amount) << endl;
}
