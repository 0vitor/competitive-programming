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

int minCoins;

int dfs(string s, vector<string> &wordDict, vector<int> dp, int dpi) {
  if (dpi == s.size()) {
    return 1;
  }

  for (string word : wordDict) {
    if (dp[dpi + word.size()]) {
      cout << "continue" << endl;
      continue;
    }

    string slice = s.substr(dpi, word.size());
    int isEqual = slice.compare(word) == 0;
    if (isEqual) {
      dpi = dpi + word.size();
      dp[dpi] = 1;
      if (dfs(s, wordDict, dp, dpi)) {
        return 1;
      }
      dpi = dpi - word.size();
    }
  }

  return 0;
}

int main() {
  vector<string> wordDict = {"a",         "aa",        "aaa",     "aaaa",
                             "aaaaa",     "aaaaaa",    "aaaaaaa", "aaaaaaaa",
                             "aaaaaaaaa", "aaaaaaaaaa"};
  string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
             "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
             "aaaaaaaaaaaaaaaaaaaab";
  vector<int> dp(s.size() + 1, 0);

  for (string word : wordDict) {
    int wordSize = word.size();
    string slice = s.substr(0, wordSize);
    int isEqual = slice.compare(word) == 0;

    if (isEqual) {
      dp[wordSize] = 1;
      if (dfs(s, wordDict, dp, wordSize)) {
        cout << 1 << endl;
        return 1;
      }
    }
  }

  cout << 0 << endl;

  return 0;
}
