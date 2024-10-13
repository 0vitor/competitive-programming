#include <bits/stdc++.h>

#define _                                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);
#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

using namespace std;
int main() {
  _ ll t, n, q, l, r, k;
  cin >> t;
  while (t--) {
    cin >> n >> q;
    bool isOdd[n + 1];
    isOdd[0] = 0;
    for (int i = 0; i < n; i++) {
      ll aux;
      cin >> aux;
      bool parity = aux & 1;
      isOdd[i + 1] = isOdd[i] ^ parity;
    }

    while (q--) {
      cin >> l >> r >> k;
      bool isOddSum;
      bool inputParity = k & 1 ? (l - r + 1) & 1 : 0;
      bool blockParity = isOdd[l - 1] ^ isOdd[r];
      isOddSum = isOdd[n] ^ blockParity ^ inputParity;

      if (isOddSum)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
  return 0;
}
