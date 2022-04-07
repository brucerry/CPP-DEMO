#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t, n, w;

  cin >> t;

  while (t--) {
    cin >> n >> w;

    int maxJump = 0;
    vector<pair<char, int>> stones (n + 1);
    stones[0] = { 'b', 0 };

    for (int i = 1; i <= n; i++) {
      char size;
      int pos;

      cin >> size >> pos;

      stones[i] = { size, pos };

      if (stones[i-1].first == 'b')
        maxJump = max(maxJump, pos - stones[i-1].second);
      else
        maxJump = max(maxJump, pos - stones[i-2].second);
    }

    if (stones.back().first == 'b')
      maxJump = max(maxJump, w - stones.back().second);
    else
      maxJump = max(maxJump, w - stones[n-1].second);

    cout << maxJump << endl;
  }
}