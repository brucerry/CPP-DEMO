#include <iostream>
#include <vector>
using namespace std;

struct Item {
  int score, mins;
};

int main() {
  int n, m;

  cin >> n >> m;

  vector<Item> items (n);

  for (int i = 0; i < n; i++) {
    cin >> items[i].score >> items[i].mins;
  }
  
  vector<int> dp (m + 1, 0);

  for (int i = 0; i < n; i++) {
    for (int j = m; j >= 0; j--) {
      if (j < items[i].mins)
        break;

      dp[j] = max(dp[j], dp[j - items[i].mins] + items[i].score);
    }
  }

  cout << dp[m];
}