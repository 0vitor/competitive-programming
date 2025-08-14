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

vector<vector<int>> insert(vector<vector<int>> &intervals,
                           vector<int> &newInterval) {
  if (intervals.size() == 0) {
    intervals.push_back(newInterval);
    return intervals;
  }
  vector<int> nums(max(newInterval[1], intervals[intervals.size() - 1][1]) + 1,
                   0);
  vector<vector<int>> intervalsMerged;
  for (auto i : intervals) {
    for (int j = i[0]; j < i[1]; j++) {
      nums[j] = 1;
    }
    nums[i[1]] = -1;
  }

  for (int j = newInterval[0]; j < newInterval[1]; j++) {
    nums[j] = 1;
  }

  if (nums[newInterval[1]] == 0) {
    nums[newInterval[1]] = -1;
  }

  for (int i = 0; i < nums.size(); i++) {
    vector<int> ni(2);
    ni[0] = i;
    while (nums[i] == 1 || nums[i] == -1) {
      if (nums[i] == -1) {
        ni[1] = i;
        intervalsMerged.push_back(ni);
        break;
      }
      i++;
    }
  }

  return intervalsMerged;
}
int main() {
  vector<vector<int>> intervals = {{1, 3}, {6, 9}};
  vector<int> newInterval = {2, 5};
  vector<vector<int>> res = insert(intervals, newInterval);
  for (auto i : res) {
    cout << "[" << i[0] << ", " << i[1] << "] ";
  }
  cout << endl;
  return 0;
}
