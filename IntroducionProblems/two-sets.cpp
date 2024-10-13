#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long ull;

int main() {
  ull n;
  cin >> n;
  ull sum = (n * (n + 1)) / 2;
  if (sum & 1) {
    cout << "NO";
    return 0;
  };
  cout << "YES" << endl;
  ull e = n;
  ull s = 4;
  vector<ull> x;
  vector<ull> y;

  if (n & 1) {
    x = {1, 2};
    y = {3};
    n = (n - 3) / 4;
  } else {
    n /= 4;
    s = 1;
  }

  while (n) {
    x.push_back(s);
    x.push_back(e);
    s++;
    e--;
    y.push_back(s);
    y.push_back(e);
    s++;
    e--;
    n--;
  }

  cout << x.size() << endl;
  for (int i = 0; i < x.size(); i++) {
    cout << x[i] << " ";
  }
  cout << endl << y.size() << endl;
  for (int i = 0; i < y.size(); i++) {
    cout << y[i] << " ";
  }
}
