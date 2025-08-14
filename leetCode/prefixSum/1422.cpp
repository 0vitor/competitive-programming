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

int maxScore(string s) {
  int res = 0, l = 0, r = 0;
  for (char c : s) {
    r += c == '1';
  }
  s.pop_back();
  for (char c : s) {
    l += c == '0';
    r -= c == '1';
    res = max(l + r, res);
  }

  return res;
}

int main() {
  string s = "00";
  int res = maxScore(s);
  cout << res << endl;
  return res;
}
