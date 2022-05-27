// https://leetcode.com/problems/gas-station/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    
    int remainGas = 0, prevRemainGas = 0;
    int start = 0;
    for (int station = 0; station < n; station++) {
      remainGas += gas[station] - cost[station];
      if (remainGas < 0) {
        prevRemainGas += remainGas;
        remainGas = 0;
        start = station + 1;
      }
    }
    
    return start == n or remainGas + prevRemainGas < 0 ? -1 : start;
  }
};