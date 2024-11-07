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
  _ ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> ps(n);
  vector<ll> ap(m);

  for (auto &p : ps)
    cin >> p;
  for (auto &a : ap)
    cin >> a;

  sort(ps.begin(), ps.end());
  sort(ap.begin(), ap.end());

  ll ips = 0;
  ll iap = 0;
  ll count = 0;
  while (iap < m && ips < n) {
    if (abs(ps[ips] - ap[iap]) <= k) {
      count++;
      ips++;
      iap++;
    } else if (ps[ips] > ap[iap]) {
      iap++;
    } else if (ps[ips] < ap[iap]) {
      ips++;
    }
  }

  cout << count << endl;
  return 0;
}
