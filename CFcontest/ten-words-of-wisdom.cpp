#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define _                                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);
#define dbg(x) cout << #x << " " << x << endl;
#define forn(i, n, x)                                                          \
  for (auto i = 0; i < n; i++) {                                               \
    cout << "[";                                                               \
    cout << i << " " << x[i] << " ";                                           \
    cout << "]";                                                               \
  }

int main() {
  _;
  ll t, n, a, b, c = 0;
  cin >> t;
  while (t--) {
    ll maxQuality = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a >> b;
      if (a <= 10 && maxQuality < b) {
        maxQuality = b;
        c = i;
      }
    }
    cout << c + 1 << endl;
  }
  return 0;
}
