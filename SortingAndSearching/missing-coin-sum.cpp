#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define _                                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);
#define dbg(i) cout << #i << " " << i << endl;
#define forn(n, x)                                                             \
  cout << "[";                                                                 \
  for (auto i = 0; i < n - 1; i++) {                                           \
    cout << x[i] << ", ";                                                      \
  }                                                                            \
  cout << x[n - 1] << "]" << endl;

int main() {
  _ ll n;
  cin >> n;
  vector<ll> v(n);
  for (auto &a : v)
    cin >> a;
  sort(v.begin(), v.end());

  ll x = 1;

  for (ll i = 0; i < n; i++) {
    if (v[i] > x) {
      cout << x << endl;
      return 0;
    }

    x += v[i];
  }

  cout << x << endl;

  return 0;
}
