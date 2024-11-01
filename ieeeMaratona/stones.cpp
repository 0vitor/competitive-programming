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
  cout << x[n - 1] << "]";

ll largestRectangleArea(vector<ll> heights, ll c) {
  stack<ll> stack;
  stack.push(-1);
  ll max_area = 0;

  bool inc = false;
  ll incHeight = 0;
  for (ll i = 0; i < heights.size(); i++) {
    while (stack.top() != -1) {

      if (heights[i] <= heights[stack.top()]) {
        if (!inc && heights[i] < c) {
          heights[i] = c;
          inc = true;
        }
        ll height = heights[stack.top()];
        stack.pop();
        ll width = i - stack.top() - 1;
        max_area = max(max_area, height * width);
        // dbg(max_area);
      }
      stack.push(i);
    }

    while (stack.top() != -1) {
      ll height = heights[stack.top()];
      stack.pop();
      ll width = heights.size() - stack.top() - 1;
      max_area = max(max_area, height * width);
    }

    return max_area;
  }

  int main() {
    _ ll n, c;
    cin >> n >> c;
    vector<ll> heigths(n);
    for (auto &v : heigths)
      cin >> v;

    cout << largestRectangleArea(heigths, c) << endl;
    return 0;
  }
