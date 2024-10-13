#include <bits/stdc++.h>
#include <iostream>
#include <vector>
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
ll square(ll x) { return x * x; }
ll bs(ll n, vector<ll> v, ll t) {
  ll l = 1, r = n;
  bool overflow = false;
  while (l <= r) {
    ll m = l + (r - l) / 2ll;
    ll res = 0;

    for (long unsigned int i = 0; i < v.size(); i++) {
      ll sq = square(v[i] + m);
      if (res > LLONG_MAX - sq) {
        overflow = true;
        break;
      }
      res += sq;
    };

    if (res == t) {
      return m / 2ll;
    }

    if (res < t && !overflow) {
      l = m + 1ll;
    } else {
      r = m - 1ll;
      overflow = false;
    }
  }

  return -1;
}

int main() {
  _;
  ll t;
  cin >> t;
  while (t--) {
    ll n, ci;
    cin >> n >> ci;
    ll range = (ll)sqrt(ci);

    vector<ll> v;

    for (int i = 0; i < n; i++) {
      ll p;
      cin >> p;
      v.push_back(p);
    }

    // forn(n, v);
    ll r = bs(range, v, ci);
    cout << r << endl;
  }
  return 0;
}
