#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define _                                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);
#define dbg(x) cout << #x << " " << x << endl;

bool hasCollision(int **m, int r, int c) {
  int upi = r + 1;
  int downi = r - 1;
  for (int j = c; j < 8; j++) {
    int upCollision = upi >= 8 ? '.' : m[upi][j];
    int downCollision = downi < 0 ? '.' : m[downi][j];
    int columnCollision = m[r][j];
    if (upCollision != '.' || downCollision != '.' || columnCollision != '.') {
      return true;
    }
    upi++;
    downi--;
  }

  return false;
}

void generateQueensBoard(int **m, int i, int j) {
  if (i == 8 && j == 8) {
    hasCollision(m, i, j);
  }
  m[i][j] = 'Q';
  if (i == 8) {
    generateQueensBoard(m, i, j + 1);
  }
  if (j == 8) {
    generateQueensBoard(m, i + 1, j);
  }
}

int main() {
  int m[8][8];
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> m[i][j];
    }
  }

  generateQueensBoard(m);

  return 0;
}
