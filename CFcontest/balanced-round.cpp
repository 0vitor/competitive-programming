#include <algorithm>
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
  cout << x[n - 1] << "]";

int main() {
  _;
  ll t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
      cin >> a[i];
    };
    sort(a.begin(), a.end());
    ll culs = 1, ls = 0;
    for (ll i = 0; i < n - 1; i++) {
      if (a[i + 1] - a[i] <= k) {
        culs += 1;
      } else {
        ls = culs > ls ? culs : ls;
        culs = 1;
      }
    };
    ls = culs > ls ? culs : ls;
    ll res = n - ls;
    cout << res << endl;
  }
  return 0;
}
