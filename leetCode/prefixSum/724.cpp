#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define _                                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);
#define dbg(i) cout << #i << " " << i << endl;
#define dbg2(i, j) cout << #i << " " << i << " " << #j << " " << j << endl;
#define forn(n, x)                                                             \
  cout << "[";                                                                 \
  for (auto i = 0; i < n - 1; i++) {                                           \
    cout << x[i] << ", ";                                                      \
  }                                                                            \
  cout << x[n - 1] << "]" << endl;

int pivotIndex(vector<int> &nums) {
  int len = nums.size();
  for (int i = 1; i < len; i++) {
    nums[i] += nums[i - 1];
  }
  nums.insert(nums.begin(), 0);
  len++;

  for (int i = 0; i < len; i++)
    if (i + 1 < len && nums[i] == nums[len - 1] - nums[i + 1])
      return i;

  return -1;
}

int main() {
  vector<int> nums = {1, 7, 3, 6, 5, 6};
  int res = pivotIndex(nums);
  cout << res << endl;
  return res;
}
