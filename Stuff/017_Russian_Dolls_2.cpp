#include <iostream>
#include <set>
#include <array>
using namespace std;

int main() {
  int n, m;

  cin >> n;

  array<set<int>, 1000> ans;
  array<int, 100> numIndex { 0 };

  for (int i = 0; i < n; i++) {
    cin >> m;

    ans[numIndex[m]].emplace(m);
    numIndex[m]++;
  }

  for (int i = 0; i < n && ans[i].size(); i++) {
    for (const int& num : ans[i]) {
      cout << num << ' ';
    }
    cout << endl;
  }
}