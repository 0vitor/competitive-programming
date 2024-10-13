#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
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
  _;
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
      ll aux;
      cin >> aux;
      v[i] = aux;
    }
    sort(v.begin(), v.end(), greater<ll>());
    ll gmax = 0, cmax = 0;
    for (int i = 0; i < n; i++) {
      if (v[i] > n)
        continue;

      for (int j = 0; j < n; j++) {

        if (v[j] > n) {
          continue;
        }

        if (v[i] % v[j] == 0) {
          cmax += 1;
        }
      }
      gmax = cmax > gmax ? cmax : gmax;
      cmax = 0;
    }
    gmax = cmax > gmax ? cmax : gmax;
    cout << gmax << endl;
    gmax = 0;
  }
  return 0;
}
