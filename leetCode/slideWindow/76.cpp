#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
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

string minWindow(string s, string t) {
  int j = 0, counter = 0, exist = 0;
  pair<int, int> res = {0, s.size()};
  map<char, int> mp;
  for (auto c : t)
    mp[c] += 1;

  for (int i = 0; i < s.size(); i++) {
    if (mp.count(s[i])) {
      while (j < s.size() && counter != t.size()) {
        auto it = mp.find(s[j]);
        if (it != mp.end()) {
          if (mp[s[j]] > 0)
            counter++;
          mp[s[j]] -= 1;
          // dbg(s[j]);
        }
        j++;
      }
      // cout << counter << " ";
      // dbg2(i, j);

      if (counter >= t.size() && j - i <= res.second - res.first) {
        res.first = i;
        res.second = j;
        exist = 1;
      }

      if (mp[s[i]] >= 0)
        counter--;
      mp[s[i]] += 1;
    }
  }
  if (exist)
    return s.substr(res.first, res.second - res.first);
  return "";
}

int main() {
  string s = "acbbaca";
  string t = "aba";
  // string s = "a";
  // string t = "a";
  cout << minWindow(s, t) << endl;
}
