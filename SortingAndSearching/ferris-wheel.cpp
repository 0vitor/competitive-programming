#include <algorithm>
#include <bits/stdc++.h>
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
  _ ll n, x;
  cin >> n >> x;
  vector<ll> ns(n);

  for (auto &a : ns)
    cin >> a;

  sort(ns.begin(), ns.end());

  ll count = 0;
  ll start = 0;
  ll end = n - 1;
  while (start < end) {
    if (ns[end] + ns[start] <= x) {
      start++;
    }

    end--;
    count++;
  }

  if (start == end)
    count++;
  cout << count << endl;
  return 0;
}
