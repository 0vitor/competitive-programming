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
  cout << x[n - 1] << "]" << endl;

int main() {
  _;
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    n++;
    vector<ll> freq(n, 0);
    vector<ll> c(n, 0);

    for (int i = 0; i < n - 1; i++) {
      ll frog;
      cin >> frog;
      if (frog < n) {
        freq[frog]++;
      }
    }

    for (ll j = 0; j < n; j++) {
      if (!freq[j])
        continue;
      for (ll k = j; k < n; k += j)
        c[k] += freq[j];
    }

    cout << *max_element(c.begin(), c.end()) << endl;
  }

  return 0;
}
