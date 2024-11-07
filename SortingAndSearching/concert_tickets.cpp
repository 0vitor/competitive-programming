#include <bits/stdc++.h>
#include <set>
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
  _ ll n, m;
  multiset<ll> ns;
  cin >> n >> m;

  ll aux;
  while (n--) {
    cin >> aux;
    ns.insert(aux);
  }

  while (m--) {
    cin >> aux;
    auto it = ns.upper_bound(aux);
    if (ns.size() && --it != ns.end() && *it <= aux) {
      cout << *it << endl;
      ns.erase(it);
    } else {
      cout << -1 << endl;
    }
  }

  return 0;
}
