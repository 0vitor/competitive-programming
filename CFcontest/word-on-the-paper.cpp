
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define _                                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);
#define dbg(x) cout << #x << " " << x << endl;

int main() {
  _;
  ll t;
  cin >> t;
  while (t--) {
    ll n = 8 * 8;
    string s;
    while (n--) {
      char c;
      cin >> c;
      if (c != '.')
        s.push_back(c);
    }
    cout << s << "\n";
  }
  return 0;
}
