#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define _                                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);
#define dbg(x) cout << #x << " " << x << endl;

int main() {
  ll t;
  cin >> t;
  while (t--) {
    ll k;
    cin >> k;
    if (k <= 9) {
      cout << k << endl;
      continue;
    };

    ll r = 0;
    ll i = 0;
    while (k > 0) {
      ll p = ((pow(10ll, i + 1) - pow(10ll, i))) * (i + 1);

      if (k <= p) {
        break;
      }

      r += p / (i + 1);
      k -= p;
      i++;
    }

    ll offsetNumber = k % (i + 1);
    if (offsetNumber != 0) {
      while (k % (i + 1) != 0) {
        k++;
      }
    }

    ll offset = k / (i + 1);
    r += offset;
    char response = to_string(r)[offsetNumber == 0 ? i : offsetNumber - 1];
    cout << response << endl;
  }

  return 0;
}
