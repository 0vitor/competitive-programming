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
#define upper_right 4
#define upper_left 5
#define down_right 6
#define down_left 7
typedef struct {
  int x;
  int y;
} direction_t;

direction_t adjacents[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
direction_t diagonals[4] = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};

#define decode_dir(c)                                                          \
  (c == 'U' ? up : c == 'D' ? down : c == 'L' ? left : right)
bool is_valid_move(ll n) { return n >= 0 && n < 7; }

string p;
vector<vector<bool>> grid(9, vector<bool>(9));
ll counter = 0;
void make_all_paths(ll i = 1, ll j = 1, ll i_path = 0) {
  if (grid[i][j])
    return;

  if (i_path == 48 && i == 7 && j == 1) {
    counter++;
    return;
  }

  if (i == 7 && j == 1)
    return;

  vector<bool> visited(8, -1);
  for (auto pair : adjacents)
    if (is_valid_move(i + pair.x) && is_valid_move(j + pair.y))
      visited.push_back(grid[i + pair.x][j + pair.y]);

  for (auto pair : diagonals)
    if (is_valid_move(i + pair.x) && is_valid_move(j + pair.y))
      visited.push_back(grid[i + pair.x][j + pair.y]);

  if (!visited[down] && !visited[up] && visited[right] && visited[left])
    return;

  if (!visited[right] && !visited[left] && visited[down] && visited[up])
    return;

  if (visited[upper_right] && !visited[right] && !visited[up])
    return;

  if (visited[upper_left] && !visited[left] && !visited[up])
    return;

  if (visited[down_right] && !visited[right] && !visited[down])
    return;

  if (visited[down_left] && !visited[left] && !visited[down])
    return;

  grid[i][j] = true;

  if (p[i_path] != '?') {
    auto pair = adjacents[decode_dir(p[i_path])];
    make_all_paths(i + pair.x, j + pair.y, i_path + 1);
  } else {
    for (auto pair : adjacents)
      make_all_paths(i, decode_dir(p[i_path]));
  }

  grid[i][j] = false;
}

int main() {
  cin >> p;
  for (int i = 0; i < 9; i++) {
    grid[i][0] = true;
    grid[i][8] = true;
    grid[0][i] = true;
    grid[8][i] = true;
  }

  make_all_paths();
  cout << counter << endl;
  return 0;
}
