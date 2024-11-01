#include <bits/stdc++.h>
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

int main() {
  ll n, q;
  cin >> n >> q;
  vector<ll> a(n + 1, 0);
  vector<ll> permutation(n + 1);
  for (int i = 1; i < n + 1; i++) {
    cin >> permutation[i];
  }
  vector<ll> pd(n + 1, 0);

  while (q--) {
    ll type, l, r, c, sum = 0;

    cin >> type;
    switch (type) {
    case 0: {
      cin >> l >> r >> c;
      ll acc = c;
      while (l <= r) {
        pd[l] += acc;
        acc += c;
        l++;
      }
      acc -= c;
      for (int i = l; i < n + 1; i++) {
        pd[i] += acc;
      }

      // forn(n + 1, pd);
      break;
    }
    case 1: {
      cin >> l >> r >> c;
      vector<ll> indexs;
      for (int i = l; i <= r; i++) {
        indexs.push_back(permutation[i]);
      }
      sort(indexs.begin(), indexs.end());
      ll j = 0;
      pd[permutation[l]] += c;
      ll acc = c;
      for (int i = permutation[l] + 1; i < n + 1; i++) {
        if (i >= indexs[j]) {
          acc += c;
          j++;
        }

        pd[i] += acc;
      }
      l++;

      // forn(n + 1, pd);

      break;
    }
    case 2: {
      cin >> l >> r;
      sum = pd[r] - pd[l - 1];
      cout << sum << endl;
      // forn(n + 1, pd);
      sum = 0;
      break;
    }
    case 3: {
      cin >> l >> r;
      while (l <= r) {
        sum += pd[permutation[l]] - pd[permutation[l] - 1];
        l++;
      }
      cout << sum << endl;

      // forn(n + 1, pd);
      sum = 0;
      break;
    }
    }
  }
}

// 0 0 0 0 0
// 0 2 2 2 0
// 3 2 2 5 3 --- 7
// 3 3 3 6 4  -- 2 + 5 = 7
// 3 3 3 6 4  -----  2 + 5 = 7
// 3 + 4 + 6 = 13
// 3 + 3 + 4 = 10
