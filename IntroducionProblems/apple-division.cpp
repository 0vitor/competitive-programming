#include <bits/stdc++.h>
#include <iostream>
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

ll r = LINF;
ll len = 0;
void solve(vector<ll> v, ll i, ll sum1, ll sum2) {
  if (i == len) {
    r = min(r, abs(sum1 - sum2));
    return;
  }
  solve(v, i + 1, sum1 + v[i], sum2);
  solve(v, i + 1, sum1, sum2 + v[i]);
  return;
}

int main() {
  ll t;
  cin >> t;
  vector<ll> v(t);

  for (int i = 0; i < t; i++) {
    cin >> v[i];
  }
  len = v.size();

  solve(v, 0, 0, 0);
  cout << r << endl;

  return 0;
}
