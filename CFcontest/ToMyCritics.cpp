#include <bits/stdc++.h>

#define _                                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);
#define dbg(x) cout << #x << " = " << x << endl;
#define forn(i, n, x)                                                          \
  for (auto i = 0; i < n; i++) {                                               \
    cout << "[";                                                               \
    cout << i << " " << x[i] << " ";                                           \
    cout << "]";                                                               \
  }
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int main() {
  _ ll t, a;
  cin >> t;
  while (t--) {
    ll n = 3, min = 10, sum = 0;
    while (n--) {
      cin >> a;
      sum += a;
      min = min < a ? min : a;
    }
    sum -= min;
    if (sum >= 10)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
