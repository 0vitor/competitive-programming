#include <bits/stdc++.h>
#include <cmath>

typedef unsigned long long ull;
using namespace std;

int main() {
  ull t, sum = 0;
  cin >> t;

  while (t--) {
    ull n;
    cin >> n;
    while (n--) {
      ull a;
      cin >> a;
      sum += a;
    }
    ull sq = (ull)sqrt(sum);
    if (sq * sq == sum) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
    sum = 0;
  }
  return 0;
}
