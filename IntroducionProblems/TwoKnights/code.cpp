#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

int main() {
  ull n;
  cin >> n;
  for (ull k = 1; k <= n; k++) {
    ull p = ((k * k) * (k * k - 1)) / 2;
    ull c = 4 * (k - 1) * (k - 2);
    cout << p - c << endl;
  }
}
