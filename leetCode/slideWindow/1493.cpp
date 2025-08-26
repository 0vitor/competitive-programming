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

int logestSubarray(vector<int> &nums) {
  int start = 0, end = 0, hasZero = 0, res = 0;
  int n = nums.size();
  while (end < n) {
    if (!nums[end]) {
      hasZero++;
    }
    if (hasZero > 1) {
      if (nums[start] == 0)
        hasZero--;
      start++;
    }
    end++;
    res = max(res, end - start);
  }

  return res;
}
int main() {
  vector<int> nums = {1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1};
  dbg(logestSubarray(nums))
}
