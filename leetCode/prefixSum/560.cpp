#include <bits/stdc++.h>
#include <vector>
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

//  O(n2)
int subarraySum(vector<int> &nums, int k) {
  int res = 0;
  for (int i = 1; i < nums.size(); i++) {
    nums[i] += nums[i - 1];
  }

  for (int i = 0; i < nums.size(); i++) {
    for (int j = i - 1; j >= -1; j--) {
      int right = nums[i];
      int left = j == -1 ? 0 : nums[j];
      if (right - left == k)
        res++;
    }
  }

  return res;
}

//  O(n)
int subarraySum2(vector<int> &nums, int k) {
  int res = 0;
  set<int> ns;
  ns.insert(nums[0]);

  if (ns.count(k))
    res++;
  ns.insert(0);
  for (int i = 1; i < nums.size(); i++) {
    nums[i] += nums[i - 1];
    auto n = ns.find(nums[i] - k);

    if (n != ns.end())
      res += *n;
  }

  return res;
}

int main() {
  vector<int> nums = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int k = 0;
  int res = subarraySum2(nums, k);
  dbg(res);

  return res;
}
