#include <bits/stdc++.h>
#include <iostream>

using namespace std;
typedef signed long long ll;

int main() {
  ll n, prev, current, r = 0;

  cin >> n;
  cin >> prev;
  while (--n > 0) {
    cin >> current;
    if (prev > current) {
      r += (prev - current);
    } else {
      prev = current;
    }
  }

  cout << r;
}
