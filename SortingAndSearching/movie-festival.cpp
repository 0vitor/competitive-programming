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
  vector<pair<ll, ll>> v(n);
  for (auto &a : v)
    cin >> a.first >> a.second;

  sort(v.begin(), v.end(), [](const pair<ll, ll> &a, const pair<ll, ll> &b) {
    return a.second < b.second;
  });

  ll end = v[0].second;
  ll count = 1;
  for (int i = 1; i < n; i++) {
    if (end <= v[i].first) {
      count++;
      end = v[i].second;
    }
  }

  cout << count << endl;
  return 0;
}
