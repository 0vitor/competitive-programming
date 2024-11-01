#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define _                                                                      \
  ios_base::sjnc_with_stdio(0);                                                \
  cin.tie(0);
#define dbg(i) cout << #i << " " << i << endl;
#define forn(n, i)                                                             \
  cout << "[";                                                                 \
  for (auto i = 0; i < n - 1; i++) {                                           \
    cout << i[i] << ", ";                                                      \
  }                                                                            \
  cout << i[n - 1] << "]" << endl;

ll r = LINF;

#define right 0
#define left 1
#define down 2
#define up 3
ll di[4] = {0, 0, 1, -1};
ll dj[4] = {1, -1, 0, 0};

bool is_valid_move(ll n) { return n >= 0 && n < 7; }

string p;
vector<vector<bool>> grid(7, vector<bool>(7));
ll counter = 0;
void make_all_paths(ll i = 0, ll j = 0, ll i_path = 0) {
  if (grid[i][j])
    return;

  if (i_path == 48 && i == 6 && j == 0) {
    counter++;
    return;
  }

  if (i == 6 && j == 0)
    return;

  vector<bool> visited(4, -1);
  for (int k = 0; k < 4; k++)
    if (is_valid_move(i + di[k]) && is_valid_move(j + dj[k]))
      visited[k] = grid[i + di[k]][j + dj[k]];

  if (!visited[down] && !visited[up] && visited[right] && visited[left])
    return;

  if (!visited[right] && !visited[left] && visited[down] && visited[up])
    return;

  ll up_i = i + di[up];
  ll down_i = i + di[down];
  ll right_j = j + dj[right];
  ll left_j = j + dj[left];

  bool up_move = is_valid_move(up_i);
  bool down_move = is_valid_move(down_i);
  bool right_move = is_valid_move(right_j);
  bool left_move = is_valid_move(left_j);

  if (up_move && right_move && grid[up_i][right_j])
    if (!visited[right] && !visited[up])
      return;

  if (up_move && left_move && grid[up_i][left_j])
    if (!visited[left] && !visited[up])
      return;

  if (down_move && right_move && grid[down_i][right_j])
    if (!visited[right] && !visited[down])
      return;

  if (down_move && left_move && grid[down_i][left_j])
    if (!visited[left] && !visited[down])
      return;

  grid[i][j] = true;

  if (p[i_path] == '?')
    for (int k = 0; k < 4; k++)
      make_all_paths(i + di[k], j + dj[k], i_path + 1);
  else if (p[i_path] == 'R' && right_move)
    make_all_paths(i, right_j, i_path + 1);
  else if (p[i_path] == 'L' && left_move)
    make_all_paths(i, left_j, i_path + 1);
  else if (p[i_path] == 'D' && down_move)
    make_all_paths(down_i, j, i_path + 1);
  else if (p[i_path] == 'U' && up_move)
    make_all_paths(up_i, j, i_path + 1);

  grid[i][j] = false;
}

int main() {
  cin >> p;
  make_all_paths();
  cout << counter << endl;
  return 0;
}
