#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define _                                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);
#define dbg(i) cout << #i << " " << i << endl;
#define dbg2(i, j) cout << #i << " " << i << " " << #j << " " << j << endl;
#define forn(v)                                                                \
  cout << "[";                                                                 \
  for (auto i : v) {                                                           \
    cout << i << ", ";                                                         \
  }                                                                            \
  cout << "]" << endl;

int lengthOfLongestSubstring(string s) {
  int i = 0, j = 0, res = 0;
  vector<char> charIndex(128, 0);
  while (j < s.size()) {
    if (!charIndex[s[j]]) {
      charIndex[s[j]] = 1;
      res = max(res, j - i + 1);
      j++;
    } else {
      charIndex[s[i]] = 0;
      i++;
    }
  }
  return res;
}
