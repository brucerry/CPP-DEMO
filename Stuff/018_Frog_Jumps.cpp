#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t, n, w;

  cin >> t;

  while (t--) {
    cin >> n >> w;

    int maxJump = 0;
    vector<pair<char, int>> stones (n + 2);
    stones[0] = { 'b', 0 };
    stones.back() = { 'b', w };

    for (int i = 1; i < stones.size(); i++) {
      if (i <= n) {
        cin >> stones[i].first >> stones[i].second;
      }

      if (stones[i-1].first == 'b')
        maxJump = max(maxJump, stones[i].second - stones[i-1].second);
      else
        maxJump = max(maxJump, stones[i].second - stones[i-2].second);
    }

    cout << maxJump << endl;
  }
}