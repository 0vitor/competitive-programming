#include <bits/stdc++.h>
#include <iostream>

using namespace std;
typedef signed long long ll;

int main() {
  ll n;
  cin >> n;
  ll x[n];
  if (n == 1) {
    cout << 1;
    return 0;
  }

  if (n <= 3ll) {
    cout << "NO SOLUTION";
    return 0;
  }

  ll j = 0;

  for (ll i = 2; i < n + 1; i++) {
    if (!(i & 1))
      x[j++] = i;
  }

  for (ll i = 1; i < n + 1; i++) {
    if (i & 1)
      x[j++] = i;
  }

  for (ll i = 0; i < n; i++)
    cout << x[i] << " ";
}
