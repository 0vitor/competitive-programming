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

int findMaxLength(vector<int> &nums) {
  if (nums.size() == 1)
    return 0;

  int res = 0;
  int summ = 1;
  int i = 1;
  while (i < nums.size()) {
    int pairs = 0;
    if (nums[i] != nums[i - 1]) {
      summ--;
      pairs += 2;
      i++;

      while (i < nums.size() && nums[i] == nums[i - 1] && summ != 0) {
        summ--;
        pairs += 2;
        i++;
      }
    }

    summ = 1;

    while (i < nums.size() && nums[i] == nums[i - 1]) {
      summ++;
      i++;
    }
    res = max(res, pairs);
    pairs = 0;
    i++;
  }

  return res;
}
int main() {
  vector<int> nums = {0, 1, 1, 1, 1, 1, 0, 0, 0};
  cout << findMaxLength(nums) << endl;
}
