#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

int main() {
  int n, m;

  cin >> n;

  vector<set<int>> ans (n);
  unordered_map<int, int> places; // num, latest index in ans

  for (int i = 0; i < n; i++) {
    cin >> m;

    if (places.count(m) == 0) {
      places[m] = 0;
    }
    else {
      places[m]++;
    }
    ans[places[m]].emplace(m);
  }

  for (int i = 0; i < n && ans[i].size(); i++) {
    for (const int& num : ans[i]) {
      cout << num << ' ';
    }
    cout << endl;
  }
}