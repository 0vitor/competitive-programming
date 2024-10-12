#include <bits/stdc++.h>
#include <cstddef>
#include <iostream>

using namespace std;
typedef unsigned long long ll;

int main() {
  ios::sync_with_stdio(false);
  string r;
  cin >> r;
  ll longestSequence = 0;
  ll currentSequence = 1;
  char c = r[0];
  for(size_t i = 1; i < r.size(); i++) {
    if(c == r[i]) {
      currentSequence += 1;
    } else {
      longestSequence = currentSequence > longestSequence ? currentSequence : longestSequence;
      currentSequence = 1;
    }
    c = r[i];
  }
  longestSequence = currentSequence > longestSequence ? currentSequence : longestSequence;
  cout << longestSequence;
  return 0;
}

