#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;
typedef unsigned long long ull;

int main() {
  std::map<char, int> letterCount;
  string s;
  cin >> s;
  for (long unsigned int i = 0; i < s.size(); i++) {
    letterCount[s[i]]++;
  }
  if (letterCount.size() == 1) {
    cout << s << endl;
    return 0;
  }

  int odd = 0;
  for (const auto p : letterCount) {
    if (p.second & 1)
      odd++;
  }
  int sz = s.size();
  if ((sz & 1 && odd != 1) || (!(sz & 1) && odd != 0)) {
    cout << "NO SOLUTION" << endl;
    return 0;
  }

  string news;
  char ki;
  int vi = 0;
  for (const auto p : letterCount) {
    int v = p.second;
    if (v & 1) {
      ki = p.first;
      vi = p.second;
      continue;
    }

    int i = v / 2;
    while (i--) {
      news.push_back(p.first);
    }
  }

  int i = vi;
  while (i--) {
    news.push_back(ki);
  }

  for (int i = news.length() - 1 - vi; i >= 0; --i) {
    news.push_back(news[i]);
  }

  cout << news << endl;
}
