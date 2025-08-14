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

int maximumPopulation(vector<vector<int>> &logs) {
  vector<int> years(101, 0);
  int maxAlive = 0;
  int indexYear = 0;
  for (auto v : logs) {
    for (int i = v[0] - 1950; i < v[1] - 1950; i++) {
      years[i]++;
    }
  }
  for (int i = 0; i < years.size(); i++) {
    if (years[i] > maxAlive) {
      maxAlive = years[i];
      indexYear = i;
    }
  }
  return indexYear + 1950;
}

int main() {
  vector<vector<int>> v = {{2033, 2034}, {2039, 2047}, {1998, 2042},
                           {2047, 2048}, {2025, 2029}, {2005, 2044},
                           {1990, 1992}, {1952, 1956}, {1984, 2014}};
  dbg(maximumPopulation(v));
}
