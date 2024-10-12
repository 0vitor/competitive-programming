#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vs vector<string>
#define mii unordered_map<int, int>
#define mss unordered_map<string, int>
#define pii pair<int, int>
#define si set<int>
#define pb push_back
#define MOD 1000000007
#define gcd(a, b) __gcd(a, b)
#define all(a) (a).begin(), (a).end()
#define f(s, e) for (auto i = s; i < e; i++)
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
// main code here
void solve() {
  int n, q;
  cin >> n >> q;
  int arr[n];
  vector<ll> p(n + 1, 0);
  p.pb(2);
  forn(i, n) {
    cin >> arr[i];
    p[i + 1] = p[i] + arr[i];
  }
  forn(i, q) {
    ll sum = p[n];
    int l, r, k;
    cin >> l >> r >> k;
    int n = r - l + 1;
    sum += (k * n);
    sum -= p[r] - p[l - 1];
    if (sum % 2 != 0)
      yes();
    else
      no();
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
