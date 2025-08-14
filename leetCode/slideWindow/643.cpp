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

double findMaxAverage(vector<int> &nums, int k) {
  double sum = 0;
  for (int i = 0; i < k; i++) {
    sum += nums[i];
  }

  double maxSum = sum;
  int i = 0, j = k;

  while (j < nums.size()) {
    sum = sum - nums[i] + nums[j];
    maxSum = max(maxSum, sum);
    i++;
    j++;
  }

  return maxSum / k;
}

int main() {
  vector<int> nums = {1, 12, -5, -6, 50, 3};
  dbg(findMaxAverage(nums, 4));
}
