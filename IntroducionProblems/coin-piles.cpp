#include <bits/stdc++.h>
#include <iostream>

using namespace std;
typedef unsigned long long ull;

int main() {
  ull a, b, n;
  cin >> n;
  while (n--) {
    cin >> a >> b;
    if (!((2 * a - b) % 3 || (2 * a - b) < 0 || (2 * b - a) % 3 ||
          (2 * b - a) < 0)) {
      cout << "YES" << endl;
      continue;
    }
    cout << "NO" << endl;
  }
}
