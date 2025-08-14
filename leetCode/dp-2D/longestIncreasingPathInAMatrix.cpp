#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
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

int m, n;
vector<vector<int>> matrix;
map<pair<int, int>, int> dp;
vector<pair<int, int>> D = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int dfs(int i, int j, int prevValue) {
  if (i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] <= prevValue) {
    return 0;
  }

  if (dp[{i, j}])
    return dp[{i, j}];

  int res = 1;
  for (auto d : D) {
    res = max(res, 1 + dfs(i + d.first, j + d.second, matrix[i][j]));
  }

  dp[{i, j}] = res;
  return dp[{i, j}];
}

int main() {
  matrix = {{9, 9, 4}, {6, 6, 4}, {2, 1, 1}};
  m = matrix.size();
  n = matrix[0].size();

  int res = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      res = max(res, dfs(i, j, -1));
    }
  }

  cout << res << endl;
  return 1;
}
