
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

int maxArea(vector<int> &height) {
  int i = 0, j = height.size() - 1, res = 0;

  while (i < j) {

    int h = min(height[i], height[j]);
    res = max(res, (j - i) * h);
    if (height[i] > height[j]) {
      j--;
    } else if (height[i] < height[j]) {
      i++;
    } else if (height[i] > height[j - 1]) {
      j--;
    } else if (height[i + 1] < height[j]) {
      i++;
    } else {
      i++;
    }
  }

  return res;
}
int main() {
  // vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  // vector<int> height = {1, 1};
  vector<int> height = {20, 20, 50, 4, 6, 7, 42, 20, 20};
  dbg(maxArea(height));
}
