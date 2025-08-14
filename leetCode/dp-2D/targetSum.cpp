#include <bits/stdc++.h>
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

vector<int> nums = {1, 1, 1, 1, 1};
map<pair<int, int>, int> dp;

int dfs(int i, int target) {
  if (i == nums.size() && target == 0)
    return 1;
  if (i > nums.size())
    return 0;
  if (dp[{i, target}])
    return dp[{i, target}];

  dp[{i, target}] = dfs(i + 1, nums[i] + target) + dfs(i + 1, nums[i] - target);
  return dp[{i, target}];
}

int main() {
  cout << dfs(0, 3) << endl;
  return 1;
}
