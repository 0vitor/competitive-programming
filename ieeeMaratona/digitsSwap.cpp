#include <bits/stdc++.h>
#include <utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
  _ string N;
  cin >> N;
  ll K;
  cin >> K;

  for (ull i = 0; i < N.size() && !K; i++) {
    ll max_idx = i;
    bool swapped = false;
    ll repeatCount = 1;
    for (ll j = i + 1; j < N.size(); j++) {
      if (N[j] == N[max_idx]) {
        repeatCount++;
      }

      if (N[j] > N[max_idx]) {
        swapped = true;
        max_idx = j;
        repeatCount = 0;
      }
    }

    vector<ll> slice;
    ll k = i;
    while (k < K + i) {
      if (N[k] < N[max_idx]) {
        k++;
      }
      slice.push_back(N[k]);
    }
    if (swapped) {
      swap(N[i], N[max_idx]);
      K--;
    }
  }

  cout << N << endl;

  return 0;
}
