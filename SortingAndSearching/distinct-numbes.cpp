#include <bits/stdc++.h>
#include <ostream>
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
  cout << x[n - 1] << "]" << endl;

int main() {
  _ ll t;
  cin >> t;
  vector<ll> ns(t);
  for (auto &n : ns)
    cin >> n;
  sort(ns.begin(), ns.end());
  ll diff = 1;
  for (ll i = 0; i < t - 1; i++) {
    if (ns[i] != ns[i + 1])
      diff++;
  }

  cout << diff << endl;
  return 0;
}
