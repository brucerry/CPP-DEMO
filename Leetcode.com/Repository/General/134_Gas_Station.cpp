// https://leetcode.com/problems/gas-station/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    
    int start = 0, remain = 0, prevRemain = 0;
    for (int i = 0; i < n; i++) {
      remain += gas[i] - cost[i];
      if (remain < 0) {
        prevRemain += remain;
        remain = 0;
        start = i + 1;
      }
    }
    
    return start == n or remain + prevRemain < 0 ? -1 : start; 
  }
};