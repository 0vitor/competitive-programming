#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
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

map<pair<int, int>, int> dp;

int dfs(int i, int j) { return 0; }

vector<int> days = {1, 4, 6, 7, 8, 20};
vector<int> costs = {7, 2, 15};

int main() {
  vector<int> dp(days.size() + 1, INT_MAX);
  dp[days.size()] = 0;

  for (int i = days.size() - 1; i >= 0; i--) {
    int index2 =
        lower_bound(days.begin() + i, days.end(), days[i] + 7) - days.begin();
    int index3 =
        lower_bound(days.begin() + i, days.end(), days[i] + 30) - days.begin();

    dp[i] = dp[i + 1] + costs[0];
    dp[i] = min(dp[i], dp[index2] + costs[1]);
    dp[i] = min(dp[i], dp[index3] + costs[2]);
  }

  cout << dp[0] << endl;

  return 0;
};
