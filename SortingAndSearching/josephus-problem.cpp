#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define _                                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);
#define dbg(i) cout << #i << " " << i << endl;
#define forn(n, x)                                                             \
  cout << "[";                                                                 \
  for (auto i = 0; i < n - 1; i++) {                                           \
    cout << x[i] << ", ";                                                      \
  }                                                                            \
  cout << x[n - 1] << "]" << endl;
#define addv(v)                                                                \
  for (auto a : v)                                                             \
    cin >> a;

struct Node {
  ll data;
  Node *next;
};

int main() {
  ll n, x;
  cin >> n;
  Node *head = new Node{1, nullptr};
  Node *tail = new Node{1, head};
  head->next = tail;

  Node *current = head;
  for (int i = 2; i <= n; i++) {
    current->next = new Node{i, head};
    tail->next = current->next;
    tail = current->next;
    current = current->next;
  }
  current = head;
  while (n--) {
    x = current->next->data;
    current->next = current->next->next;
    cout << x << " ";
    current = current->next;
  }

  return 0;
}
