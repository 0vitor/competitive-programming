
#include <bits/stdc++.h>
#include <iostream>
#include <set>
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
  multiset<ll> g;
  ll x;
  cin >> x;
  g.insert(x);

  while (--n) {
    cin >> x;
    auto it = g.upper_bound(x);
    --it;
    if (it == g.end()) {
      it = --g.end();
    }

    if (*it < x) {
      g.erase(*it);
    }
    g.insert(x);
  }
  cout << g.size() << endl;
  return 0;
}
