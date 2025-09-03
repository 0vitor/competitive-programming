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
#define forn(v)                                                                \
  cout << "[";                                                                 \
  for (auto i : v) {                                                           \
    cout << i << ", ";                                                         \
  }                                                                            \
  cout << "]" << endl;

vector<vector<int>> threeSum(vector<int> &nums) {
  vector<vector<int>> res;
  sort(nums.begin(), nums.end());
  int i = 0, j = nums.size() - 1, k = 0;
  while (i + 1 < j) {
    while (k < j && nums[i] + nums[k] + nums[j] <= 0) {
      k++;
      if (nums[i] + nums[k] + nums[j] == 0) {
        res.push_back({nums[i], nums[k], nums[j]});
        break;
      }
    }
    if (nums[i] == nums[i + 1])
      i++;
    if (nums[j] == nums[j - 1])
      j++;
  }

  return res;
}

int main() {
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  threeSum(nums);
}
