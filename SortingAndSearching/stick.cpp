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
  ll mid = (n - 1) / 2;

  nth_element(v.begin(), v.begin() + mid, v.end());
  ll aux = v[mid];
  v[mid] = v[0];
  v[0] = aux;
  ll counter = 0;
  for (ll i = 0; i < n - 1; i++) {
    ll diff = v[i] - v[i + 1];
    v[i + 1] += diff;
    counter += abs(diff);
  }

  cout << counter << endl;
  return 0;
}
