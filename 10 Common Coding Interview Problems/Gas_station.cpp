/*
  time: O(n)
  space: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

int canTraverse(vector<int>& gas, vector<int>& cost) {
  int ans = 0;
  int remainGas = 0;
  int prevRemainGas = 0;

  for (int i = 0; i < gas.size(); i++) {
    remainGas += gas[i] - cost[i];
    if (remainGas < 0) {
      prevRemainGas += remainGas;
      remainGas = 0;
      ans = i + 1;
    }
  }

  return (ans == gas.size() || remainGas + prevRemainGas < 0) ? -1 : ans;
}

int main() {
  vector<int> gas {1, 5, 3, 3, 5, 3, 1, 3, 4, 5};
  vector<int> cost {5, 2, 2, 8, 2, 4, 2, 5, 1, 2};

  cout << canTraverse(gas, cost);
}