#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
  ll n, a, b;
  cin >> n;
  vector<pair<ll, ll>> v(n);
  for (auto &x : v)
    cin >> x.first >> x.second;
  sort(v.begin(), v.end());
  priority_queue<ll, vector<ll>, greater<ll>> minEnd;
  minEnd.push(v[0].second);

  ll i = 0;
  ll counter = 0;
  while (++i < n) {
    a = v[i].first;
    b = v[i].second;
    ll currentMin = minEnd.top();
    while (a > currentMin && minEnd.size()) {
      minEnd.pop();
      currentMin = minEnd.top();
    }

    if (minEnd.empty()) {
      minEnd.push(b);
    }

    if (a <= currentMin) {
      minEnd.push(b);
      counter = max(counter, (ll)minEnd.size());
    }
  }

  if (!counter) {
    cout << 1 << endl;
  } else {
    cout << counter << endl;
  }
  return 0;
}
