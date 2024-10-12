#include <bits/stdc++.h>
#include <iostream>

using namespace std;
typedef signed long long ll;

int main() {
  ll n;
  cin >> n;
  ll i, j, r;
  while (n--) {
    cin >> i >> j;

    if (i >= j) {
      ll max = i * i;
      if (i & 1 && i != j) {
        r = max - (i - 1);
        r -= (i - j);
      } else {
        r = max - (j - 1);
      }

    } else {
      ll max = j * j;
      if (j & 1) {
        r = max - (i - 1);
      } else {
        r = max - (j - 1);
        r -= (j - i);
      }
    }

    cout << r << endl;
  }
}
