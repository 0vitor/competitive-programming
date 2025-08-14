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

int sumOddLengthSubarrays(vector<int> &arr) {
  int sum = 0;
  int n = arr.size();

  for (int i = 0; i < n; i++) {
    int start = i + 1;
    int end = n - i;
    int total = start * end;
    int oddCount = (total + 1) / 2;

    sum += arr[i] * oddCount;
  }

  return sum;
}

int main() {}
