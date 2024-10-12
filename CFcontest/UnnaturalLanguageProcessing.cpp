#include <bits/stdc++.h>

typedef unsigned long long ull;
using namespace std;
bool isV(char c) { return c == 'a' || c == 'e'; }

int main() {
  bool valid = true;
  string s, out;
  ull t;
  cin >> t;
  while (t--) {
    ull n;
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
      if (i + 3 < n && !isV(s[i]) && isV(s[i + 1]) && !isV(s[i + 2])) {
        i += 2;
        if (i >= n) {
        } else if (i < n && !isV(s[i])) {

          cout << s[i] << s[i + 1] << '.';
          cout << s[i] << s[i + 1] << s[i + 2] << '.';
          i++;
        }
      }
    }
    return 0;
  }
}
