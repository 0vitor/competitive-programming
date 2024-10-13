#include <bits/stdc++.h>
#include <iostream>
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

int bs(ll n, ll a, ll b, ll c) {
  ll l = 1, r = n;
  while (l <= r) {
    ll m = l + (r - l) / 2;
    ll res = a * m * m + b * m + c;
    // dbg(res);
    if (res == 0) {
      return m;
    }

    if (res < 0) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }

  return -1;
}

int main() {
  _;
  ll t;
  cin >> t;
  while (t--) {
    ll a = 0, b = 0, c = 0;
    ll n, ci;
    cin >> n >> ci;

    ll range = (ll)sqrt(ci) / n;

    while (n--) {
      ll p;
      cin >> p;
      a += 4;
      b += (p * 2) + (p * 2);
      c += p * p;
    }
    dbg(c);
    c = -(ci - c);
    ll r = bs(range, a, b, c);
    cout << r << endl;
  }
  return 0;
}
