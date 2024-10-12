#include <bits/stdc++.h>
#include <iostream>

using namespace std;
typedef unsigned long long ll;

int main() {
    ll l, n, r = 0;
    cin >> l;
    for (ll i = 1; i < l; i++) {
      cin >> n;
      r ^= n ^ i;
    }
    cout << (r ^ l);
    return 0;
}
