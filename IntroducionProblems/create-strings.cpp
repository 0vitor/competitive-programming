#include <bits/stdc++.h>
#include <iostream>
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

ll findLastDecreasingElem(string c) {
  auto size = c.size();
  ll i = size - 1;
  for (; i > 0 && c[i - 1] >= c[i]; --i)
    ;
  return i - 1;
}

ll findUpperBoundFromSuffix(string c, ll i) {
  auto size = c.size();
  ll j = i + 1;
  while (j < size && c[j] > c[i])
    j++;
  return j - 1;
}

bool cmp(char x, char y) { return x < y; }

int main() {
  string s;
  vector<string> as;
  cin >> s;
  sort(s.begin(), s.end(), cmp);
  as.push_back(s);

  while (true) {
    ll i = findLastDecreasingElem(s);
    if (i == -1)
      break;
    ll j = findUpperBoundFromSuffix(s, i);
    char aux = s[i];
    s[i] = s[j];
    s[j] = aux;
    reverse(s.begin() + i + 1, s.end());
    as.push_back(s);
  }

  ll amountPermutations = as.size();
  cout << amountPermutations << endl;
  for (int i = 0; i < amountPermutations; i++) {
    cout << as[i] << endl;
  }

  return 0;
}
