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
#define forn(n, x)                                                             \
  cout << "[";                                                                 \
  for (auto i = 0; i < n - 1; i++) {                                           \
    cout << x[i] << ", ";                                                      \
  }                                                                            \
  cout << x[n - 1] << "]" << endl;

struct CompareSecond {
  bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
    return a.second > b.second;
  }
};

int maximumPopulation(vector<vector<int>> &logs) {
  sort(logs.begin(), logs.end(),
       [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
  priority_queue<pair<int, int>, vector<pair<int, int>>, CompareSecond> minHeap;

  int alive = 0;
  int start = 0;
  int earlastYear = logs[0][0];
  minHeap.push(logs[0][1]);
  for (int i = 1; i < logs.size(); i++) {

    int top = minHeap.top().second;
    int topI = minHeap.top().second;
    if (logs[i][0] >= minHeap.top().second) {
      start = topI + 1;
      minHeap.pop();
    } else
      minHeap.push({i, logs[i][1]});

    int size = i - start;
    if (size > alive) {
      earlastYear = logs[i][0];
      alive = size;
    }
  }

  return res;
}

int main() {
  vector<vector<int>> logs = {{1950, 1961}, {1960, 1971}, {1970, 1981}};
  dbg(maximumPopulation(logs));
}

// if m[i][1] > m[i+1][0]
//   year = m[i+1][0]
//   while(m[start][1] <= year)
//     start++;
//     counter--;
