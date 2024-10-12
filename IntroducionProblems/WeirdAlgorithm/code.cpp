#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

int main() {
  ll l;
  cin >> l;
  cout << l << " ";
  while(l != 1) {
    if((l & 1) == 1) {
      l = (l*3) + 1;
    } else {
      l /= 2;
    }
    cout << l << " ";
  }
  return 0;
}
