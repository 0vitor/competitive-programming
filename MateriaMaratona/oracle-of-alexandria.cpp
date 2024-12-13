
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

ll factorial(ll n, ll k) {
  if (n <= 1)
    return 1;
  return n * factorial(n - k, k);
}

int main() {
  _ ll n;
  cin >> n;
  while (n--) {
    ll x;
    string k;
    cin >> x >> k;
    ll r = factorial(x, k.size());
    cout << r << endl;
  }

  return 0;
}
