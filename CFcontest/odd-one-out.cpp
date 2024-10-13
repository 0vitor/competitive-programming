
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

int main() {
  int n;
  cin >> n;
  int a, b, c;
  while (n--) {
    cin >> a >> b >> c;
    a ^= b ^ c;
    cout << a << endl;
  }
  return 0;
}
