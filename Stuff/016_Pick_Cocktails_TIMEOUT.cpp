#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> cocktails (n);

  multiset<int> window;

  for (int i = 0; i < n; i++) {
    int score;
    cin >> score;
    cocktails[i] = score;

    window.insert(score);

    if (window.size() == m) {
      auto it = window.begin();
      advance(it, k - 1);
      if (i - m + 1 > 0) cout << ' ';
      cout << *it;
      window.erase(window.find(cocktails[i - m + 1]));
    }
  }
}