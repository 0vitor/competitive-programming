#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

int main() {
  int n;
  cin >> n;
  n *= 3;
  while (n--) {
    int sum = 198;
    for (int i = 0; i < 3; i++) {
      char c;
      cin >> c;
      sum -= c == '?' ? 0 : c;
    }
    if (sum != 0)
      cout << (char)sum << endl;
  }

  return 0;
}
