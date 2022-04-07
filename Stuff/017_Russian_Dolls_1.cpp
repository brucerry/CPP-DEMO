#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

int main() {
  int n, m;

  cin >> n;

  vector<set<int>> ans (n);
  unordered_map<int, int> map; // num, latest index in ans

  for (int i = 0; i < n; i++) {
    cin >> m;

    if (map.count(m) == 0) {
      map[m] = 0;
      ans[0].emplace(m);
    }
    else {
      map[m]++;
      ans[map[m]].emplace(m);
    }
  }

  for (int i = 0; i < n && ans[i].size(); i++) {
    for (const int& num : ans[i]) {
      cout << num << ' ';
    }
    cout << endl;
  }
}