#include <bits/stdc++.h>
#include <set>
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

int main() {
  int n, m, c;
  cin >> n >> m;
  multiset<int> v;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.insert(x);
    cin >> r;

  while (m--) {
    cin >> c;
    auto it = v.upper_bound(c);
    it--;
    if (it != v.end() && *it <= c) {
      cout << *it << endl;
      v.erase(it);
    } else {
      cout << -1 << endl;
    }
    if (v.empty()){

    return 0;
    }
  }
  return 0;
}
