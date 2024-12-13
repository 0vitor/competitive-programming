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

int main() {
  _ ll n, start = 0, end = 0, maxSum = 0, currentSum = 0;
  cin >> n;
  vector<ll> v(n);
  for (auto &a : v)
    cin >> a;
  currentSum = v[0];
  while (start < n) {
    if (v[start] < 0 && currentSum < v[start]) {
      currentSum = v[start];
    }
    if (v[start] > 0) {
      currentSum = v[start];
      break;
    }
    start++;
  }
  maxSum = currentSum;

  end = start + 1;
  if (currentSum > 0) {
    while (end < n) {
      if (currentSum + v[end] >= 0) {
        currentSum += v[end];
        end++;
        maxSum = max(maxSum, currentSum);
      } else {
        end++;
        currentSum = 0;
      }
    }
  }

  cout << maxSum << endl;

  return 0;
}
