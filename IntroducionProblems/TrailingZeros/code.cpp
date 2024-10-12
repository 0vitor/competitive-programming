#include <bits/stdc++.h>
#include <iostream>

using namespace std;
typedef unsigned long long ull;

int main() {
  ull n = 0, r = 0, aux = 0;
  cin >> n;
  for (ull i = 5; i <= n; i += 5) {
    aux = i;
    while (aux % 5 == 0) {
      r += 1;
      aux /= 5;
    }
  }

  cout << r << endl;
}
