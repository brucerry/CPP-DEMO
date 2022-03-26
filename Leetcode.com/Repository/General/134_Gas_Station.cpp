// https://leetcode.com/problems/gas-station/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int len = gas.size();
    int sumOfGas = 0;
    int sumOfCost = 0;

    for (int i = 0; i < len; i++) {
      sumOfGas += gas[i];
      sumOfCost += cost[i];
    }

    if (sumOfGas < sumOfCost) return -1;
    
    int remainGas = 0;
    int pos = 0;
    for (int i = 0; i < len - 1; i++) {
      remainGas += gas[i] - cost[i];
      if (remainGas < 0) {
        remainGas = 0;
        pos = i + 1;
      }
    }
    return pos;
  }
};