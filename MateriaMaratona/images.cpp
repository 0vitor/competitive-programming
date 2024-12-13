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
void printRow(ll hashtags, ll underlines) {
  while (hashtags--) {
    cout << '#';
  }
  while (underlines--) {
    cout << '_';
  }
  cout << endl;
}
int main() {
  _ ll n, m, x, y;
  char ch;

  cin >> n >> m;

  while (n != 0 && m != 0) {
    vector<string> input(n);
    for (auto &row : input) {
      cin >> row;
    }

    cin >> x >> y;
    for (ll i = 0; i < n; i++) {
      ll hashtags = 0;
      ll underlines = 0;

      for (ll j = 0; j < m; j++) {
        if (input[i][j] == '#')
          hashtags++;
        else
          underlines++;
      }

      hashtags *= (y / m);
      underlines *= (y / m);
      for (ll k = 0; k < (x / n); k++) {
        printRow(hashtags, underlines);
      }
    }
    cout << endl;
    cin >> n >> m;
  }
  return 0;
}
