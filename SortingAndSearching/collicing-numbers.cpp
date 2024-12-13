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
#define addv(v)                                                                \
  for (auto a : v)                                                             \
    cin >> a;

int main() {
  _ ll n, x;
  cin >> n;
  vector<ll> v(n + 1, 0);

  ll counter = 0;
  while (n--) {
    cin >> x;
    if (!v[x - 1])
      counter++;
    v[x] = x;
  }

  cout << counter << endl;
  return 0;
}
