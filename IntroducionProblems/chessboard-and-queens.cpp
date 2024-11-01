#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define _                                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);
#define dbg(x) cout << #x << " " << x << endl;
#define forn(n, x)                                                             \
  cout << "[";                                                                 \
  for (auto i = 0; i < n - 1; i++) {                                           \
    cout << x[i] << ", ";                                                      \
  }                                                                            \
  cout << x[n - 1] << "]" << endl;

ll r = LINF;

bool hasCollision(vector<vector<char>> &board, ll i, ll j) {
  ll down_i = i, up_i = i;
  while (--j >= 0) {
    bool up_collision = --up_i >= 0 && board[up_i][j] == 'Q' ;
    bool down_collision = ++down_i < 8 && board[down_i][j] == 'Q'  ;
    bool row_collision = board[i][j] == 'Q';
    if (down_collision || up_collision || row_collision)
      return true;
  }
  return false;
}

void putQueens(vector<vector<char>> &board, ll j_row, ll *counter) {
  if (j_row == 8) {
    *counter += 1;
    return;
  }

  for (ll i = 0; i < 8; i++) {
    if (board[i][j_row] == '.' && !hasCollision(board, i, j_row)) {
      board[i][j_row] = 'Q';
      putQueens(board, j_row + 1, counter);
      board[i][j_row] = '.';
    }
  }
}

int main() {
  vector<vector<char>> board(8, vector<char>(8));
  ll counter = 0;
  for (ll i = 0; i < 8; i++) {
    for (ll j = 0; j < 8; j++) {
      cin >> board[i][j];
    }
  }
  putQueens(board, 0, &counter);
  cout << counter << endl;
  return 0;
}
