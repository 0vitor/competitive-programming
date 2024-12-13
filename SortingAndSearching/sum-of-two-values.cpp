
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
  _ ll n, x;
  cin >> n >> x;
  map<ll, vector<ll>> m;
  for (int i = 0; i < n; i++) {
    ll aux;
    cin >> aux;
    m[aux].push_back(i + 1);
  }

  for (auto a : m) {
    ll aux = x - a.first;
    if (m.find(aux) != m.end()) {
      for (auto idx : m[aux]) {
        if (idx != a.second[0]) {
          cout << a.second[0] << " " << idx;
          return 0;
        }
      }
    }
  }

  cout << "IMPOSSIBLE" << endl;

  return 0;
}
