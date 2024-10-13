#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
ull m = 1e9 + 7ull;

ull fastExp(ull n) {
  ull r = 1;
  while (n--) {
    r <<= 1;
    if (r > m)
      r %= m;
  }
  return r;
}

int main() {
  ull n;
  cin >> n;
  cout << fastExp(n) << endl;
}
