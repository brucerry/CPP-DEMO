#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <climits>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  vector<pair<int, int>> cocktails (n); // concentration, position

  for (int i = 0; i < n; i++) {
    int position, concentration;
    cin >> position >> concentration;
    cocktails[i] = { concentration, position };
  }

  sort(cocktails.begin(), cocktails.end());

  for (int i = 0; i < q; i++) {
    int judgePos, minConcentration;
    cin >> judgePos >> minConcentration;

    int start = distance(cocktails.begin(), lower_bound(cocktails.begin(), cocktails.end(), make_pair(minConcentration, INT_MIN)));
    if (start == cocktails.size()) {
      cout << -1;
    }
    else {
      int diff = INT_MAX, pos;
      for (int j = start; j < cocktails.size(); j++) {
        if (diff > abs(judgePos - cocktails[j].second)) {
          diff = abs(judgePos - cocktails[j].second);
          pos = cocktails[j].second;
        }
      }
      cout << pos;
    }
    cout << endl;
  }
}