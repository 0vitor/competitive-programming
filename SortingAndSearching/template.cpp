#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  while (true) {
    int N, K;
    cin >> N >> K;

    if (N == 0 && K == 0)
      break;

    vector<pair<int, int>> drivers(N);
    for (int i = 0; i < N; ++i) {
      cin >> drivers[i].first >> drivers[i].second;
    }

    priority_queue<int, vector<int>, greater<int>> parking;

    bool possible = true;
    for (int i = 0; i < N; ++i) {
      int arrival = drivers[i].first;
      int departure = drivers[i].second;

      while (!parking.empty() && parking.top() <= arrival) {
        parking.pop();
      }

      parking.push(departure);

      if ((int)parking.size() > K) {
        possible = false;
        break;
      }
    }

    cout << (possible ? "Sim" : "Nao") << '\n';
  }

  return 0;
}
