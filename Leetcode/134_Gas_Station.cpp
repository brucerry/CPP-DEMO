// https://leetcode.com/problems/gas-station/

#include <vector>
using namespace std;

class Solution {
public:
  // time: O(n)
  // space: O(1)
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int len = gas.size();
    int sumOfGas = 0;
    int sumOfCost = 0;
    for (int i = 0; i < len; i++) {
      sumOfGas += gas[i];
      sumOfCost += cost[i];
    }
    if (sumOfGas < sumOfCost) return -1;
    int totalDiff = 0;
    int pos = 0;
    for (int i = 0; i < len; i++) {
      totalDiff += gas[i] - cost[i];
      if (totalDiff < 0) {
        totalDiff = 0;
        pos = i + 1;
      }
    }
    return pos;
  }

  // time: O(n^2)
  // space: O(1)
  // int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
  //   int len = gas.size();
  //   for (int i = 0; i < len; i++) {
  //     int j = i;
  //     int tank = gas[j];
  //     while (tank >= cost[j]) {
  //       tank = tank - cost[j] + gas[(j + 1) % len];
  //       j = (j + 1) % len;
  //       if (j == i) return i;
  //     }
  //   }

  //   return -1;
  // }
};