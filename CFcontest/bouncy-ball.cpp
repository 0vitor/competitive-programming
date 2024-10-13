#include <bits/stdc++.h>

#define _                                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);
#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

using namespace std;
int main() { _
ll t, collision = 0;
  cin >> t;
  ll n, m, i1, j1, i2, j2, dx, dy, res = 0;
  string s;

  while (t--) {
    ll maxx = m * n * 4;
    cin >> n >> m >> i1 >> j1 >> i2 >> j2 >> s;
    n--;
    m--;
    dx = s[0] == 'D' ? 1 : -1;
    dy = s[1] == 'R' ? 1 : -1;

    while (maxx--) {
      if (i1 == n || i1 == 0) {
        dx *= -1;
        res++;
      };
      if (j1 == m || j1 == 0) {
        dy *= -1;
        res++;
      }

      i1 += dx;
      j1 += dy;

      if (i1 == i2 & j1 == j2) {
        cout << res << endl;
        break;
      }
    }
  }
  return 0;
}
