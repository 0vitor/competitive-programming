#include <bits/stdc++.h>
#include <cstdio>
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
  int n;
  cin >> n;
  string format = "%0" + to_string(n) + "b" + "\n";
  int x = 1;
  x <<= n;
  while (x--)
    printf(&format[0], (x ^ (x / 2)));

  return 0;
}
