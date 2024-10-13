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

int solve(int n, int l, int r, int a) {
  if (n == 1) {
    cout << l << " " << r << endl;
    return 0;
  }

  solve(n - 1, l, a, r);
  cout << l << " " << r << endl;

  solve(n - 1, a, r, l);
  return 0;
}

int main() {
  int n;
  cin >> n;
  cout << pow(2, n) - 1 << endl;
  solve(n, 1, 3, 2);
  return 0;
}
