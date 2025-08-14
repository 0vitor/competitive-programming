#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
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

int minCoins;

int main() {
  vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

  vector<int> dp(nums.size(), 1);
  for (int i = nums.size() - 1; i >= 0; --i) {
    for (int j = i; j < nums.size(); ++j) {
      if (nums[i] < nums[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  // forn(dp.size(), dp);

  int maxElement = *max_element(dp.begin(), dp.end());
  // cout << maxElement << endl;

  return maxElement;
}
