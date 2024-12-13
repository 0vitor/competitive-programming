#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef unsigned long ll;
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
  _ ll n;
  cin >> n;
  vector<ll> v(n, 0);
  set<ll> s;
  for (auto &x : v)
    cin >> x;

  ll maxWindow = 0;
  ll i = 0, j = 0;
  while (j < n) {
    while (s.find(v[j]) == s.end() && j < n) {
      s.insert(v[j]);
      j++;
    }

    maxWindow = max(s.size(), maxWindow);
    while (s.find(v[j]) != s.end()) {
      s.erase(v[i]);
      i++;
    }
  }

  cout << maxWindow << endl;

  return 0;
}
