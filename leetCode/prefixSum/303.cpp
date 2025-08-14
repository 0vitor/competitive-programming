#include <bits/stdc++.h>
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

class NumArray {
public:
  vector<int> ns;
  NumArray(vector<int> &nums) {
    vector<int> aux(nums.size() + 1, 0);
    for (int i = 1; i < aux.size(); i++) {
      aux[i] += aux[i - 1] + nums[i - 1];
    }
    ns = aux;
  }

  int sumRange(int left, int right) { return ns[right + 1] - ns[left]; }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main() {
  vector<int> nums = {-2, 0, 3, -5, 2, -1};
  NumArray *numArray = new NumArray(nums);
  numArray->sumRange(0, 2); // 1
  numArray->sumRange(2, 5); // -1
  numArray->sumRange(0, 5); // -3
}
